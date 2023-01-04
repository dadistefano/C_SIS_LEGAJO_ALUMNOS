#include "clsAlumnoView.h"

void clsAlumnoView::Menu()
{
    char op;
    bool salir=false;
    while(!salir)
    {
        system("cls");
        cout<<"---MENU----------------------------------------------------------"<<endl;
        cout<<" N) NUEVO ALUMNO"<<endl;
        cout<<" L) LISTAR ALUMNO"<<endl;
        cout<<" B) BUSQUEDA POR ALUMNO DE NOMBRE"<<endl;
        cout<<" M) MODIFICAR MATERIA"<<endl;
        cout<<" E) ELIMINAR MATERIA"<<endl;
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
            case 'B':
            case 'b':
                {
                    ListarBusqueda();
                    system("pause");
                }break;
            case 'M':
            case 'm':
                {
                    Modificar();
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

void clsAlumnoView::Insertar()
{
    char nombre_alum[50];
    int dia_nacimiento,dia;
    int mes_nacimiento,mes;
    int anio_nacimiento,anio;
    clsAlumnoDTO dto;
    clsAlumnoBL bl;
    clsValidacion val;
    system("cls");
    cout<<"-----NUEVO ALUMNO------------------------"<<endl;
    val.ValidarRequeridoTexto("Ingrese el nombre del Alumno: ",nombre_alum,50);
    dia=val.Validardia("Ingrese DIA de Nacimiento: ",dia_nacimiento);
    mes=val.Validarmes("Ingrese MES de Nacimiento: ",mes_nacimiento);
    anio=val.Validaranio("Ingrese ANIO de Nacimiento: ",anio_nacimiento);

    dto.SetNombre_Alumno(nombre_alum);
    dto.SetDia_Nacimiento(dia);
    dto.SetMes_Nacimiento(mes);
    dto.SetAnio_Nacimiento(anio);
    bl.Insertar(dto);
}
void clsAlumnoView::Listar()
{
    clsAlumnoBL bl;
    system("cls");
    cout<<" LISTADO DE ALUMNOS "<<endl;
    cout<<" "<<endl;
    int c=bl.Count();
    clsAlumnoDTO* lista=(clsAlumnoDTO*)malloc(sizeof(clsAlumnoDTO)*c);
    bl.Listar(lista);
    char nombre_alum[50];
    cout<<"------------------------------------------------------"<<endl;
    cout<<"|"<<setw(10)<<"LEGAJO"<<"|"<<setw(20)<<"NOMBRE"<<"|"<<setw(5)<<"FECHA DE NACIMIENTO "<<"|"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    for(int x=0;x<c;x++)
    {
        lista[x].GetNombre_Alumno(nombre_alum);
        //lista[x].GetDia_Nacimiento(dia_nacimiento);
        //lista[x].GetMes_Nacimiento(mes_nacimiento);
        //lista[x].GetAnio_Nacimiento(anio_nacimiento);
        cout<<"|"<<setw(10)<<lista[x].GetLegajo()<<"|"<<setw(20)<<nombre_alum<<"|"<<setw(11)<<lista[x].GetDia_Nacimiento()<<"-"<<setw(2)<<lista[x].GetMes_Nacimiento()<<"-"<<setw(2)<<lista[x].GetAnio_Nacimiento()<<setw(2)<<"|"<<endl;
        cout<<"------------------------------------------------------"<<endl;
    }

}
void clsAlumnoView::ListarBusqueda()
{
    clsAlumnoBL bl;
    char condicion[50];
    system("cls");
    cout<<"- LISTADO DE ALUMNO POR BUSQUEDA DE NOMBRE "<<endl;
    cout<<""<<endl;
    cout<<"Ingrese NOMBRE del Alumno a buscar: ";
    cin.getline(condicion,50);
    int c=bl.BuscarSubCount(condicion);
    clsAlumnoDTO* lista=(clsAlumnoDTO*)malloc(sizeof(clsAlumnoDTO)*c);
    bl.BuscarSub(lista,condicion);
    cout<<"------------------------------------------------------"<<endl;
    cout<<"|"<<setw(10)<<"LEGAJO"<<"|"<<setw(20)<<"NOMBRE"<<"|"<<setw(5)<<"FECHA DE NACIMIENTO "<<"|"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    char nombre_alum[50];
    for(int x=0;x<c;x++)
    {
        lista[x].GetNombre_Alumno(nombre_alum);
        cout<<"|"<<setw(10)<<lista[x].GetLegajo()<<"|"<<setw(20)<<nombre_alum<<"|"<<setw(11)<<lista[x].GetDia_Nacimiento()<<"-"<<setw(2)<<lista[x].GetMes_Nacimiento()<<"-"<<setw(2)<<lista[x].GetAnio_Nacimiento()<<setw(2)<<"|"<<endl;
        cout<<"------------------------------------------------------"<<endl;
    }
}
void clsAlumnoView::Modificar()
{
    int Legmodificar;
    char nombreAlum[50];
    int dia_Nac;
    int Mes_Nac;
    int Anio_Nac;
    bool Verificacion;
    clsAlumnoDTO dto;
    clsAlumnoBL bl;
    clsValidacion val;
    system("cls");
    cout<<"-----MATERIA A MODIFICAR------------------------"<<endl;
    cout<<"Ingrese el Legajo del Alumno a modificar: ";
    cin>>Legmodificar;
    val.ValidarRequeridoTexto("Ingrese el nombre del Alumno: ",nombreAlum,50);
    cout<<"Ingrese DIA de Nacimiento: ";
    cin>>dia_Nac;
    cout<<"Ingrese MES de Nacimiento: ";
    cin>>Mes_Nac;
    cout<<"Ingrese ANIO de Nacimiento: ";
    cin>>Anio_Nac;

    dto.SetLegajo(Legmodificar);
    dto.SetNombre_Alumno(nombreAlum);
    dto.SetDia_Nacimiento(dia_Nac);
    dto.SetMes_Nacimiento(Mes_Nac);
    dto.SetAnio_Nacimiento(Anio_Nac);
    bl.Modificar(dto);
    Verificacion=bl.Modificar(dto);
    if(Verificacion==true)
    {
        cout<<"LA MODIFICACION DEL LEGADO "<<Legmodificar<<" SE REALIZO CORRECTAMENTE"<<endl;
    }
    else
    {
        cout<<"NO SE LOGRO REALIZAR LA MODIFICACION!!!, VERIFIQUE LOS DATOS INGRESADO"<<endl;
    }
}
void clsAlumnoView::Eliminar()
{
    int Legmodificar;
    bool Verificacion;
    clsAlumnoDTO dto;
    clsAlumnoBL bl;
    system("cls");
    cout<<"-----MATERIA A ELIMINAR------------------------"<<endl;
    cout<<"Ingrese el LEGAJO del Alumno a Eliminar: ";
    cin>>Legmodificar;


    dto.SetLegajo(Legmodificar);
    Verificacion=bl.Eliminar(Legmodificar);
    if(Verificacion==true)
    {
        cout<<"LA ELIMINACION DEL LEGAJO "<<Legmodificar<<" SE REALIZO CORRECTAMENTE"<<endl;
    }
    else
    {
        cout<<"NO SE LOGRO REALIZAR LA ELIMINACION DEL ALUMNO!!, VERIFIQUE LOS DATOS INGRESADO"<<endl;
    }
}

