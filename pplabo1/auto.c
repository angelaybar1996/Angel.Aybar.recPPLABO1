#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auto.h"



/**
 * \brief Inicializa el array de autos
 * \param  autos array de autos a ser actualizados
 * \param tamAuto limite del array de autos
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int inicializarAutos(eAuto autos[], int tamAuto)
{
    int retorno=-1;

    if(autos!=NULL && tamAuto >0)
    {
        retorno=0;
        for(int i=0; i<tamAuto; i++)
        {
            autos[i].isEmpty=1;
        }
    }
    return retorno;
}

/**
 * \brief busca la primer posicion vacia
 * \param  autos array de autos
 * \param tamAuto limite del array de autos
 * \return Retorna el indice de la posicion vacia ó -1 (ERROR)
 */
int buscarLibreAuto(eAuto autos[],int tamAuto)
{
    int retorno=-1;
    if(autos!=NULL && tamAuto>=0)
    {
        for(int i=0; i<tamAuto; i++)
        {
            if(autos[i].isEmpty)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief busca una patente en un array y devuelve la posicion en que se encuentra
 * \param autos array de autos
 * \param tamAuto limite del array de autos
 * \param patente el char buscado
 * \return Retorna la posicion en que se encuentra la patente ó -1 (ERROR)
 */
int buscarAuto(eAuto autos[],int tamAuto, char patente[])
{
    int retorno=-1;
	int i;

	if(autos!=NULL &&tamAuto>0)
	{
		retorno=0;
		for(i=0;i<tamAuto;i++)
		{
			if(strcmp(autos[i].patente,patente)==0 && autos[i].isEmpty==0)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief busca un id en un array y devuelve la posicion en que se encuentra
 * \param autos array de autos
 * \param tamAuto limite del array de autos
 * \param id identificador a buscar
 * \return Retorna la posicion en que se encuentra el identificador ó -1 (ERROR)
 */
int buscarAutoId(eAuto autos[],int tamAuto, int id)
{
    int retorno=-1;
	int i;

	if(autos!=NULL &&tamAuto>0)
	{
		retorno=0;
		for(i=0;i<tamAuto;i++)
		{
			if(autos[i].id==id && autos[i].isEmpty==0)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Imprime los datos de un auto
 * \param unAuto Puntero al auto que se busca imprimir
 * \param marcas Array de marcas
 * \param tamMar Limite del array de marcas
 * \param colores Array de colores
 * \param tamCol Limite del array de colores
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarAuto(eAuto unAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli)
{
    int retorno=-1;
    char desMarca[20];
    char desColor[20];
    char nombre[20];

    if(marcas!=NULL && tamMar>=0 && colores!=NULL && tamCol>=0)
    {
    	cargarDescripcionColor(unAuto.idColor, colores, tamCol, desColor);//bien
    	cargarDescripcionMarca(unAuto.idMarca, marcas, tamMar, desMarca);//bien
    	cargarNombreCliente(unAuto.idCliente,clientes,tamCli,nombre);//bien

       retorno=0;
     //printf("Id    Patente        Marca        Color     Modelo        Cliente\n");
       printf("\n%d   %10s          %10s          %10s         %d    %s\n",
       unAuto.id,
       unAuto.patente,
       desMarca,
       desColor,
       unAuto.modelo,
       nombre);

    }

    return retorno;
}

/**
 * \brief Imprime el array de autos
 * \param autos Array de autos a ser actualizados
 * \param tamAuto Limite del array de autos
 * \param marcas Array de marcas a ser actualizados
 * \param tamMar Limite del array de marcas
 * \param colores Array de colores a ser actualizados
 * \param tamCol Limite del array de colores
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarAutos(eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli)
{
    int retorno=-1;
    int flag=1;

    printf("\n                Listado de Autos\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("Id           Patente             Marca               Color           Modelo     Cliente\n");
    printf("---------------------------------------------------------------------------------------\n");
    if(autos!=NULL && tamAuto>0 && marcas!=NULL && tamMar>=0 && colores!=NULL && tamCol>=0 && clientes!=NULL && tamCli>=0)
    {
        retorno=0;
        for(int i=0; i<tamAuto; i++)
        {
            if(autos[i].isEmpty==0)
            {
              mostrarAuto(autos[i],marcas,tamMar,colores,tamCol,clientes,tamCli);
              flag=0;
            }
        }
        if(flag)
        {
                printf("\nNo hay autos que mostrar\n");
        }
        printf("\n\n");
    }
    return retorno;
}

/**
 * \brief Da de alta un auto en una posicion del array
 * \param autos Array de autos a ser actualizados
 * \param tamAuto Limite del array de autos
 * \param marcas Array de marcas a ser actualizados
 * \param tamMar Limite del array de marcas
 * \param colores Array de colores a ser actualizados
 * \param tamCol Limite del array de colores
 * \param pNextId Puntero identificador a ser asignado al auto
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int altaAuto(eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli,int* pNextId)
{
    int retorno=-1;
    int indice;
    eAuto auxAuto;

    if(autos!=NULL && tamAuto>=0 && marcas!=NULL && tamMar>=0 &&colores!=NULL && tamCol>=0 && pNextId!=NULL)
    {
        printf("\nALTA AUTO\n");
        printf("\nID: %d\n",*pNextId);
        indice=buscarLibreAuto(autos,tamAuto);

        if(indice==-1)
        {
            printf("\nNo hay lugar para mas autos\n");
        }
        else
        {
            mostrarMarcas(marcas, tamMar);
            if(utn_getNumero(&auxAuto.idMarca,
                                     "\nIngrese id de la marca:",
                                     "\nError, id no valida",1000,1004,4)==0 &&
               buscarMarca(marcas, tamMar, auxAuto.idMarca)!=-1)
            {
            	mostrarColores(colores, tamCol);
            	if(utn_getNumero(&auxAuto.idColor,
										 "\nIngrese id del color:",
										 "\nError, id no valido",5000,5004,4)==0 &&
				   buscarColor(colores, tamCol,auxAuto.idColor)!=-1)
            	{
            		if(utn_getNumero(&auxAuto.modelo,  "\nIngrese modelo(anio):",  "\nError, modelo no valido", 1, 3000, 4)==0 &&
            		utn_getTexto(auxAuto.patente, TAM_PAT, "\nIngrese patente:", "\nError, patente no valida", 4)==0)
            		{
            		    mostrarClientes(clientes,tamCli);
            		    if(utn_getNumero(&auxAuto.idCliente,
										 "\nIngrese id del cliente:",
										 "\nError, id no valido",3000,3009,4)==0 &&
                                        buscarCliente(clientes,tamCli,auxAuto.idCliente)!=-1)
                        {
                            auxAuto.isEmpty=0;
                            auxAuto.id=*pNextId;
                            autos[indice] = auxAuto;
                            (*pNextId)++;
                            retorno=0;
                        }
            		}
            	}
             }
        }
    }
    return retorno;
}

/**
 * \brief Menu de opciones de los datos del auto a modificar
 * \param  autos array de autos a ser actualizados
 * \param tamAuto limite del array de autos
 * \param marcas Array de marcas a ser actualizados
 * \param tamMar Limite del array de marcas
 * \param colores Array de colores a ser actualizados
 * \param tamCol Limite del array de colores
 * \param indice Posicion recibida
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int menuModificarAuto(eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli,int indice)
{
    int retorno=-1;
    int opcion;
    eAuto auxAutos;

	if(autos!=NULL && tamAuto>0 && indice<tamAuto && marcas!=NULL && tamMar>0 && colores!=NULL && tamCol>0 && autos[indice].isEmpty==0)
	{
	    do
        {
            if(utn_getNumero(&opcion,
                             "***Modificar Auto***\n\n"
                             "\n1.Modificar color"
                             "\n2.Modificar modelo"
                             "\n3.Salir\n\n"
                             "Ingrese opcion:","\nError,opcion no valida\n",1,3,2)==0)
            {
                retorno=0;
                switch(opcion)
                {
                    case 1:
                        mostrarColores(colores,tamCol);
                        if(utn_getNumero(&auxAutos.idColor,"\nIngrese id del color:","\nError,idColor no valido",5000,5004,1)==0)
                        {
                            autos[indice].idColor=auxAutos.idColor;
                            printf("\nModificacion realizada con exito\n");
                        }
                        break;
                    case 2:
                        if(utn_getNumero(&auxAutos.modelo,"\nIngrese modelo:","\nError,modelo no valido",1,3000,1)==0)
                        {
                            autos[indice].modelo=auxAutos.modelo;
                            printf("\nModificacion realizada con exito\n");
                        }
                        break;
                }
            }
        }while(opcion!=3);
	}
	return retorno;
}

/**
 * \brief Busca un id y lo remplaza por su descripcion
 * \param id identificador del auto
 * \param autos Array de autos
 * \param tamAuto limite del array de autos
 * \param desc Array donde se va a cargar la descripcion
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int cargarDescripcionAuto(int id,eAuto autos[],int tamAuto,char desc[],int nextAuto)
{
     int retorno=-1;

    if(autos!=NULL && tamAuto>=0 && id>=80000 && id<=nextAuto && desc!=NULL)
    {
        for(int i=0;i<tamAuto;i++)
        {
            if(autos[i].id==id)
            {
                strcpy(desc,autos[i].patente);
                break;
                retorno=0;
            }
        }
    }
    return retorno;
}

/**
 * \brief ordena el array de autos agrupado por marca y patente
 * \param  autos array de autos a ser actualizados
 * \param tamAuto limite del array de autos
 * \param marcas Array de marcas a ser actualizados
 * \param tamMar Limite del array de marcas
 * \param colores Array de colores a ser actualizados
 * \param tamCol Limite del array de colores
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */

int ordenarMarcaPatente(eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[], int tamCol)
{
    int retorno=-1;
    eAuto auxAuto;

    if(autos!=NULL && tamAuto>0 && marcas!=NULL && tamMar>0 && colores!=NULL && tamCol>0)
	{
        retorno=0;
        for(int i=0; i<tamAuto-1; i++)
        {
            for(int j=i+1; j<tamAuto; j++)
            {
                if(autos[i].idMarca>autos[j].idMarca || (autos[i].idMarca==autos[j].idMarca && strcmp(autos[i].patente,autos[j].patente)>0) )
                {
                    auxAuto=autos[i];
                    autos[i]=autos[j];
                    autos[j]=auxAuto;
                }
            }
        }
	}
    return retorno;
}



