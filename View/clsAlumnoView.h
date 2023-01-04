#ifndef CLSALUMNOVIEW_H
#define CLSALUMNOVIEW_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "../DTO/clsAlumnoDTO.h"
#include "../BL/clsAlumnoBL.h"
#include "../Helpers/clsValidacion.h"


using namespace std;

class clsAlumnoView
{
    public:
        void Menu();
        void Insertar();
        void Eliminar();
        void Modificar();
        void Listar();
        void ListarBusqueda();

};


#endif // CLSALUMNOVIEW_H
