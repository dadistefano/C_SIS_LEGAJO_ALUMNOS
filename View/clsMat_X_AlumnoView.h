#ifndef CLSMAT_X_ALUMNOVIEW_H
#define CLSMAT_X_ALUMNOVIEW_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "../DTO/clsMat_X_AlumnoDTO.h"
#include "../BL/clsMat_X_AlumnoBL.h"
#include "../Helpers/clsValidacion.h"

using namespace std;

class clsMat_X_AlumnoView
{
    public:
        void Menu();
        void Insertar();
        void Eliminar();
        void Listar();

};



#endif // CLSMAT_X_ALUMNOVIEW_H
