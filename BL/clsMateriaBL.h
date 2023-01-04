#ifndef CLSMATERIABL_H
#define CLSMATERIABL_H
#include "../DTO/clsMateriaDTO.h"
#include "../DAO/clsMateriaDAO.h"

class clsMateriaBL
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

#endif // CLSMATERIABL_H
