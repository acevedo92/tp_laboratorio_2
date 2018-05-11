#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#define CANT 20

int main()
{
    Epersona persona[CANT];//lista de personas
    char continuar='s',confirmacion='n';
    int opcion;

    system("cls");
    inicializarEstados(persona,CANT);

    do{
        opcion=menu();
        switch (opcion){
            case 1:
            {
                agregarPersona(persona,CANT);
                break;
            }//end case 1
            case 2:
            {
                borrarPersona(persona,CANT);
                break;
            }//end case 2
            case 3:
            {
                listar(persona,CANT);
                break;
            }//end case 3
            case 4:
            {
                graficar(persona,CANT);
                break;
            }//end case 4
            case 5:
            {
                printf("Seguro desea salir? s|n: ");
                setbuf(stdin,NULL);
                scanf("%c",&confirmacion);
                confirmacion=tolower(confirmacion);
                if (confirmacion=='s')
                {
                    continuar='n';
                }
                break;
            }//end case 5
        }//end switch
    }while (continuar=='s');

}

