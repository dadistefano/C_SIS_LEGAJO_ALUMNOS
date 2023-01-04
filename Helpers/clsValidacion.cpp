#include "clsValidacion.h"

void clsValidacion::ValidarRequeridoTexto(char* texto,char* out,int tam)
{
    bool reintentar;

    do
    {
        int i=0;
        reintentar=true;
        cout<<texto;
        cin.getline(out,tam);
        while(out[i]!='\0')
        {
            if((out[i]>='a'&& out[i]<='z')||(out[i]>='A'&& out[i]<='Z'))
            {
                reintentar=false;
            }
            i++;
        }
    }while(reintentar);
}

int clsValidacion::Validardia(char* texto,int out)
{
    bool reintentar;

    do
    {
        int i=0;
        reintentar=true;
        cout<<texto;
        cin>>out;
            if(out>0 && out<=31)
            {
                reintentar=false;
            }
            i++;

    }while(reintentar);
    return out;
}

int clsValidacion::Validarmes(char* texto,int out)
{
    bool reintentar;

    do
    {
        int i=0;
        reintentar=true;
        cout<<texto;
        cin>>out;
            if(out>0 && out<=12)
            {
                reintentar=false;
            }
            i++;

    }while(reintentar);
    return out;
}

int clsValidacion::Validaranio(char* texto,int out)
{
    bool reintentar;

    do
    {
        int i=0;
        reintentar=true;
        cout<<texto;
        cin>>out;
            if(out>1800 && out<=2500)
            {
                reintentar=false;
            }
            i++;

    }while(reintentar);
    return out;
}


bool clsValidacion::ExistenciaLeg(int legajo)
{
    FILE *p;
    clsAlumnoDTO dto;
    bool resultado=false;
    int pos=0;
    p=fopen(ARCHIVO_ALUMNO, "rb");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsAlumnoDTO),1,p))
        {
            if(dto.GetLegajo()==legajo && !dto.GetEliminado_Alum())
            {
                resultado=true;
                break;
            }
            pos++;
        }
    }
	fclose(p);
	return resultado;
}

bool clsValidacion::ExistenciaID(int id)
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
                resultado=true;
                break;
            }
            pos++;
        }
    }
	fclose(p);
    return resultado;
}

bool clsValidacion::VerificacionDobleIngreso(int legajo, int id) //Si devuelte TRUE es que no hay duplicado!!!
{
    FILE *p;
    clsMat_X_AlumnoDTO dto;
    bool resultado=true;
    int pos=0;
    p=fopen(ARCHIVO_MATXALUM,"rb+");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsMat_X_AlumnoDTO),1,p))
        {
            if(dto.GetLegajo_MatxAlum()==legajo && dto.GetId_MatxAlum()==id && !dto.GetEliminado_MatxAlum())
            {
                resultado=false;
                break;
            }
            pos++;
        }
    }
	fclose(p);
	return resultado;
}

