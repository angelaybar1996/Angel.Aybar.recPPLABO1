#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

#define TAM_DES 24
typedef struct{

int id;//20000
char descripcion[TAM_DES];
float precio;

}eServicio;

int mostrarServicios(eServicio servicios[], int tamSer);
int mostrarServicio(eServicio* unServicio);
int cargarDescripcionServicio(int id,eServicio servicios[],int tamSer,char desc[]);

#endif // SERVICIO_H_INCLUDED
