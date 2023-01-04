#ifndef CLSVALIDACION_H
#define CLSVALIDACION_H
#include <iostream>
#include <cstdio>
#include "../DTO/clsAlumnoDTO.h"
#include "../DTO/clsMateriaDTO.h"
#include "../DAO/clsMateriaDAO.h"
#include "../DAO/clsAlumnoDAO.h"
#include "../DTO/clsMat_X_AlumnoDTO.h"
#include "../DAO/clsMat_X_AlumnoDAO.h"

using namespace std;


class clsValidacion
{
    public:

        void ValidarRequeridoTexto(char*,char*,int);
        int Validardia(char*,int);
        int Validarmes(char*,int);
        int Validaranio(char*,int);
        bool ExistenciaLeg(int);
        bool ExistenciaID(int);
        bool VerificacionDobleIngreso(int, int);


};

#endif // CLSVALIDACION_H
