#include "trabajo.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int menuInformes(eTrabajo trabajos[],int tamTra,eAuto autos[],int tamAuto,eServicio servicios[],int tamSer,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli,int nextAuto,int nextTrabajo);//listo

int mostrarAutosColor(eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);//listo
int mostrarAutosAllMarcas(eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);//listo
int listarAutosMasViejos(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);//listo
int trabajosAuto(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli,int nextAuto);//listo
int totalTrabajosAuto(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli,int nextAuto);//listo
int listarTotalServiciosFecha(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol,int nextAuto);
int cantidadColoresMarcas(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol);
int cantidadAutoMarca(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol);
int informarCantidadServicios(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli);//listo
int marcaAuto(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli);

int mostrarAutosLocalidad(eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);//listo
int mostrarAutosCapitalFederal(eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);//listo
int mostrarAutosProvinciaBa(eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);//listo
int listarAutosMasNuevos(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);
int mostrarAutosAllLocalidades(eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);//listo

#endif // INFORMES_H_INCLUDED
