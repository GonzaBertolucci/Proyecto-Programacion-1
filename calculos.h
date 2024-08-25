#ifndef CALCULOS_H_INCLUDED
#define CALCULOS_H_INCLUDED

void ordernarLista      (int *tirada,int tam);
bool esCalera           (int *tirada,int tam);
int calcularPuntos      (int *tirada,int tam);
int resultadoRonda      (int *tirada,int tam);
void generarArrayRand   (int *tirada,int tam);

#endif // CALCULOS_H_INCLUDED

int resultadoRonda (int tirada[],int tam){            // Calcula el resultado de la ronda.

    ordernarLista (tirada, tam);                       // Ordena la lista.

    if (esCalera(tirada, tam)){                        // Comprueba si el resultado es escalera
        return 1;                                      // Si se obtuvo escalera retorna 1.
    }else{
    return calcularPuntos(tirada, tam);                // En caso contrario retorna los puntos de la ronda
    }                                                  // o -1 en caso de que sean 6 seises.
}

void ordernarLista (int tirada[],int tam){             // Ordenamiento de burbuja.
    int temp = 0;                                      // Para que sea mas facil calcular si
    for (int i=1; i<tam; i++){                         // es escalera o no.
        for (int j=0 ; j<tam - 1; j++){
            if (tirada[j] > tirada[j+1]){
            temp = tirada[j];
            tirada[j] = tirada[j+1];
            tirada[j+1] = temp;
            }
        }
    }
}

bool esCalera (int tirada[],int tam){                  // Calcula si es escalera.
    for (int i=1; i<tam; i++){
        for (int j=0 ; j<tam - 1; j++){
            if ((tirada[j]+1)!=tirada[j+1]){           // Comprueba si el numero actual +1 es igual al
                return false;                         // numero siguiente. En caso de que no lo sea
            }                                          // devuelve falso.
        }
    }
    return true;
}

int calcularPuntos(int tirada[],int tam){              // Funcion para calcular los puntos.
    int puntos = 0;
    int contRep = 0;

    for (int i = 1; i < (tam+1); i++){                 // Comprueba si hay numeros repetidos.
        contRep=0;
        for (int j = 0; j < (tam); j++){               // Recorre el array.
            if (i== tirada[j]){                        // Si los hay el contador sube.
                contRep++;
            }
        }
        if (contRep>2){                                // Comprueba si el contador es 3 o mas.
            if (contRep==6){                           // Comprueba si el contador es 6.
                if (i==6){                             // Comprueba si el I es 6, en cuyo caso, el
                    puntos = -1;                       // resultado de la ronda son 6 seises y
                    return puntos;                     // retorna -1 porque la ronda entera queda anulada.
                }else{
                    puntos = i*50;                     // En caso contrario retorna el numero repetido 6
                    return puntos;                     // veces * 50, ya que no son 6 seises.
                }
            }else{                                     // Esta linea se ejecuta varias veces dado que va
                if (puntos < (i*10)){                  // a comprobar hasta un maximo de cuatro veces si
                    puntos = i*10;                     // el contador es igual a 6. En caso de que no lo
                }                                      // sea comprueba si puntos es 0 o tiene un puntaje
            }                                          // mayor al anterior, dado que en caso de que la
        }                                              // tirada sea 2 2 2 4 4 4 se decidio que quede como
    }                                                  // resultado el puntaje mas alto.

    if (puntos!=0){                                    // Es caso de que puntos no sea 0 significa que hubo
        return puntos;                                 // entre 3 y 5 numeros repetidos, por ende retorna
    }                                                  // el puntaje del numero repetido * 10.
    for (int i = 0; i< (tam) ; i++ ){                  //
        puntos += tirada[i];                           // En caso contrario suma todos los valores de la
    }                                                  // tirada porque no hubo 3 o mas numeros repitos y
    return puntos;                                     // devuelve ese valor
}

void generarArrayRand(int *tirada, int tam){           // Genera una lista de numeros randoms.
    for (int i=0;i<tam ;i++ ){
       tirada[i]=rand()%6+1;
    }
}
