#include "clsMateriaDAO.h"


void clsMateriaDAO::Insertar(clsMateriaDTO dto)
{
	FILE *p;
	p=fopen(ARCHIVO_MATERIA, "ab");
    if (p!=NULL)
    {
        fwrite(&dto, sizeof(clsMateriaDTO),1,p);
        fclose(p);
    }
}

bool clsMateriaDAO::Eliminar(int id)
{
    FILE *p;
    clsMateriaDTO dto;
    bool resultado=false;
    int pos=0;
    p=fopen(ARCHIVO_MATERIA, "rb+");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
        {
            if(dto.GetId()==id && !dto.GetEliminado())
            {
                dto.SetEliminado(true);
                fseek(p,sizeof(clsMateriaDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsMateriaDTO),1,p);
                resultado=true;
                break;
            }
            pos++;
        }
    }
	fclose(p);
    return resultado;
}

bool clsMateriaDAO::Modificar(clsMateriaDTO dto)
{
    FILE *p;
    clsMateriaDTO dto_arch;
    bool resultado=false;
    int pos=0;
    p=fopen(ARCHIVO_MATERIA, "rb+");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsMateriaDTO),1,p))
        {
            if(dto_arch.GetId()==dto.GetId() && !dto_arch.GetEliminado())
            {
                fseek(p,sizeof(clsMateriaDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsMateriaDTO),1,p);
                resultado=true;
                break;
            }
            pos++;
        }
	fclose(p);
    }
    return resultado;
}


void clsMateriaDAO::Listar(clsMateriaDTO *dto)
{
    FILE *p;
    clsMateriaDTO dto_arch;
    int pos=0;
    p=fopen(ARCHIVO_MATERIA, "rb");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsMateriaDTO),1,p))
        {
            if(!dto_arch.GetEliminado())
            {
                dto[pos].Copy(dto_arch);
                pos++;
            }
        }
        fclose(p);
    }
}


int clsMateriaDAO::Count()
{
    FILE *p;
    clsMateriaDTO dto;
    int cant=0;
    p=fopen(ARCHIVO_MATERIA, "rb");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
        {
            if(!dto.GetEliminado())
            {
                cant++;
            }
        }
        fclose(p);
    }
    return cant;
}



void clsMateriaDAO::BuscarSub(clsMateriaDTO *dto,char *cond)
{
    FILE *p;
    clsMateriaDTO dto_arch;
    clsCadenas cadenas;
    int pos=0;
    char nombre[50];
    p=fopen(ARCHIVO_MATERIA, "rb");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsMateriaDTO),1,p))
        {
            dto_arch.GetNombre(nombre);
            if(!dto_arch.GetEliminado()&& cadenas.strSub(nombre,cond)>=0)
            {
                dto[pos].Copy(dto_arch);
                pos++;
            }
        }
        fclose(p);
    }
}


int clsMateriaDAO::BuscarSubCount(char *cond)
{
    FILE *p;
    int cant=0;
    char nombre[50];
    clsMateriaDTO dto;
    clsCadenas cadenas;

    p=fopen(ARCHIVO_MATERIA, "rb");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
        {
            dto.GetNombre(nombre);
            if(!dto.GetEliminado()&& cadenas.strSub(nombre,cond)>=0)
            {
                cant++;
            }
        }
        fclose(p);
    }
    return cant;
}
