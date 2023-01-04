#ifndef CLSMAT_X_ALUMNOBL_H
#define CLSMAT_X_ALUMNOBL_H

#include "../DTO/clsMat_X_AlumnoDTO.h"
#include "../DAO/clsMat_X_AlumnoDAO.h"

class clsMat_X_AlumnoBL
{
	public:
		void Insertar(clsMat_X_AlumnoDTO);
		bool Eliminar(int,int);
		void Listar(clsMat_X_AlumnoDTO *);
		int Count();
};


#endif // CLSMAT_X_ALUMNOBL_H
