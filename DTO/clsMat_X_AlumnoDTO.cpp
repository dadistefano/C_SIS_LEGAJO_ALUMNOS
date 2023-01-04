#include "clsMat_X_AlumnoDTO.h"

clsMat_X_AlumnoDTO::clsMat_X_AlumnoDTO() //CONSTRUCTOR
{
    this->Eliminado_MatxAlum=false;
}

void clsMat_X_AlumnoDTO::Copy(clsMat_X_AlumnoDTO dto)
{
    this->Id_MatxAlum = dto.GetId_MatxAlum();
    this->Legajo_MatxAlum = dto.GetLegajo_MatxAlum();
    this->Eliminado_MatxAlum = dto.GetEliminado_MatxAlum();

}
