#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

void obtenerNombre      (char *nombre, int p);
void mostrarResultado   (int lanzaDados[], int tam);
void guardarNHS         (char *nombre,int p);
int menu                ();

#endif // UTILIDADES_H_INCLUDED

void obtenerNombre(char nombre[3][10],int p){
    cout<<"Ingrese su nombre"<<endl;
    lineasHorizontales(1,2,17,2,3);
    rlutil::locate(1,3);
    colorTexto(8);
    cin>>nombre[p];
    colorTexto(1);
}

void guardarNPM (char nombre[3][10],int p){               //Guarda el nombre del jugador con la mayor
    for (int i=0;i<10;i++){
        nombre[2][i]=nombre[p][i];
    }
}

int menu() {
     int seleccionMenu=0;
    while (seleccionMenu>4 || seleccionMenu<1){
        system("cls");
        lineasHorizontales(1,1,45,6,1);
        rlutil::locate(1,2);
        cout << "Seleccione alguna de las siguientes opciones:" << endl;
        cout << "1 > Modo un jugador" << endl;
        cout << "2 > Modo dos jugadores" << endl;
        cout << "3 > Puntuacion mas alta" << endl;
        cout << "4 > Finalizar" << endl;
        rlutil::locate(1,8);
        cout << "> ";
        cin >> seleccionMenu;

        if (seleccionMenu>4 || seleccionMenu<1){
            system("cls");
            colorTexto(4);
            cout << "Ingreso invalido, ingrese una opcion valida" << endl;
            colorTexto(1);
            system("pause");
        }
    }
    return seleccionMenu;
}
