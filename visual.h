#ifndef VISUAL_H_INCLUDED
#define VISUAL_H_INCLUDED
char tipoLineaHori           (int tipoLinea);
char tipoVer                 (int tipoLinea);
void lineaHorizontal         (int x, int y, int tope, int tipoLinea);
void lineaVertical           (int x, int y, int tope, int tipoLinea);
void esquinasVisual          (int x, int y, int diferenciaX, int diferenciaY);
void lineasHorizontales      (int x, int y, int tope, int diferenciaY, int tipoLinea);
void lineasVerticales        (int x, int y, int tope, int diferenciaX, int tipoLinea);
void puntajeMaxVisual        (char *nombres,int puntajeMax);
void colorTexto              (int color);
void caracteresEspeciales    (int x, int y, int caracter, bool salto);
void dibujaDados             (int lanzaDados[],int tam);

#endif // VISUAL_H_INCLUDED

void colorTexto(int color){

    switch (color){
        case 1:
            rlutil::setColor(rlutil::WHITE);
            break;
        case 2:
            rlutil::setColor(rlutil::GREEN);
            break;
        case 3:
            rlutil::setColor(rlutil::CYAN);
            break;
        case 4:
            rlutil::setColor(rlutil::RED);
            break;
        case 5:
            rlutil::setColor(rlutil::MAGENTA);
            break;
        case 6:
            rlutil::setColor(rlutil::YELLOW);
            break;
        case 7:
            rlutil::setColor(rlutil::BLUE);
            break;
        case 8:
            rlutil::setColor(rlutil::LIGHTMAGENTA);
            break;
        default:
            rlutil::setColor(rlutil::BROWN);
            break;
    }
}

char tipoLineaHori (int tipoLinea){

    switch (tipoLinea){
        case 1:
            return char(45);  //linea no-continua
            break;
        case 2:
            return char(196); //linea seguida
            break;
        case 3:
            return char(205); //Doble linea seguida
            break;
        case 4:
            return char(238); //linea seguida superior
            break;
        default:
            break;
    }
}

char tipoLineaVer (int tipoLinea){

    if (tipoLinea==1){
        return char(221); //linea no continua
    }else{
        return char(179); //linea continua
    }
}

void lineaHorizontal(int x,int y, int tope,int tipoLinea){                //esta funcion hace lineas horizontales

    char charLinea=tipoLineaHori(tipoLinea);
    for ( x; x <= tope; x++){                                               //pide posicion "x","y","tope" y tipoLinea (hasta donde llega la linea en las cordenadas x,y)
        rlutil::locate(x,y);                                                 //en el for primero localiza la posicion (x,y), despues dibuja el primer guion
        cout<<charLinea;                                                    //y despues sigue aumentando el valor de x, desplazandose hacia la derecha
    }
    cout << endl;
}
void lineaVertical(int x, int y, int tope, int tipoLinea){

    char charLinea=tipoLineaVer(tipoLinea);
    for ( y; y <= tope; y++){
        rlutil::locate(x,y);
        cout<<charLinea;
    }
    cout << endl;
}

void esquinasVisual(int x, int y, int diferenciaX, int diferenciaY){

    for (int esquina = 1; esquina < 5; esquina++){
        switch (esquina){
        case 1:                     //esquina superior izquierda
            rlutil::locate(x,y);
            cout << char(218);;
            break;
        case 2:                     //esquina superior derecha
            rlutil::locate((x+diferenciaX),y);
            cout << char(191);;
            break;
        case 3:                     //esquina inferior izquierda
            rlutil::locate(x,(y+diferenciaY));
            cout << char(192);
            break;
        case 4:                     //esquina inferior derecha
            rlutil::locate((x+diferenciaX),(y+diferenciaY));
            cout << char(217);
            break;
        default:
            break;
        }
    }
}

void lineasHorizontales(int x, int y, int tope, int diferenciaY, int tipoLinea){

    int temp=x;
    char charLinea=tipoLineaHori(tipoLinea);
    for (int i = 1; i <3; i++){
        x=temp;
        for ( x; x <= tope; x++){
            rlutil::locate(x,y);
            cout<<charLinea;
            }
    y+=diferenciaY;
    }
}

