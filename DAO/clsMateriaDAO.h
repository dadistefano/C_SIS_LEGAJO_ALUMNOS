#ifndef CLSMATERIADAO_H
#define CLSMATERIADAO_H

#include <cstdio> //MANIPULACION DE ARCHIVO
#include "../DTO/clsMateriaDTO.h"
#include "../Helpers/clsCadenas.h"

char const ARCHIVO_MATERIA[]="ARCHIVO_MATERIA.DAT";
class clsMateriaDAO
{
	public:
		void Insertar(clsMateriaDTO);
		bool Eliminar(int);
		bool Modificar(clsMateriaDTO);
		void Listar(clsMateriaDTO *);
		int Count();
        void BuscarSub(clsMateriaDTO *,char*);
		int BuscarSubCount(char*);
};


#endif // CLSMATERIADAO_H
