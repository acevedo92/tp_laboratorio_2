#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char nombre[50], dni[9];
    int edad, estado;
}Epersona;

void inicializarEstados(Epersona persona[],int cantidad);
int menu();
int buscarLibre(Epersona persona[],int cantidad);
void agregarPersona(Epersona persona[],int cantidad);
void borrarPersona(Epersona persona[], int cantidad);
void listar(Epersona persona[], int cantidad);
void graficar(Epersona persona[], int CANT);

#endif