void lineasVerticales(int x, int y, int tope, int diferenciaX, int tipoLinea){

    int temp=y;
    char charLinea=tipoLineaVer(tipoLinea);
    for (int i = 1; i < 3; i++){
        y=temp;
        for ( y; y <= tope; y++){
            rlutil::locate(x,y);
            cout<<charLinea;
        }
    x+=diferenciaX;
    }
}

void puntajeMaxVisual(char nombre[3][10],int puntajeMax){
    //Color
    colorTexto(6);
    //Esquinas
    esquinasVisual(30,7,59,15);
    //Lineas
    lineasHorizontales(31,7,88,15,1);
    lineasVerticales(30,8,21,59,1);
    //Sonidos
    PlaySound(TEXT("redoble.wav"), NULL, SND_ASYNC);

    rlutil::locate(47,13);
    cout << "El puntaje maximo es de: ";
    rlutil::locate(47,14);
    cout << "Puntaje obtenido por: ";
    rlutil::msleep(3500);
    colorTexto(1);
    rlutil::locate(72,13);
    cout <<puntajeMax;
    rlutil::locate(69,14);
    colorTexto(8);
    cout <<nombre[2];
    colorTexto(1);
    rlutil::locate(75,14);
    rlutil::getkey();
}

void caracteresEspeciales(int x, int y, int caracter, int salto){

    rlutil::locate(x,y);
    if(salto==0){
        cout << char(caracter);
    }else{
        cout << char(caracter)<< endl;
    }
}

void dibujaDados(int lanzaDados[],int tam){

    int simboloDado=254;
    int tipoLineas=2;
    int lineasH[4]={2,8,8,4};
    int lineasV[4]={1,9,11,8};

for (int i=0; i<tam; i++){

    colorTexto(lanzaDados[i]);
    lineasHorizontales(lineasH[0],lineasH[1],lineasH[2],lineasH[3],tipoLineas);
    lineasVerticales(lineasV[0],lineasV[1],lineasV[2],lineasV[3],tipoLineas);
    esquinasVisual(lineasV[0],lineasH[1],lineasV[3],lineasH[3]);

    switch (lanzaDados[i]){
        case 1:                                               //dado 1
            caracteresEspeciales((lineasV[0]+4),10,simboloDado,0);
            rlutil::locate(100,20);
            break;
        case 2:                                               //dado 2
            caracteresEspeciales((lineasV[0]+6),9,simboloDado,0);
            caracteresEspeciales((lineasV[0]+2),11,simboloDado,0);
            rlutil::locate(100,20);
            break;
        case 3:                                               //dado 3
            caracteresEspeciales((lineasV[0]+6),9,simboloDado,0);
            caracteresEspeciales((lineasV[0]+4),10,simboloDado,0);
            caracteresEspeciales((lineasV[0]+2),11,simboloDado,0);
            rlutil::locate(100,20);
            break;
        case 4:                                               //dado 4
            caracteresEspeciales((lineasV[0]+2),9,simboloDado,0);
            caracteresEspeciales((lineasV[0]+6),9,simboloDado,0);
            caracteresEspeciales((lineasV[0]+2),11,simboloDado,0);
            caracteresEspeciales((lineasV[0]+6),11,simboloDado,0);
            rlutil::locate(100,20);
            break;
        case 5:                                               //dado 5
            caracteresEspeciales((lineasV[0]+2),9,simboloDado,0);
            caracteresEspeciales((lineasV[0]+6),9,simboloDado,0);
            caracteresEspeciales((lineasV[0]+4),10,simboloDado,0);
            caracteresEspeciales((lineasV[0]+2),11,simboloDado,0);
            caracteresEspeciales((lineasV[0]+6),11,simboloDado,0);
            rlutil::locate(100,20);
            break;
        case 6:                                               //dado 6
            caracteresEspeciales((lineasV[0]+1),9,simboloDado,0);
            caracteresEspeciales((lineasV[0]+4),9,simboloDado,0);
            caracteresEspeciales((lineasV[0]+7),9,simboloDado,0);
            caracteresEspeciales((lineasV[0]+1),11,simboloDado,0);
            caracteresEspeciales((lineasV[0]+4),11,simboloDado,0);
            caracteresEspeciales((lineasV[0]+7),11,simboloDado,0);
            rlutil::locate(100,20);
            break;
    default:
        break;
    }
    lineasH[0]+=9;
    lineasH[2]+=9;
    lineasV[0]+=9;
   }
 colorTexto(1);
}
