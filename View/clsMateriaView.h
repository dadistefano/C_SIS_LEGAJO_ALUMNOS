#ifndef CLSMATERIAVIEW_H
#define CLSMATERIAVIEW_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "../DTO/clsMateriaDTO.h"
#include "../BL/clsMateriaBL.h"
#include "../Helpers/clsValidacion.h"


using namespace std;

class clsMateriaView
{
    public:
        void Menu();
        void Insertar();
        void Eliminar();
        void Modificar();
        void Listar();
        void ListarBusqueda();
        //void Modificar();

};

#endif // CLSMATERIAVIEW_H
