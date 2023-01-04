#ifndef CLSALUMNODTO_H
#define CLSALUMNODTO_H
#include <cstring>

class clsAlumnoDTO
{
    public:
        clsAlumnoDTO();
        int GetLegajo() { return Legajo; }
        void SetLegajo(int val) { Legajo=val; }
        void GetNombre_Alumno (char *val) { strcpy(val, Nombre_Alumno); }
        void SetNombre_Alumno (char *val) { strcpy(Nombre_Alumno, val); }
        int GetDia_Nacimiento() { return Dia_Nacimiento; }
        void SetDia_Nacimiento(int val) { Dia_Nacimiento = val; }
        int GetMes_Nacimiento() { return Mes_Nacimiento; }
        void SetMes_Nacimiento(int val) { Mes_Nacimiento = val; }
        int GetAnio_Nacimiento() { return Anio_Nacimiento; }
        void SetAnio_Nacimiento(int val) { Anio_Nacimiento = val; }
        bool GetEliminado_Alum() { return Eliminado_Alum; }
        void SetEliminado_Alum(bool val) { Eliminado_Alum = val; }
        void Copy(clsAlumnoDTO); //entidad de mi mismo y se hace una copia


    private:
        int Legajo;
        char Nombre_Alumno[50];
        int Dia_Nacimiento;
        int Mes_Nacimiento;
        int Anio_Nacimiento;
        bool Eliminado_Alum;
};

#endif // CLSALUMNODTO_H
