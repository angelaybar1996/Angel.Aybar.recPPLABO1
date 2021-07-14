#include "utn.h"
#include "fecha.h"
#include "marca.h"
#include "color.h"
#include "cliente.h"

#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#define TAM_PAT 20

typedef struct{

int id;//el que quiera
char patente[TAM_PAT];
int idMarca;
int idColor;
int idCliente;
int modelo;//anio

int isEmpty;

}eAuto;

int inicializarAutos(eAuto autos[], int tamAuto);
int buscarLibreAuto(eAuto autos[],int tamAuto);
int buscarAuto(eAuto autos[],int tamAuto, char patente[]);
int buscarAutoId(eAuto autos[],int tamAuto, int id);

int altaAuto(eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli,int* pNextId);
//aca estaba bajaAuto pero como si se elimina un auto se debe eliminar trabajos de ese auto lo lleve a trabajo.h
int menuModificarAuto(eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli,int indice);

int mostrarAuto(eAuto unAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli);
int mostrarAutos(eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli);

int cargarDescripcionAuto(int id,eAuto autos[],int tamAuto,char desc[],int nextAuto);
int ordenarMarcaPatente(eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[], int tamCol);

#endif // AUTO_H_INCLUDED

