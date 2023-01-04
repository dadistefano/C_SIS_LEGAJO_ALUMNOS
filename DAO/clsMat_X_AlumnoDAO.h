#ifndef CLSMAT_X_ALUMNODAO_H
#define CLSMAT_X_ALUMNODAO_H

#include <cstdio> //MANIPULACION DE ARCHIVO
#include "../DTO/clsMat_X_AlumnoDTO.h"

char const ARCHIVO_MATXALUM[]="ARCHIVO_MATXALUM.DAT";
class clsMat_X_AlumnoDAO
{
	public:
		void Insertar(clsMat_X_AlumnoDTO);
		bool Eliminar(int,int);
		//bool Modificar(clsMat_X_AlumnoDTO);
		void Listar(clsMat_X_AlumnoDTO*);
		int Count();
};

#endif // CLSMAT_X_ALUMNODAO_H
