#include "clsAlumnoBL.h"


void clsAlumnoBL::Insertar(clsAlumnoDTO dto)
{
    clsAlumnoDAO dao;
    int legajo=dao.Count()+1;
    dto.SetLegajo(legajo);
    dto.SetEliminado_Alum(false);
    dao.Insertar(dto);
}
bool clsAlumnoBL::Eliminar(int legajo)
{
    clsAlumnoDAO dao;
    dao.Eliminar(legajo);
}
bool clsAlumnoBL::Modificar(clsAlumnoDTO dto)
{
    clsAlumnoDAO dao;
    dao.Modificar(dto);
}
void clsAlumnoBL::Listar(clsAlumnoDTO *lista)
{
    clsAlumnoDAO dao;
    dao.Listar(lista);
}
int clsAlumnoBL::Count()
{
    clsAlumnoDAO dao;
    return dao.Count();
}
void clsAlumnoBL::BuscarSub(clsAlumnoDTO *lista,char *cond)
{
    clsAlumnoDAO dao;
    dao.BuscarSub(lista,cond);
}
int clsAlumnoBL::BuscarSubCount(char *cond)
{
    clsAlumnoDAO dao;
    return dao.BuscarSubCount(cond);
}
