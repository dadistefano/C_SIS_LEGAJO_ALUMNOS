#include "clsMateriaView.h"

void clsMateriaView::Menu()
{
    char op;
    bool salir=false;
    while(!salir)
    {
        system("cls");
        cout<<"---MENU----------------------------------------------------------"<<endl;
        cout<<" N) NUEVA MATERIA"<<endl;
        cout<<" L) LISTAR MATERIA"<<endl;
        cout<<" B) BUSQUEDA DE MATERIA POR NOMBRE"<<endl;
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
                    Insertar();
                    system("pause");
                }break;
            case 'L':
            case 'l':
                {
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

void clsMateriaView::Insertar()
{
    char nombre[50];
    char profesor[50];
    clsMateriaDTO dto;
    clsMateriaBL bl;
    clsValidacion val;
    system("cls");
    cout<<"-----NUEVA MATERIA------------------------"<<endl;
    val.ValidarRequeridoTexto("Ingrese el nombre de la materia: ",nombre,50);
    val.ValidarRequeridoTexto("Ingrese el nombre del profesor: ",profesor,50);

    dto.SetNombre(nombre);
    dto.SetProfesor(profesor);
    bl.Insertar(dto);
}
void clsMateriaView::Listar()
{
    clsMateriaBL bl;
    system("cls");
    cout<<" LISTADO DE MATERIAS "<<endl;
    cout<<""<<endl;
    int c=bl.Count();
    clsMateriaDTO* lista=(clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*c);
    bl.Listar(lista);
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"|"<<setw(10)<<"ID MATERIA"<<"|"<<setw(20)<<"MATERIA"<<"|"<<setw(30)<<"PROFESOR"<<"|"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    char nombre[50];
    char profesor[50];
    for(int x=0;x<c;x++)
    {
        lista[x].GetNombre(nombre);
        lista[x].GetProfesor(profesor);
        cout<<"|"<<setw(10)<<lista[x].GetId()<<"|"<<setw(20)<<nombre<<"|"<<setw(30)<<profesor<<"|"<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
    }

}
void clsMateriaView::ListarBusqueda()
{
    clsMateriaBL bl;
    char condicion[50];
    system("cls");
    cout<<"- LISTADO DE MATERIAS POR BUSQUEDA DE NOMBRE ----------------------------"<<endl;
    cout<<"Ingrese la materia a buscar: ";
    cin.getline(condicion,50);
    int c=bl.BuscarSubCount(condicion);
    clsMateriaDTO* lista=(clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*c);
    bl.BuscarSub(lista,condicion);

    char nombre[50];
    char profesor[50];
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"|"<<setw(10)<<"ID MATERIA"<<"|"<<setw(20)<<"MATERIA"<<"|"<<setw(30)<<"PROFESOR"<<"|"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    for(int x=0;x<c;x++)
    {
        lista[x].GetNombre(nombre);
        lista[x].GetProfesor(profesor);
        cout<<"|"<<setw(10)<<lista[x].GetId()<<"|"<<setw(20)<<nombre<<"|"<<setw(30)<<profesor<<"|"<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
    }
}

void clsMateriaView::Modificar()
{
    int Idmodificar;
    char nombre[50];
    char profesor[50];
    bool Verificacion;
    clsMateriaDTO dto;
    clsMateriaBL bl;
    clsValidacion val;
    system("cls");
    cout<<"-----MATERIA A MODIFICAR------------------------"<<endl;
    cout<<"Ingrese el ID de la materia a modificar: ";
    cin>>Idmodificar;
    val.ValidarRequeridoTexto("Ingrese el nombre de la materia: ",nombre,50);
    val.ValidarRequeridoTexto("Ingrese el nombre del profesor: ",profesor,50);

    dto.SetId(Idmodificar);
    dto.SetNombre(nombre);
    dto.SetProfesor(profesor);
    Verificacion=bl.Modificar(dto);
    if(Verificacion==true)
    {
        cout<<"LA MODIFICACION DEL ID "<<Idmodificar<<" SE REALIZO CORRECTAMENTE"<<endl;
    }
    else
    {
        cout<<"NO SE LOGRO REALIZAR LA MODIFICACION!!!, VERIFIQUE LOS DATOS INGRESADO"<<endl;
    }
}

void clsMateriaView::Eliminar()
{
    int Idmodificar;
    bool Verificacion;
    clsMateriaDTO dto;
    clsMateriaBL bl;
    system("cls");
    cout<<"-----MATERIA A ELIMINAR------------------------"<<endl;
    cout<<"Ingrese el ID de la materia a Eliminar: ";
    cin>>Idmodificar;


    dto.SetId(Idmodificar);
    Verificacion=bl.Eliminar(Idmodificar);
    if(Verificacion==true)
    {
        cout<<"LA ELIMINACION DEL IDMATERIA "<<Idmodificar<<" SE REALIZO CORRECTAMENTE"<<endl;
    }
    else
    {
        cout<<"NO SE LOGRO REALIZAR LA ELIMINACION DE LA MATERIA!!!, VERIFIQUE LOS DATOS INGRESADO"<<endl;
    }
}




