#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabajo.h"


/**
 * \brief Inicializa el array
 * \param  lista array de trabajos a ser actualizados
 * \param tam limite del array de trabajos
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int inicializarTrabajos(eTrabajo trabajos[], int tamTra)
{
    int retorno=-1;

    if(trabajos!=NULL && tamTra>0)
    {
        retorno=0;
        for(int i=0; i<tamTra; i++)
        {
            trabajos[i].isEmpty=1;
        }
    }
    return retorno;
}

/**
 * \brief busca un id en un array y devuelve la posicion en que se encuentra
 * \param  trabajos array de trabajos
 * \param tamTra limite del array de trabajos
 * \param idBuscado el valor buscado
 * \return Retorna la posicion en que se encuentra el id ó -1 (ERROR)
 */
int buscarTrabajo(eTrabajo trabajos[],int tamTra, int idBuscado)
{
    int retorno=-1;
	int i;

	if(trabajos!=NULL &&tamTra>0 && idBuscado>=0 )
	{
		retorno=0;
		for(i=0;i<tamTra;i++)
		{
			if(trabajos[i].id==idBuscado && trabajos[i].isEmpty==0)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief busca la primer posicion vacia
 * \param  trabajos array de trabajos
 * \param tamAuto limite del array de trabajos
 * \return Retorna el indice de la posicion vacia ó -1 (ERROR)
 */
int buscarLibre(eTrabajo trabajos[],int tamAuto)
{
    int retorno=-1;
    if(trabajos!=NULL && tamAuto>=0)
    {
        for(int i=0; i<tamAuto; i++)
        {
            if(trabajos[i].isEmpty)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Imprime los datos de un un trabajo
 * \param unTrabajo Puntero al trabajo que se busca imprimir
 * \param autos array de autos
 * \param tamAuto limite del array de autos
 * \param servicios array de servicios
 * \param tamSer limite del array de servicios
 * \param marcas array de marcas
 * \param tamMar limite del array de marcas
 * \param colores array de colores
 * \param tamCol limite del array de colores
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarTrabajo(eTrabajo* unTrabajo,eAuto autos[],int tamAuto,eServicio servicios[],int tamSer,eMarca marcas[],int tamMar,eColor colores[],int tamCol,int nextAuto)
{
    int retorno=-1;
    char descAuto[20];
    char descServicio[20];

    if(unTrabajo!=NULL && unTrabajo->isEmpty==0 && autos!=NULL && tamAuto>=0 && servicios!=NULL && tamSer>=0 && marcas!=NULL && tamMar>=0 && colores!=NULL && tamCol>=0)
    {
        //cargarDescripcionColor(unEmpleado->idSector,sectores,tamSec,descripcion);
        cargarDescripcionServicio(unTrabajo->idServicio,servicios,tamSer,descServicio);
        cargarDescripcionAuto(unTrabajo->idAuto,autos,tamAuto,descAuto,nextAuto);//listo
        retorno=0;
      //printf("Id       Patente   Servicio       Fecha   \n");
        printf("\n%d      %10s       %10s      %2d/%2d/%4d   ",
               unTrabajo->id,
               descAuto,
               descServicio,
               unTrabajo->fecha.dia,unTrabajo->fecha.mes,unTrabajo->fecha.anio);
    }
    return retorno;
}

/**
 * \brief Imprime el array de trabajos
 * \param trabajos Array de trabajos a ser actualizados
 * \param tamTra limite del array de trabajos
 * \param autos array de autos
 * \param tamAuto limite del array de autos
 * \param servicios array de servicios
 * \param tamSer limite del array de servicios
 * \param marcas array de marcas
 * \param tamMar limite del array de marcas
 * \param colores array de colores
 * \param tamCol limite del array de colores
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarTrabajos(eTrabajo trabajos[],int tamTra,eAuto autos[],int tamAuto,eServicio servicios[],int tamSer,eMarca marcas[],int tamMar,eColor colores[],int tamCol,int nextAuto)
{
    int retorno=-1;

    printf("\nLista de Trabajos\n");
    printf("\n----------------------------------------------------------------");
    printf("\nId             Patente          Servicio        Fecha   ");
    printf("\n----------------------------------------------------------------");
    if(trabajos!=NULL && tamTra>=0 && autos!=NULL && tamAuto>=0 && servicios!=NULL && tamSer>=0 && marcas!=NULL && tamMar>=0 && colores!=NULL && tamCol>=0)
    {
        retorno=0;
        for(int i=0; i<tamTra; i++)
        {
            mostrarTrabajo(&trabajos[i],autos,tamAuto,servicios,tamSer,marcas,tamMar,colores,tamCol,nextAuto);
        }
        printf("\n\n");
    }
    return retorno;
}

/**
 * \brief Da de alta un trabajo en una posicion del array
 * \param trabajos array de trabajos a ser actualizados
 * \param tamTra Limite del array de empleados
 * \param autos array de autos
 * \param tamAuto limite del array de autos
 * \param servicios array de servicios
 * \param tamSer limite del array de servicios
 * \param marcas array de marcas
 * \param tamMar limite del array de marcas
 * \param colores array de colores
 * \param tamCol limite del array de colores
 * \param pId Puntero identificador a ser asignado al trabajo
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int altaTrabajo(eTrabajo trabajos[],int tamTra,eAuto autos[],int tamAuto,eServicio servicios[],int tamSer,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli, int* pId,int nextAuto)
{
    int retorno=-1;
    int i;
    eTrabajo auxTrabajo;

    i=buscarLibre(trabajos,tamTra);

    if(trabajos!=NULL && tamTra>=0 && autos!=NULL && tamAuto>=0 && servicios!=NULL && tamSer>=0 && marcas!=NULL && tamMar>=0 && clientes!=NULL && tamCli>=0 &&pId!=NULL )
    {
        printf("\nId: %d\n",*pId);
        if(i>=0)
        {
            mostrarAutos(autos,tamAuto,marcas,tamMar,colores,tamCol,clientes,tamCli);
            if(utn_getNumero(&auxTrabajo.idAuto,"\nIngrese id del auto:","\nError,id no valido\n",80000,nextAuto,2)==0)
            {
                mostrarServicios(servicios,tamSer);
                if(utn_getNumero(&auxTrabajo.idServicio,"\nIngrese id del servicio:","\nError,id no valido\n",20000,20003,2)==0 &&
                   utn_getNumero(&auxTrabajo.fecha.dia,"Ingrese fecha\nIngrese dia:","\nError,dia no valido\n",1,31,2)==0 &&
                   utn_getNumero(&auxTrabajo.fecha.mes,"Ingrese mes:","\nError,mes no valido\n",1,12,2)==0&&
                   utn_getNumero(&auxTrabajo.fecha.anio,"Ingrese anio:","\nError,anio no valido\n",1,3000,2)==0)
                {
                    auxTrabajo.isEmpty=0;
                    auxTrabajo.id=*pId;
                    trabajos[i]=auxTrabajo;
                    (*pId)++;
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

/**
 * \brief Actualiza una posicion del array
 * \param trabajos array de trabajo a ser actualizados
 * \param tamTra limite del array de trabajos
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int bajaTrabajo(eTrabajo trabajos[],int tamTra,int indice)
{
    int retorno=-1;

    if(trabajos!=NULL && tamTra>=0 && indice >=0)
    {
        trabajos[indice].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

/**
 * \brief Busca un id y lo remplaza por su fecha
 * \param id identificador del trabajo
 * \param trabajos Array de trabajo
 * \param tamTra limite del array de trabajos
 * \param fecha  donde se va a cargar la fecha
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int cargarFechaTrabajo(int id,eTrabajo trabajos[],int tamTra,eFecha fecha)//despues probar este
{
    int retorno=-1;
    int indice;

    if(trabajos!=NULL && tamTra>=0)
    {
        indice=buscarTrabajo(trabajos,tamTra,id);
        if(indice!=-1)
        {
            trabajos[indice].fecha=fecha;
            retorno=0;
        }
    }
    return retorno;
}

/**
 * \brief Menu de opciones de los datos del trabajo a modificar
 * \param trabajos array de trabajo a ser actualizados
 * \param tamTra limite del array de trabajos
 * \param autos array de autos
 * \param tamAuto limite del array de autos
 * \param servicios array de servicios
 * \param tamSer limite del array de servicios
 * \param marcas array de marcas
 * \param tamMar limite del array de marcas
 * \param colores array de colores
 * \param tamCol limite del array de colores
 * \param indice Posicion recibida
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int menuModificarTrabajo(eTrabajo trabajos[],int tamTra,eAuto autos[],int tamAuto,eServicio servicios[],int tamSer,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli, int indice,int nextAuto)
{
    int retorno=-1;
    int opcion;
    eTrabajo auxTrabajo;

	if(trabajos!=NULL &&tamTra>0 &&indice<tamTra && autos!=NULL && tamAuto>=0  && servicios!=NULL && tamSer>=0 && marcas!=NULL && tamMar>=0 && colores!=NULL && tamCol>=0  && clientes!=NULL && tamCli>=0 &&trabajos[indice].isEmpty==0)
	{
	    do
        {
            if(utn_getNumero(&opcion,
                             "Modificar Trabajo\n\n"
                             "\n1.Modificar patente"
                             "\n2.Modificar servicio"
                             "\n3.Modificar fecha"
                             "\n4.Salir\n\n"
                             "Ingrese opcion:","\nError,opcion no valida\n",1,4,2)==0)
            {
                retorno=0;
                switch(opcion)
                {
                    case 1:
                        mostrarAutos(autos,tamAuto,marcas,tamMar,colores,tamCol,clientes,tamCli);
                        if(utn_getNumero(&auxTrabajo.idAuto,"\nIngrese id del auto:",
                                         "\nError,id no valido:",80000,nextAuto,2)==0)
                        {
                            trabajos[indice].idAuto=auxTrabajo.idAuto;//listo
                        }
                        break;
                    case 2:
                        mostrarServicios(servicios,tamSer);
                        if(utn_getNumero(&auxTrabajo.idServicio,
                                      "Ingrese id del servicio:",
                                      "\nError,id no valido\n",20000,20003,2)==0)
                        {
                            trabajos[indice].idServicio=auxTrabajo.idServicio;
                        }
                        break;
                    case 3:
                        if(utn_getNumero(&auxTrabajo.fecha.dia,"Ingrese fecha\n\nDia:","\nError,dia no valido\n",1,31,2)==0 &&
                        utn_getNumero(&auxTrabajo.fecha.mes,"Mes:","\nError,mes no valido\n",1,12,2)==0 &&
                        utn_getNumero(&auxTrabajo.fecha.anio,"Anio:","\nError,anio no valido\n",1,3000,2)==0)
                        {
                            trabajos[indice].fecha.dia = auxTrabajo.fecha.dia;
                            trabajos[indice].fecha.mes = auxTrabajo.fecha.mes;
                            trabajos[indice].fecha.anio = auxTrabajo.fecha.anio;
                        }
                        break;
                }
            }
        }while(opcion!=4);
	}
	return retorno;
}

/**
 * \brief Actualiza una posicion del array
 * \param autos array de autos a ser actualizados
 * \param tamAuto limite del array de autos
 * \param trabajos array de trabajos a ser actualizados
 * \param tamTra limite del array de trabajos
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int bajaAuto(eAuto autos[],int tamAuto,eTrabajo trabajos[],int tamTra,int indice)
{
    int retorno=-1;

    if(autos!=NULL && tamAuto>=0 && trabajos!=NULL && tamTra>=0 && indice >=0)
    {
    	autos[indice].isEmpty=1;
    	for(int i=0;i<tamTra;i++)
        {
            if(trabajos[i].idAuto==autos[indice].id)
            {
                trabajos[i].isEmpty=1;
            }
        }
        retorno=0;
    }
    return retorno;
}










