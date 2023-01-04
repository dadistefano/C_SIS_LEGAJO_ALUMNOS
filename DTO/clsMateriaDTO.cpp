#include "clsMateriaDTO.h"

clsMateriaDTO::clsMateriaDTO() //CONSTRUCTOR
{
    this->Eliminado=false;
}

void clsMateriaDTO::Copy(clsMateriaDTO dto)
{
    char nombre[50];
    char profesor[50];
    this->Id = dto.GetId();
    dto.GetNombre(nombre);
    strcpy(this->Nombre,nombre);

    dto.GetProfesor(profesor);
    strcpy(this->Profesor,profesor);
}
