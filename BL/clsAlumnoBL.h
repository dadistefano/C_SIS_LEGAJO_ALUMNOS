#ifndef CLSALUMNOBL_H
#define CLSALUMNOBL_H

#include "../DTO/clsAlumnoDTO.h"
#include "../DAO/clsAlumnoDAO.h"

class clsAlumnoBL
{
	public:
		void Insertar(clsAlumnoDTO);
		bool Eliminar(int);
		bool Modificar(clsAlumnoDTO);
		void Listar(clsAlumnoDTO *);
		int Count();
        void BuscarSub(clsAlumnoDTO *,char*);
		int BuscarSubCount(char*);
};
#endif // CLSALUMNOBL_H
