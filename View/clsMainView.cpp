#include "clsMainView.h"

void clsMainView::Menu()
{
    int op;
    bool salir=false;
    while(!salir)
    {
        system("cls");
        cout<<"---MENU---------------------------------------------------"<<endl;
        cout<<" 1) MATERIA"<<endl;
        cout<<" 2) ALUMNOS"<<endl;
        cout<<" 3) MATERIA POR ALUMNO"<<endl;
        cout<<""<<endl;
        cout<<" 0) SALIR"<<endl;
        cout<<"----------------------------------------------------------"<<endl;
        cout<<"Ingrese una opcion: "<<endl;
        cin>>op;
        cin.ignore();
        switch(op)
        {
            case 1:
                {
                    system("cls");
                    clsMateriaView matView;
                    matView.Menu();
                }break;
            case 2:
                {
                    system("cls");
                    clsAlumnoView aluView;
                    aluView.Menu();
                }break;
            case 3:
                {
                    system("cls");
                    clsMat_X_AlumnoView mxaView;
                    mxaView.Menu();
                }break;
            case 0:
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
void clsMainView::Entrada()
{
      system("cls");
      cout<<"______________________________________________ TP NRO 02 INTEGRADOR _______"<<endl;
      cout<<""<<endl;
      cout<<" BIENVENIDOS "<<endl;
      cout<<""<<endl;
      cout<<" INTEGRANTE: DIEGO DI STEFANO"<<endl;

      cout<<" MATERIA: LABORATORIO 2"<<endl;
      cout<<" CARRERA: TSP"<<endl;
      cout<<""<<endl;
      cout<<""<<endl;
      cout<<""<<endl;
      cout<<""<<endl;
      cout<<""<<endl;
      cout<<"___________________________________________________________________________"<<endl;
      system("pause");
}

void clsMainView::Salida()
{
      system("cls");
      cout<<"______________________________________________ TP NRO 02 INTEGRADOR _______"<<endl;
      cout<<"  "<<endl;
      cout<<" GRACIAS POR INGRESAR, VUELVA PRONTO......... "<<endl;
      cout<<"  "<<endl;
      cout<<" INTEGRANTE: DIEGO DI STEFANO"<<endl;
      cout<<" MATERIA: LABORATORIO 2"<<endl;
      cout<<" CARRERA: TSP"<<endl;
      cout<<"   "<<endl;
      cout<<"   "<<endl;
      cout<<"   "<<endl;
      cout<<"   "<<endl;
      cout<<"   "<<endl;
      cout<<"___________________________________________________________________________"<<endl;
      system("pause");
}

