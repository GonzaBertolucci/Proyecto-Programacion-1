#ifndef SINGLEPLAYER_H_INCLUDED
#define SINGLEPLAYER_H_INCLUDED

void singleplayer       (char *nombre, int tam,int puntajeMax,int *posPuntajeMax);

#endif // SINGLEPLAYER_H_INCLUDED

void singleplayer(char nombre[3][10], int tam,int puntajeMax,int *posPuntajeMax){
    bool gano = false;
    bool casoPrueba=false;
    int lanzaDados[tam];
    int contRonda = 1;
    int puntosTot = 0;
    int puntosRonda;
    int resultado;
    int puntosV=500;
    int *posPuntosTot = &puntosTot;

    obtenerNombre(nombre,0);

    if (nombre[0][0]=='t' && nombre[0][1]=='e' && nombre[0][2]=='s'&& nombre[0][3]=='t'){
        casoPrueba=true;
        system("cls");
        cout<<"Modo de prueba activado"<<endl;
        cout<<"Ingrese los puntos necesarios para obtener la victoria"<<endl;
        cin>>puntosV;
    }

    while(gano==false){
        system("cls");

             esquinasVisual(30,7,59,15);
            lineasHorizontales(31,7,88,15,1);
            lineasVerticales(30,8,21,59,1);
            rlutil::locate(52,13);
            cout<<"Nueva Ronda";
            rlutil::locate(52,14);
            cout<<"Ronda n"<<char(248)<<": "<<contRonda;

        rlutil::msleep(1500);
        puntosRonda = 0;
        srand(time(NULL));

        for(int i=1; i<4; i++){
            system("cls");

            if (casoPrueba==true){
                for (int j=0;j<tam;j++){
                    cout<<"Ingrese el resultado del dado "<<(j+1)<<endl;
                    cin>>lanzaDados[j];
                }
                system("cls");
            }else{
                generarArrayRand(lanzaDados, tam);
            }
            dibujaDados(lanzaDados, tam);                                //dibujadados

            rlutil::locate(1,1);                                        //interfaz
             cout<<"Ronda n"<<char(248)<<": "<<contRonda<<char(32)<<char(186)<<char(32)<<"Turno n"<<char(248)<<": "<<i<<char(32)<<char(186)<<char(32)<<"   Puntaje Total: "<<puntosTot<<endl;
            caracteresEspeciales(54,1,186,0);
            lineaHorizontal(1,2,53,3);
            caracteresEspeciales(13,2,202,0);
            caracteresEspeciales(27,2,202,0);
            caracteresEspeciales(54,2,188,1);
            lineasHorizontales(1,3,54,4,1);

            resultado=resultadoRonda(lanzaDados, tam);

            switch(resultado){
            case -1:
                puntosRonda = 0;
                i=3;
                rlutil::locate(1,5);
                colorTexto(4);
                cout<<"Sacaste 6 seises, perdiste los puntos de la ronda."<<endl;
                colorTexto(1);
                rlutil::locate(1,6);
                break;
            case 1:
                gano = true;
                i=3;
                rlutil::locate(23,5);
                colorTexto(6);
                cout<<char(173)<<"Escalera!"<<endl;
                colorTexto(1);
                rlutil::locate(1,6);
                break;
            default:
                puntosRonda += resultado;
                rlutil::locate(1,4);
                cout<<"Ganaste "<<resultado<<" puntos."<<endl;
                cout<<"En esta ronda llevas: "<<puntosRonda<<" puntos."<<endl;
                rlutil::locate(1,6);
                break;
            }
            system("pause");
        }

        system("cls");
        puntosTot+=puntosRonda;

        if(puntosTot>=puntosV || gano==true){
            gano=true;

            PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
            esquinasVisual(30,7,59,15);
            lineasHorizontales(31,7,88,15,1);
            lineasVerticales(30,8,21,59,1);
            rlutil::locate(44,13);
            cout<<"Felicidades ";
            colorTexto(8);
            cout<<nombre[0];
            colorTexto(6);
            cout<< char(32)<<char(173)<<"GANASTE!";
            colorTexto(1);
            rlutil::locate(44,14);
            cout<<"Conseguiste un total de "<<puntosTot<<" puntos.";

            if (puntosTot>puntajeMax && !casoPrueba){
                *posPuntajeMax=*posPuntosTot;
                guardarNPM(nombre,0);
            }

            rlutil::getkey();
        }
        else{
            contRonda++;
            esquinasVisual(30,7,59,15);
            lineasHorizontales(31,7,88,15,1);
            lineasVerticales(30,8,21,59,1);
             rlutil::locate(39,13);
             colorTexto(8);
            cout<<nombre[0];
            colorTexto(1);
            cout<<" llevas acumulado un total de: "<<puntosTot<<" Puntos";
            rlutil::locate(39,14);
            cout<<"Pasando a la siguiente ronda ...";
            rlutil::msleep(2000);
        }
    }
}
