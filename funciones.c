#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
#include "funciones.h"

/** \brief Indica que todos los espacios de la lista se encuentran disponibles para su utilizacion
 *
 * \param persona[] recibe la lista como parametro
 * \param cantidad indica el tamaño de la lista
 * \return void
 *
 */
void inicializarEstados(Epersona persona[], int cantidad){
    int i;
    for (i=0;i<cantidad;i++){//recorre el array
        persona[i].estado=0;//indica que la posicion esta disponible
    }//end for
}//end inicializarEstados


/** \brief Despliega el menu de opciones. Valida y devuelve la opcion seleccionada por el usuario
 *
 * \return int
 *
 */
int menu(){
    int opcion,esNum,resultado=0;
    printf("\n1_Agregar Persona\n");
    printf("2_Borrar Persona\n");
    printf("3_Imprimir Lista Ordenada Alfabeticamente\n");
    printf("4_Imprimir Grafico de Edades\n");
    printf("5_Salir\n");
    setbuf(stdin,NULL);
    esNum=scanf("%d",&opcion);
    if(esNum==1 && opcion<=5 && opcion>=1)//valida que sea una opcion correcta
        resultado=opcion;
    else
        printf("\nOpcion invalida, intente nuevamente:\n");
    return resultado;
}//end menu


/** \brief Recorre la lista y devuelve el primer espacio libre disponible. De no existir ninguno devuelve -1
 *
 * \param persona[] recibe la lista como parametro
 * \param cantidad indica el tamaño de la lista
 * \return int
 *
 */
int buscarLibre(Epersona persona[],int cantidad){
    int i,resultado=-1;
    for(i=0;i<cantidad;i++){//recorre la lista
        if(persona[i].estado == 0)
            resultado=i;
    }//end for
    return resultado;
}//end buscarLibre


/** \brief Da de alta una persona en la lista
 *
 * \param persona[] recibe la lista como parametro
 * \param cantidad indica el tamaño de la lista
 * \return void
 *
 */
void agregarPersona(Epersona persona[],int cantidad){
    int libre;
    libre=buscarLibre(persona,cantidad);
    if (libre!=-1){//acciones a realizar en caso de encontrar un espacio libre
        printf("\nIngrese nombre:");
        setbuf(stdin,NULL);
        scanf("%[^\n]",persona[libre].nombre);
        strupr(persona[libre].nombre);
        printf("Ingrese DNI:");
        scanf("%s",persona[libre].dni);
        printf("Ingrese edad:");
        scanf("%d",&persona[libre].edad);
        persona[libre].estado=1;
    }//end if
    else//accion a realizar en caso de no encontrar un espacio libre
        printf("No hay espacios disponibles en la lista, elimine una persona existente\n");
}//end agregarPersona


/** \brief Busca y elimina a una persona por su DNI
 *
 * \param persona[] recibe la lista como parametro
 * \param cantidad indica el tamaño de la lista
 * \return void
 *
 */
void borrarPersona(Epersona persona[], int cantidad){
    int i,flag=0;
    char confirma='n',dni_aux[9];
    printf("\nIngrese el DNI de la persona a eliminar:");
    setbuf(stdin,NULL);
    scanf("%s",&dni_aux);
    for(i=0;i<cantidad;i++){ //recorre la lista en busca del DNI ingresado por el usario
        if(strcmp(dni_aux,persona[i].dni)==0){
            flag=1; //indica que logro encontrar el DNI
            break;
        }//end if
    }//end for
    if (flag==1){ //acciones a realizar en caso de encontrar el DNI
        printf("\nSeguro desea eliminar a la siguiente persona?:\n");
        printf("\nNombre: %s\nDNI: %s\ns|n: ",persona[i].nombre,persona[i].dni);
        setbuf(stdin,NULL);
        scanf("%c",&confirma);
        confirma=tolower(confirma);
        if (confirma=='s'){
            persona[i].estado=0;
            strcpy(persona[i].dni,"\0");
            printf("\nPersona eliminada con exito\n");
        }//end if confirma
        else
            printf("\nOperacion cancelada\n");
    }//end if flag
    else //accion a realizar en caso de no encontrar el DNI
        printf("\nNo se pudo encontrar el DNI\n");
}//end borrarPersona


/** \brief Despliega la lista de personas ordenada alfabeticamente
 *
 * \param persona[] recibe la lista compo parametro
 * \param cantidad indica el tamaño de la lista
 * \return void
 *
 */
void listar(Epersona persona[], int cantidad){
    int i,j;
    Epersona aux;
    for(i=0;i<cantidad-1;i++){
        for(j=i+1;j<cantidad;j++){
            if(strcmp(persona[i].nombre,persona[j].nombre)>0){
                aux=persona[i];
                persona[i]=persona[j];
                persona[j]=aux;
            }//end if
        }//end for j
    }//end for i

    for(i=0;i<cantidad;i++){
        if(persona[i].estado==1){
            printf("\nNombre: %s\nEdad: %d\nDNI: %s\n",persona[i].nombre,persona[i].edad,persona[i].dni);
        }//end if
    }//end for
}//end listar


/** \brief Despliega un grafico de edades
 *
 * \param persona[] recibe la lista como parametro
 * \param cantidad indica el tamaño de la lista
 * \return void
 *
 */
void graficar(Epersona persona[], int cantidad){
    int menores_18=0, entre_18y35=0, mayores_35=0;
    int edad[3];
    int i,j,max;

    for(i=0;i<cantidad;i++){//recorre la lista y clasifica las edades
        if(persona[i].estado==1){
            if(persona[i].edad<18 && persona[i].edad>0)
                menores_18++;
            else if(persona[i].edad>=18 && persona[i].edad<=35)
                entre_18y35++;
            else
                mayores_35++;
        }//end if
    }//end for

    edad[0]=menores_18;
    edad[1]=entre_18y35;
    edad[2]=mayores_35;
    max = 0;

    for(i = 0; i < 3; i++)//obtiene el grupo con mayor cantidad de personas
        if (edad[i] > max)
            max = edad[i];

    printf("\n");
    for (i = max; i > 0; i--){//grafico
        for (j = 0; j < 3; j++)
            if (edad[j] >= i)
                printf("  *\t");
            else
                printf("\t");
        printf("\n");
   }//end for
   printf(" <18\t18-35\t >35\n");
}//end graficar
