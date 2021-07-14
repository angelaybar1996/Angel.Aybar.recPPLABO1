#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"

#define CANT 10
#define TAM_TRA 20

char nombres[CANT][TAM_TRA]={
    "Donato","German","Daniel",
    "Andrea","Carmen","Chepi",
    "Alex","Julio","Rosa","Camilo"};

char apellidos[CANT][TAM_TRA]={
    "Diaz","Gilardini","Pasco",
    "Ambrussiti","Caceres","Saenz",
    "Alvarez","Jaramillo","Buendia","Lopez"};

char sexos[CANT]={
    'm','m','m','f','f','f','m','m','f','m'};

int edades[CANT]={56,25,39,41,25,43,36,48,52,60};

int documentos[CANT]={40126493,44621458,43888777,38071976,22146789,35545696,32142788,41126475,20555321,20534512};

float sueldos[CANT]={
   15000,18000,20100,22500,30000,
   11000,10500,28000,29600,32500};

eFecha fechas[CANT]={
    {10,12,2018},{15,02,2012},{19,03,2020},
    {27,03,2018},{13,11,2021},{25,01,2013},
    {30,05,2015},{27,07,2016},{23,06,2019},
    {11,04,2011}};

char telefonos[CANT][TAM_TRA]={
    "11-50124578","4612-5207","4613-5112",
    "4615-5001","11-55124576","5212-5555",
    "4611-5990","11-37274577","9912-5887",
    "4402-5667"};

char mails[CANT][TAM_TRA]={
    "donato56@gmail.com","german25@gmail.com",
    "daniel39@gmail.com","andrea41@gmail.com",
    "carmen25@gmail.com","chepi43@gmail.com",
    "alex36@gmail.com","julio48@gmail.com",
    "rosa52@gmail.com","camilo60@gmail.com"};

char direcciones [CANT][TAM_TRA]={
    "fray cayetano 345","Av.Cordoba 1243",
    "Av.Corrientes 235","paseo Colon 478",
    "Av.Callao 367","catarmarca 3125",
    "humberto primo 1670","Av.Libertador 238",
    "Mozart 2334","Av.San juan 2701"};

char localidades[CANT][TAM_TRA]={
    "Capital Federal","Avellaneda",
    "Lanus","Castelli",
    "Vicente Lopez","La plata",
    "Paso del Rey","Pilar",
    "Moron","Valentin Alsina"};

//Para hardcodear 23 Trabajos

int idAutos[]={
80000,80006,80001,80005,80007,
80002,80000,80004,80001,80003,
80008,80001,80006,80003,80004,
80008,80005,80000,80005,80003,
80007,80009,80004};

int idServicios[]={
    20000,20003,20003,20002,20001,20000,20000,20001,
    20002,20001,20003,20001,20002,20002,20000,20003,
    20002,20002,20000,20001,20001,20003,20000};

eFecha fechasTrabajo[]={
    {1,1,2021},{1,1,2021},{1,1,2021},
    {1,1,2021},{1,1,2021},{1,1,2021},{2,1,2021},{2,1,2021},
    {2,1,2021},{2,1,2021},{2,1,2021},{3,1,2021},{3,1,2021},
    {3,1,2021},{3,1,2021},{3,1,2021},{3,1,2021},{4,1,2021},
    {4,1,2021},{4,1,2021},{4,1,2021},{4,1,2021},{4,1,2021}};

//para hardcodear 10 Autos

char patentes[CANT][TAM_TRA]={
    "TUI371","CAR123","VXZ489",
    "ASD523","QWE752","ABC473",
    "MRQ445","DQG196","ELP421","FAS456"};

int idMarcas[]={
    1000,1003,1002,1000,
    1000,1004,1002,1001,
    1004,1003};

int idColores[]={
    5000,5003,5002,5000,
    5000,5004,5002,5001,
    5004,5003};

int modelos[CANT]={1980,1996,2014,1986,1968,2021,2010,2018,2020,1998};

int idClientes[]={
    3000,3001,3002,3003,
    3004,3005,3006,3007,
    3008,3009};

/**
 * \brief  Hardcodea una lista de trabajos con sus datos
 * \param  trabajos Array de trabajos a cargar
 * \param  tamTra Limite del array de trabajos a cargar
 * \param  cant Cantidad de datos a cargar en el array de trabajos
 * \param  pId Puntero identificador a ser asignado al trabajo
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int hardcodearTrabajos(eTrabajo trabajos[], int tamTra,int cant,int* pId)
{
    int retorno=-1;

    if(trabajos!=NULL && tamTra>=0 && cant >=0 && cant <=tamTra &&pId!=NULL)
    {
        for(int i=0;i<cant;i++)
        {
            trabajos[i].idAuto=idAutos[i];
            trabajos[i].idServicio=idServicios[i];

            trabajos[i].fecha.dia=fechasTrabajo[i].dia;
            trabajos[i].fecha.mes=fechasTrabajo[i].mes;
            trabajos[i].fecha.anio=fechasTrabajo[i].anio;

            trabajos[i].id=*pId;
            (*pId)++;
            trabajos[i].isEmpty=0;

            retorno=0;
        }
    }
    return retorno;
}

/**
 * \brief  Hardcodea una lista de autos con sus datos
 * \param  autos  Array de autos  a cargar
 * \param  tamAuto Limite del array de autos  a cargar
 * \param  cant Cantidad de datos a cargar en el array de autos
 * \param  pId Puntero identificador a ser asignado al auto
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int hardcodearAutos(eAuto autos[],int tamAuto,int cant,int* pId)
{
    int retorno=-1;

    if(autos!=NULL && tamAuto>=0 && cant >=0 && cant <=tamAuto && pId!=NULL)
    {
        for(int i=0;i<cant;i++)
        {
            autos[i].id=*pId;
            strcpy(autos[i].patente,patentes[i]);//bien
            autos[i].idMarca=idMarcas[i];
            autos[i].idColor=idColores[i];
            autos[i].modelo=modelos[i];
            autos[i].idCliente=idClientes[i];

            autos[i].isEmpty=0;
            (*pId)++;
            retorno=0;
        }
    }
    return retorno;
}

