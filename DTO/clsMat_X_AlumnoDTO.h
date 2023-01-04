#ifndef CLSMAT_X_ALUMNODTO_H
#define CLSMAT_X_ALUMNODTO_H
#include <cstring>

class clsMat_X_AlumnoDTO
{
    public:
        clsMat_X_AlumnoDTO();
        int GetId_MatxAlum() { return Id_MatxAlum; }
        void SetId_MatxAlum(int val) { Id_MatxAlum = val; }
        int GetLegajo_MatxAlum() { return Legajo_MatxAlum; }
        void SetLegajo_MatxAlum(int val) { Legajo_MatxAlum = val; }
        bool GetEliminado_MatxAlum() { return Eliminado_MatxAlum; }
        void SetEliminado_MatxAlum(bool val) { Eliminado_MatxAlum = val; }
        void Copy(clsMat_X_AlumnoDTO); //entidad de mi mismo y se hace una copia


    private:
        int Id_MatxAlum;
        int Legajo_MatxAlum;
        bool Eliminado_MatxAlum;
};

#endif // CLSMAT_X_ALUMNODTO_H
