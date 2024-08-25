#ifndef MULTIPLAYER_H_INCLUDED
#define MULTIPLAYER_H_INCLUDED

void multiplayer        (char *nombres, int tam,int puntajeMax,int *posPuntajeMax);

#endif // MULTIPLAYER_H_INCLUDED

void multiplayer(char nombres[3][10], int tam,int puntajeMax,int *posPuntajeMax){
    bool seis6P1 = false;
    bool seis6P2 = false;
    bool ganoP1 = false;
    bool ganoP2 = false;
    bool casoPrueba=false;
    bool terminoJuego=false;
    int lanzaDados[tam];
    int puntosTotP1 = 0;
    int puntosTotP2 = 0;
    int puntosRondaP1;
    int puntosRondaP2;
    int resultado;
    int contTurnos;
    int contRonda = 1;
    int puntosV=500;
    int maxDRondas=0;
    int *posPuntosTotP1 = &puntosTotP1;
    int *posPuntosTotP2 = &puntosTotP2;
    colorTexto(7);
    cout<<"Jugador 1"<<endl;
    colorTexto(1);
    obtenerNombre(nombres,0);
    system("cls");
    colorTexto(4);
    cout<<"Jugador 2"<<endl;
    colorTexto(1);
    obtenerNombre(nombres,1);

    system("cls");
    lineasHorizontales(1,1,50,3,1);
    colorTexto(2);
    rlutil::locate(1,2);
    cout<<"Seleccione el maximo numero de rondas de la partida"<<endl<<"Ingrese 0 para una cantidad infinita"<<endl;
    colorTexto(1);
    rlutil::locate(1,5);
    cin>>maxDRondas;

    if (nombres[0][0]=='t' && nombres[0][1]=='e' && nombres[0][2]=='s'&& nombres[0][3]=='t'){
        casoPrueba=true;
        system("cls");
        cout<<"Modo de prueba activado"<<endl;
        cout<<"Ingrese los puntos necesarios para obtener la victoria"<<endl;
        cin>>puntosV;
    }

    while(ganoP1==false && ganoP2==false && terminoJuego==false ){
        system("cls");
        esquinasVisual(30,7,59,15);
        lineasHorizontales(31,7,88,15,1);
        lineasVerticales(30,8,21,59,1);
        rlutil::locate(52,13);
        cout<<"Nueva Ronda";
        rlutil::locate(52,14);
        cout<<"Ronda n"<<char(248)<<": "<<contRonda;
        seis6P1 = false;
        seis6P2 = false;
        puntosRondaP1 = 0;
        puntosRondaP2 = 0;
        contTurnos = 1;
        srand(time(NULL));

        rlutil::msleep(1500);

        for(int i=1; i<7; i++){
            system("cls");
            if(i%2!=0 && !seis6P1){

                if (casoPrueba==true){
                    for (int j=0;j<tam;j++){
                    cout<<"Ingrese el resultado del dado "<<(j+1)<<endl;
                    cin>>lanzaDados[j];
                    }
                    system("cls");
                }else{
                    generarArrayRand(lanzaDados, tam);
                }
                dibujaDados(lanzaDados, tam);
                rlutil::locate(1,1);                                        //interfaz
                cout<<"Ronda n"<<char(248)<<": "<<contRonda<<char(32)<<char(186)<<char(32);
                colorTexto(7);
                cout<<nombres[0]<<char(32);
                colorTexto(1);
                cout<<char(186)<<char(32)<<"Turno n"<<char(248)<<": "<<contTurnos<<char(32)<<char(186)<<char(32)<<"Puntaje Total: "<<puntosTotP1<<char(32);
                lineaHorizontal(1,2,60,3);
                caracteresEspeciales(60,1,186,0);
                caracteresEspeciales(60,2,188,1);
                lineasHorizontales(1,3,54,4,1);

                resultado=resultadoRonda(lanzaDados, tam);
                contTurnos++;

                switch(resultado){
                case -1:
                    puntosRondaP1 = 0;
                    seis6P1 = true;
                    rlutil::locate(1,5);
                    colorTexto(4);
                    cout<<"Sacaste 6 seises, perdiste los puntos de la ronda."<<endl;
                    colorTexto(1);
                    rlutil::locate(1,6);
                    break;
                case 1:
                    ganoP1 = true;
                    i = 7;
                    rlutil::locate(23,5);
                    colorTexto(6);
                    cout<<char(173)<<"Escalera!"<<endl;
                    colorTexto(1);
                    rlutil::locate(1,6);
                    break;
                default:
                    puntosRondaP1 += resultado;
                    rlutil::locate(1,4);
                    cout<<"Ganaste "<<resultado<<" puntos."<<endl;
                    cout<<"En esta ronda llevas: "<<puntosRondaP1<<" puntos."<<endl;
                    rlutil::locate(1,6);
                    break;
                }

            }else if (!seis6P2){

                if (casoPrueba==true){
                    for (int j=0;j<tam;j++){
                    cout<<"Ingrese el resultado del dado "<<(j+1)<<endl;
                    cin>>lanzaDados[j];
                    }
                    system("cls");
                }else{
                    generarArrayRand(lanzaDados, tam);
                }
                 dibujaDados(lanzaDados, tam);
                rlutil::locate(1,1);                                        //interfaz
                cout<<"Ronda n"<<char(248)<<": "<<contRonda<<char(32)<<char(186)<<char(32);
                colorTexto(4);
                cout<<nombres[1]<<char(32);
                colorTexto(1);
                cout<<char(186)<<char(32)<<"Turno n"<<char(248)<<": "<<(i/2)<<char(32)<<char(186)<<char(32)<<"Puntaje Total: "<<puntosTotP2<<char(32);
                lineaHorizontal(1,2,60,3);
                caracteresEspeciales(60,1,186,0);
                caracteresEspeciales(60,2,188,1);
                lineasHorizontales(1,3,54,4,1);
                resultado=resultadoRonda(lanzaDados, tam);

                switch(resultado){
                case -1:
                    puntosRondaP2 = 0;
                    seis6P2 = true;
                    rlutil::locate(1,5);
                    colorTexto(4);
                    cout<<"Sacaste 6 seises, perdiste los puntos de la ronda."<<endl;
                    colorTexto(1);
                    rlutil::locate(1,6);
                    break;
                case 1:
                    ganoP2 = true;
                    i = 7;
                    rlutil::locate(23,5);
                    colorTexto(6);
                    cout<<char(173)<<"Escalera!"<<endl;
                    colorTexto(1);
                    rlutil::locate(1,6);
                    break;
                default:
                    puntosRondaP2 += resultado;
                    rlutil::locate(1,4);
                    cout<<"Ganaste "<<resultado<<" puntos."<<endl;
                    cout<<"En esta ronda llevas: "<<puntosRondaP2<<" puntos."<<endl;
                    rlutil::locate(1,6);
                    break;
                }
            }
        system("pause");
        system("cls");
        }

        system("cls");

        puntosTotP1 += puntosRondaP1;
        puntosTotP2 += puntosRondaP2;

        if (contRonda==maxDRondas){
            terminoJuego=true;
        }

        if((puntosTotP1>=puntosV && puntosTotP1 > puntosTotP2) || (terminoJuego && puntosTotP1 > puntosTotP2) || ganoP1==true){ //Jugador 1 win
            PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);

            esquinasVisual(30,7,59,15);
            lineasHorizontales(31,7,88,15,1);
            lineasVerticales(30,8,21,59,1);
            rlutil::locate(44,13);
            cout<<"Felicidades ";
            colorTexto(7);
            cout<<nombres[0];
            colorTexto(6);
            cout<< char(32)<<char(173)<<"GANASTE!";
            colorTexto(1);
            rlutil::locate(44,14);
            cout<<"Conseguiste un total de "<<puntosTotP1<<" puntos";
            rlutil::locate(44,15);
            cout<<"Mientras que ";
            colorTexto(4);
            cout<<nombres[1];
            colorTexto(1);
            cout<<" consiguio: "<<puntosTotP2;

            ganoP1=true;
            if (puntosTotP1>puntajeMax && !casoPrueba){
                *posPuntajeMax=*posPuntosTotP1;
                guardarNPM(nombres,0);
            }
            rlutil::getkey();
        } else if((puntosTotP2>=puntosV && puntosTotP2 > puntosTotP1) || (terminoJuego && puntosTotP1 < puntosTotP2) || ganoP2 == true){ // Jugador 2 win
            PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);

            esquinasVisual(30,7,59,15);
            lineasHorizontales(31,7,88,15,1);
            lineasVerticales(30,8,21,59,1);
            rlutil::locate(44,13);
            cout<<"Felicidades ";
            colorTexto(4);
            cout<<nombres[1];
            colorTexto(6);
            cout<< char(32)<<char(173)<<"GANASTE!";
            colorTexto(1);
            rlutil::locate(44,14);
            cout<<"Conseguiste un total de "<<puntosTotP2<<" puntos";
            rlutil::locate(44,15);
            cout<<"Mientras que ";
            colorTexto(7);
            cout<<nombres[0];
            colorTexto(1);
            cout<<" consiguio: "<<puntosTotP1;

            ganoP2=true;
            if (puntosTotP2>puntajeMax && !casoPrueba){
                *posPuntajeMax=*posPuntosTotP2;
                guardarNPM(nombres,1);
            }
            rlutil::getkey();
        } else if((puntosTotP1>puntosV) || (terminoJuego) ){ //Empate
            PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
            esquinasVisual(30,7,59,15);
            lineasHorizontales(31,7,88,15,1);
            lineasVerticales(30,8,21,59,1);
            rlutil::locate(41,13);
            cout<<"Ambos jugadores empataron con "<< puntosTotP1 <<" puntos";
            ganoP1=true;
            ganoP2=true;
            rlutil::getkey();

        } else{ // Aun nadie gano
            contRonda++;

            esquinasVisual(30,7,59,15);
            lineasHorizontales(31,7,88,15,1);
            lineasVerticales(30,8,21,59,1);
            //jugador1
            rlutil::locate(39,13);
            colorTexto(7);
            cout<<nombres[0];
            colorTexto(1);
            cout<<" llevas acumulado un total de: "<<puntosTotP1<<" Puntos";
            //jugador2
            rlutil::locate(39,14);
            colorTexto(4);
            cout<<nombres[1];
            colorTexto(1);
            cout<<" llevas acumulado un total de: "<<puntosTotP2<<" Puntos";
            //Proxima Ronda
            rlutil::locate(39,15);
            cout<<"Pasando a la siguiente ronda ...";
            rlutil::msleep(3500);
        }
    }
}
