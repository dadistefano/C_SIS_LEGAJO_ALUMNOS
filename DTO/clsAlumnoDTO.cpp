#include "clsAlumnoDTO.h"

clsAlumnoDTO::clsAlumnoDTO() //CONSTRUCTOR
{
    this->Eliminado_Alum=false;
}

void clsAlumnoDTO::Copy(clsAlumnoDTO dto)
{
    char nombre_alumn[50];
    this->Legajo = dto.GetLegajo();
    dto.GetNombre_Alumno(nombre_alumn);
    strcpy(this->Nombre_Alumno,nombre_alumn);
    this->Dia_Nacimiento = dto.GetDia_Nacimiento();
    this->Mes_Nacimiento = dto.GetMes_Nacimiento();
    this->Anio_Nacimiento = dto.GetAnio_Nacimiento();

}
