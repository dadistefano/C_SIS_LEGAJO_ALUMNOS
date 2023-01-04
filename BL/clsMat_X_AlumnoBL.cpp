#include "clsMat_X_AlumnoBL.h"


void clsMat_X_AlumnoBL::Insertar(clsMat_X_AlumnoDTO dto)
{
    clsMat_X_AlumnoDAO dao;
    dto.SetEliminado_MatxAlum(false);
    dao.Insertar(dto);
}
bool clsMat_X_AlumnoBL::Eliminar(int legajo, int id)
{
    clsMat_X_AlumnoDAO dao;
    dao.Eliminar(legajo,id);
}

void clsMat_X_AlumnoBL::Listar(clsMat_X_AlumnoDTO *lista)
{
    clsMat_X_AlumnoDAO dao;
    dao.Listar(lista);
}
int clsMat_X_AlumnoBL::Count()
{
    clsMat_X_AlumnoDAO dao;
    return dao.Count();
}
