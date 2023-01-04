#include "clsMat_X_AlumnoDAO.h"



void clsMat_X_AlumnoDAO::Insertar(clsMat_X_AlumnoDTO dto)
{
	FILE *p;
	p=fopen(ARCHIVO_MATXALUM,"ab");
    if (p!=NULL)
    {
        fwrite(&dto, sizeof(clsMat_X_AlumnoDTO),1,p);
        fclose(p);
    }
}

bool clsMat_X_AlumnoDAO::Eliminar(int legajo, int id)
{
    FILE *p;
    clsMat_X_AlumnoDTO dto;
    bool resultado=false;
    int pos=0;
    p=fopen(ARCHIVO_MATXALUM,"rb+");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsMat_X_AlumnoDTO),1,p))
        {
            if(dto.GetLegajo_MatxAlum()==legajo && dto.GetId_MatxAlum()==id && !dto.GetEliminado_MatxAlum())
            {
                dto.SetEliminado_MatxAlum(true);
                fseek(p,sizeof(clsMat_X_AlumnoDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsMat_X_AlumnoDTO),1,p);
                resultado=true;
                break;
            }
            pos++;
        }
    }
	fclose(p);
	return resultado;
}

/*bool clsMat_X_AlumnoDAO::Modificar(clsMat_X_AlumnoDTO dto)
{
    FILE *p;
    clsMat_X_AlumnoDTO dto_arch;
    bool resultado=false;
    int pos=0;
    p=fopen(ARCHIVO_MATXALUM, "rb+");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsMat_X_AlumnoDTO),1,p))
        {
            if(dto_arch.GetLegajo_MatxAlum()==dto.GetLegajo_MatxAlum() && dto_arch.GetId_MatxAlum()==dto.GetId_MatxAlum() && !dto_arch.GetEliminado_MatxAlum())
            {
                fseek(p,sizeof(clsMat_X_AlumnoDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsMat_X_AlumnoDTO),1,p);
                resultado=true;
                break;
            }
            pos++;
        }
	fclose(p);
    }
    return resultado;
}*/


void clsMat_X_AlumnoDAO::Listar(clsMat_X_AlumnoDTO *dto)
{
    FILE *p;
    clsMat_X_AlumnoDTO dto_arch;
    int pos=0;
    p=fopen(ARCHIVO_MATXALUM, "rb");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsMat_X_AlumnoDTO),1,p))
        {
            if(!dto_arch.GetEliminado_MatxAlum())
            {
                dto[pos].Copy(dto_arch);
                pos++;
            }
        }
        fclose(p);
    }
}


int clsMat_X_AlumnoDAO::Count()
{
    FILE *p;
    clsMat_X_AlumnoDTO dto;
    int cant=0;
    p=fopen(ARCHIVO_MATXALUM, "rb");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsMat_X_AlumnoDTO),1,p))
        {
            if(!dto.GetEliminado_MatxAlum())
            {
                cant++;
            }
        }
        fclose(p);
    }
    return cant;
}
