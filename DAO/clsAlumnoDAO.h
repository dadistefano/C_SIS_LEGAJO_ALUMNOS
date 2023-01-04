#ifndef CLSALUMNODAO_H
#define CLSALUMNODAO_H

#include <cstdio> //MANIPULACION DE ARCHIVO
#include "../DTO/clsAlumnoDTO.h"
#include "../Helpers/clsCadenas.h"

char const ARCHIVO_ALUMNO[]="ARCHIVO_ALUMNO.DAT";
class clsAlumnoDAO
{
	public:
		void Insertar(clsAlumnoDTO);
		bool Eliminar(int);
		bool Modificar(clsAlumnoDTO);
		void Listar(clsAlumnoDTO*);
		int Count();
        void BuscarSub(clsAlumnoDTO *,char*);
		int BuscarSubCount(char*);
};

#endif // CLSALUMNODAO_H
