#include "clsMat_X_AlumnoView.h"

void clsMat_X_AlumnoView::Menu()
{
    char op;
    bool salir=false;
    while(!salir)
    {
        system("cls");
        cout<<"---MENU----------------------------------------------------------"<<endl;
        cout<<" N) NUEVO MATERIA POR ALUMNO"<<endl;
        cout<<" L) LISTAR MATERIA POR ALUMNO"<<endl;
        cout<<" E) ELIMINAR MATERIA DEL ALUMNO"<<endl;
        cout<<" S) SALIR"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"Ingrese una opcion: "<<endl;
        cin>>op;
        cin.ignore();
        switch(op)
        {
            case 'N':
            case 'n':
                {
                    system("cls");
                    Insertar();
                }break;
            case 'L':
            case 'l':
                {
                    system("cls");
                    Listar();
                    system("pause");
                }break;
            case 'E':
            case 'e':
                {
                    Eliminar();
                    system("pause");
                }break;
            case 'S':
            case 's':
                {
                    salir=true;

                }break;
            default:
                {
                    cout<<"Opcion Incorrecta"<<endl;
                }break;

        }
    }
}

void clsMat_X_AlumnoView::Insertar() //hay quilombo aca
{
    int IdMateria;
    int LegAlumno;
    bool bleg_id,bid,bleg;
    clsMat_X_AlumnoDTO dto;
    clsMat_X_AlumnoBL bl;
    clsValidacion val;
    system("cls");
    cout<<"-----NUEVO MATERIA POR ALUMNO------------------------"<<endl;
    cout<<"Ingrese Legajo del Alumno: ";
    cin>>LegAlumno;
    cout<<"Ingrese el ID de la materia: ";
    cin>>IdMateria;
    bid=val.ExistenciaID(IdMateria);
    bleg=val.ExistenciaLeg(LegAlumno);
    bleg_id=val.VerificacionDobleIngreso(LegAlumno,IdMateria);


    if(bleg_id==true&&bid==true&&bleg==true)
    {
        dto.SetLegajo_MatxAlum(LegAlumno);
        dto.SetId_MatxAlum(IdMateria);
        bl.Insertar(dto);
        cout<<"SE GUARDO CORRECTAMENTE"<<endl;
        system("pause");
    }
    else
    {
        cout<<"VERIFICA EL LEGAJO O ID QUE SON INCORRECTOS"<<endl;
        system("pause");
    }


}
void clsMat_X_AlumnoView::Listar()
{
    clsMat_X_AlumnoBL bl;
    system("cls");
    cout<<" LISTADO DE MATERIA POR ALUMNO "<<endl;
    cout<<" "<<endl;

    int c=bl.Count();
    clsMat_X_AlumnoDTO* lista=(clsMat_X_AlumnoDTO*)malloc(sizeof(clsMat_X_AlumnoDTO)*c);
    bl.Listar(lista);
    cout<<"---------------------------------"<<endl;
    cout<<"|"<<setw(10)<<"LEGAJO"<<"|"<<setw(20)<<"ID MATERIA"<<"|"<<endl;
    cout<<"---------------------------------"<<endl;
    for(int x=0;x<c;x++)
    {

        cout<<"|"<<setw(10)<<lista[x].GetLegajo_MatxAlum()<<"|"<<setw(20)<<lista[x].GetId_MatxAlum()<<"|"<<endl;
        cout<<"---------------------------------"<<endl;
    }

}

void clsMat_X_AlumnoView::Eliminar()
{
    int Ideliminar;
    int legeliminar;
    bool Verificacion;
    clsMat_X_AlumnoDTO dto;
    clsMat_X_AlumnoBL bl;
    system("cls");
    cout<<"-----MATERIA POR LEGAJO A ELIMINAR------------------------"<<endl;
    cout<<"Ingrese el LEGAJO del Alumno: ";
    cin>>legeliminar;

    cout<<"Ingrese el ID de la materia por Alumno a Eliminar: ";
    cin>>Ideliminar;


    dto.SetLegajo_MatxAlum(legeliminar);
    dto.SetId_MatxAlum(Ideliminar);

    Verificacion=bl.Eliminar(legeliminar,Ideliminar);
    if(Verificacion==true)
    {
        cout<<"LA ELIMINACION DEL IDMATERIA "<<Ideliminar<<" DEL ALUMNO "<<legeliminar<<" SE REALIZO CORRECTAMENTE"<<endl;
    }
    else
    {
        cout<<"NO SE LOGRO REALIZAR LA ELIMINACION!!!, VERIFIQUE LOS DATOS INGRESADO"<<endl;
    }
}

