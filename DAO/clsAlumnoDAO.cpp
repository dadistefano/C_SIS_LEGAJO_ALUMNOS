#include "clsAlumnoDAO.h"


void clsAlumnoDAO::Insertar(clsAlumnoDTO dto)
{
	FILE *p;
	p=fopen(ARCHIVO_ALUMNO, "ab");
    if (p!=NULL)
    {
        fwrite(&dto, sizeof(clsAlumnoDTO),1,p);
        fclose(p);
    }
}

bool clsAlumnoDAO::Eliminar(int legajo)
{
    FILE *p;
    clsAlumnoDTO dto;
    bool resultado=false;
    int pos=0;
    p=fopen(ARCHIVO_ALUMNO, "rb+");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsAlumnoDTO),1,p))
        {
            if(dto.GetLegajo()==legajo && !dto.GetEliminado_Alum())
            {
                dto.SetEliminado_Alum(true);
                fseek(p,sizeof(clsAlumnoDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsAlumnoDTO),1,p);
                resultado=true;
                break;
            }
            pos++;
        }
    }
	fclose(p);
	return resultado;
}

bool clsAlumnoDAO::Modificar(clsAlumnoDTO dto)
{
    FILE *p;
    clsAlumnoDTO dto_arch;
    bool resultado=false;
    int pos=0;
    p=fopen(ARCHIVO_ALUMNO, "rb+");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsAlumnoDTO),1,p))
        {
            if(dto_arch.GetLegajo()==dto.GetLegajo() && !dto_arch.GetEliminado_Alum())
            {
                fseek(p,sizeof(clsAlumnoDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsAlumnoDTO),1,p);
                resultado=true;
                break;
            }
            pos++;
        }
	fclose(p);
    }
    return resultado;
}


void clsAlumnoDAO::Listar(clsAlumnoDTO *dto)
{
    FILE *p;
    clsAlumnoDTO dto_arch;
    int pos=0;
    p=fopen(ARCHIVO_ALUMNO, "rb");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsAlumnoDTO),1,p))
        {
            if(!dto_arch.GetEliminado_Alum())
            {
                dto[pos].Copy(dto_arch);
                pos++;
            }
        }
        fclose(p);
    }
}


int clsAlumnoDAO::Count()
{
    FILE *p;
    clsAlumnoDTO dto;
    int cant=0;
    p=fopen(ARCHIVO_ALUMNO, "rb");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsAlumnoDTO),1,p))
        {
            if(!dto.GetEliminado_Alum())
            {
                cant++;
            }
        }
        fclose(p);
    }
    return cant;
}

void clsAlumnoDAO::BuscarSub(clsAlumnoDTO *dto,char *cond)
{
    FILE *p;
    clsAlumnoDTO dto_arch;
    clsCadenas cadenas;
    int pos=0;
    char nombreAlum[50];
    p=fopen(ARCHIVO_ALUMNO, "rb");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsAlumnoDTO),1,p))
        {
            dto_arch.GetNombre_Alumno(nombreAlum);
            if(!dto_arch.GetEliminado_Alum()&& cadenas.strSub(nombreAlum,cond)>=0)
            {
                dto[pos].Copy(dto_arch);
                pos++;
            }
        }
        fclose(p);
    }
}


int clsAlumnoDAO::BuscarSubCount(char *cond)
{
    FILE *p;
    int cant=0;
    char nombreAlum[50];
    clsAlumnoDTO dto;
    clsCadenas cadenas;

    p=fopen(ARCHIVO_ALUMNO, "rb");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsAlumnoDTO),1,p))
        {
            dto.GetNombre_Alumno(nombreAlum);
            if(!dto.GetEliminado_Alum()&& cadenas.strSub(nombreAlum,cond)>=0)
            {
                cant++;
            }
        }
        fclose(p);
    }
    return cant;
}
