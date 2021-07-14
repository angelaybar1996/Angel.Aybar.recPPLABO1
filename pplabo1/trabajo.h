
#include "auto.h"
#include "servicio.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{

    int id;//el que quiera
    int idAuto;//idAuto,debe existir//
    int idServicio;//debe existir
    eFecha fecha;
    int isEmpty;

}eTrabajo;

int inicializarTrabajos(eTrabajo trabajos[], int tamTra);
int buscarLibre(eTrabajo trabajos[],int tamTra);
int buscarTrabajo(eTrabajo trabajos[],int tamTra, int legajoBuscado);

int altaTrabajo(eTrabajo trabajos[],int tamTra,eAuto autos[],int tamAuto,eServicio servicios[],int tamSer,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli, int* pId,int nextAuto);//listo
int bajaTrabajo(eTrabajo trabajos[],int tamTra,int indice);
int menuModificarTrabajo(eTrabajo trabajos[],int tamTra,eAuto autos[],int tamAuto,eServicio servicios[],int tamSer,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli, int indice,int nextAuto);

int mostrarTrabajo(eTrabajo* unTrabajo,eAuto autos[],int tamAuto,eServicio servicios[],int tamSer,eMarca marcas[],int tamMar,eColor colores[],int tamCol,int nextAuto);
int mostrarTrabajos(eTrabajo trabajos[],int tamTra,eAuto autos[],int tamAuto,eServicio servicios[],int tamSer,eMarca marcas[],int tamMar,eColor colores[],int tamCol,int nextAuto);

int cargarFechaTrabajo(int id,eTrabajo trabajos[],int tamTra,eFecha fecha);

int bajaAuto(eAuto autos[],int tamAuto,eTrabajo trabajos[],int tamTra,int indice);

#endif // TRABAJO_H_INCLUDED

