#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "datawarehouse.h"

#include "auto.h"
#include "trabajo.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "informes.h"
#include "cliente.h"

#define TAM_COL 5
#define TAM_MAR 5
#define TAM_SER 4
#define TAM_AUTO 15
#define TAM_TRA 30
#define TAM_CLI 10

int main(void)
{
    int opcion;
    eTrabajo trabajos[TAM_TRA];
    eAuto autos[TAM_AUTO];
    eMarca marcas[TAM_MAR]={{1000,"Renault"},{1001,"Fiat"},{1002,"Ford"},{1003,"Chevrolet"},{1004,"Peugeot"}};
    eServicio servicios[TAM_SER]={{20000,"Lavado",250},{20001,"Pulido",300},{20002,"Encerado",400},{20003,"Completo",600}};
    eColor colores[TAM_COL]={{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
    eCliente clientes[TAM_CLI]={
        {3000,"Pepe",'m',"Capital Federal"},{3001,"Pablo",'m',"Avellaneda"},{3002,"Jose",'m',"Lanus"},{3003,"Juan",'m',"Castelli"},{3004,"Abel",'m',"Vicente Lopez"},
        {3005,"Miguel",'m',"La plata"},{3006,"Ana",'f',"Paso del Rey"},{3007,"Maria",'f',"Pilar"},{3008,"Julia",'f',"Moron"},{3009,"Marisa",'f',"Valentin Alsina"}};


    int nextTrabajo=40000;
    int nextAuto=80000;
    int auxIndice;
    int decision;
    eAuto auxAuto;
    int flagAuto=0;

    inicializarTrabajos(trabajos,TAM_TRA);
    inicializarAutos(autos,TAM_AUTO);

    hardcodearTrabajos(trabajos,TAM_TRA,23,&nextTrabajo);
    hardcodearAutos(autos,TAM_AUTO,10,&nextAuto);

    do
    {
        if(utn_getNumero(&opcion,
                         "\n---------------------\n"
                         "LAVADERO DE AUTOS\n"
                         "---------------------\n"
                         "\n1.Alta Auto"
                         "\n2.Baja Auto"
                         "\n3.Modificar Auto"
                         "\n4.Listar Autos"
                         "\n5.Listar Marcas"
                         "\n6.Listar Colores"
                         "\n7.Listar Servicios"
                         "\n8.Alta Trabajo"
                         "\n9.Listar Trabajos"
                         "\n10.Informes"
                         "\n11.Salir\n\n"
                         "Ingrese opcion:",
                         "Opcion no valida",1,11,3)==0)
        {
            switch(opcion)
            {
                case 1:
                    if(altaAuto(autos,TAM_AUTO, marcas,TAM_MAR, colores, TAM_COL,clientes,TAM_CLI,&nextAuto)==0)
                    {
                        system("cls");
                        printf("Alta Auto exitosa\n");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("No hay lugar\n");
                        system("pause");
                    }
                    flagAuto=1;
                    break;
                case 2:
                    if(flagAuto)
                    {
                        mostrarAutos(autos, TAM_AUTO, marcas, TAM_MAR, colores, TAM_MAR,clientes,TAM_CLI);
                        if(utn_getTexto(auxAuto.patente,TAM_PAT,
                                "\nIngrese la patente del auto que desea eliminar:",
                                "\nError,la patente no es valida", 2)==0)
                        {
                            auxIndice=buscarAuto(autos, TAM_AUTO,auxAuto.patente);

                            if(auxIndice>=0 && mostrarAuto(autos[auxIndice], marcas, TAM_MAR, colores, TAM_COL,clientes,TAM_CLI)==0)
                            {
                                if(utn_getNumero(&decision,
                                                 "Desea eliminarlo?\n"
                                                 "\n1.[si]\n"
                                                 "\n2.[no]\n",
                                                 "Opcion no valida",1,2,1)==0)
                                {
                                    if(decision==1 &&
                                            bajaAuto(autos, TAM_AUTO,trabajos,TAM_TRA,auxIndice)==0)//bien

                                    {
                                        system("cls");
                                        printf("\nBaja realizada con exito\n");
                                        system("pause");
                                    }
                                    else
                                    {
                                        system("cls");
                                        printf("\nDar de baja cancelada\n");
                                        system("pause");
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        system("cls");
                        printf("Debe dar de Alta un auto para entrar a esta opcion\n");
                        system("pause");
                    }
                    break;
                case 3:
                    if(flagAuto)
                    {
                        mostrarAutos(autos, TAM_AUTO, marcas, TAM_MAR, colores, TAM_MAR,clientes,TAM_CLI);
                         if(utn_getTexto(auxAuto.patente,TAM_PAT,
                                "\nIngrese la patente del auto que desea modificar:",
                                "\nError,la patente no es valida",2)==0)
                        {
                            auxIndice=buscarAuto(autos, TAM_AUTO,auxAuto.patente);

                            if(auxIndice!=-1 && mostrarAuto(autos[auxIndice], marcas, TAM_MAR, colores, TAM_COL,clientes,TAM_CLI)==0)
                            {
                                if(utn_getNumero(&decision,
                                                 "Desea modificarlo?\n"
                                                 "\n1.[si]\n"
                                                 "\n2.[no]\n",
                                                 "Opcion no valida",1,2,1)==0)
                                {
                                    if(decision==2)
                                    {
                                        system("cls");
                                        printf("\nModificacion cancelada\n");
                                        system("pause");
                                    }
                                    else
                                    {
                                        system("cls");
                                        menuModificarAuto(autos,TAM_AUTO,marcas,TAM_MAR,colores,TAM_COL,clientes,TAM_CLI,auxIndice);
                                        system("pause");
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        system("cls");
                        printf("Debe dar de Alta un auto para entrar a esta opcion\n");
                        system("pause");
                    }
                    break;
                case 4:
                    if(flagAuto)
                    {
                        system("cls");
                        if(ordenarMarcaPatente(autos,TAM_AUTO,marcas,TAM_MAR,colores,TAM_COL)==0)//bien
                        {
                             mostrarAutos(autos,TAM_AUTO,marcas,TAM_MAR,colores,TAM_COL,clientes,TAM_CLI);//bien
                        }
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("Debe dar de Alta un auto para entrar a esta opcion\n");
                        system("pause");
                    }
                    break;
                case 5:
                    system("cls");
                    mostrarMarcas(marcas, TAM_MAR);//bien
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    mostrarColores(colores,TAM_COL);//bien
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    mostrarServicios(servicios,TAM_SER);//bien
                    system("pause");
                    break;
                case 8:
                    if(flagAuto)
                    {
                        if(altaTrabajo(trabajos,TAM_TRA,autos,TAM_AUTO,servicios,TAM_SER,marcas,TAM_MAR,colores,TAM_COL,clientes,TAM_CLI,&nextTrabajo,nextAuto)==0)
                        {
                            system("cls");
                            printf("\nAlta Trabajo exitosa\n\n");
                            system("pause");
                        }
                        else
                        {
                            system("cls");
                            printf("\nNo hay lugar\n\n");
                            system("pause");
                        }
                    }
                    else
                    {
                        system("cls");
                        printf("Debe dar de Alta un auto para entrar a esta opcion\n");
                        system("pause");
                    }
                    break;
                case 9:
                    if(flagAuto)
                    {
                         system("cls");
                        mostrarTrabajos(trabajos,TAM_TRA,autos,TAM_AUTO,servicios,TAM_SER,marcas,TAM_MAR,colores,TAM_COL,nextAuto);//bien
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("Debe dar de Alta un auto para entrar a esta opcion\n");
                        system("pause");
                    }
                    break;
                case 10:
                    if(flagAuto)
                    {
                        system("cls");
                        menuInformes(trabajos,TAM_TRA,autos,TAM_AUTO,servicios,TAM_SER,colores,TAM_COL,marcas,TAM_MAR,clientes,TAM_CLI,nextAuto,nextTrabajo);
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("Debe dar de Alta un auto para entrar a esta opcion\n");
                        system("pause");
                    }
                    break;
            }
        }
    }while(opcion!=11);

    return 0;
}
