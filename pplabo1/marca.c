#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "marca.h"
//#include "utn.h"



/**
 * \brief Busca un id y lo remplaza por su descripcion
 * \param id identificador de la marca
 * \param marcas Array de marcas
 * \param tamMar limite del array de marcas
 * \param desc Array donde se va a cargar la descripcion
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int cargarDescripcionMarca(int id,eMarca marcas[],int tamMar,char desc[])
{
    int retorno=-1;

    if(marcas!=NULL && tamMar>=0 && id>=1000 && id<=1004 && desc!=NULL)
    {
        for(int i=0;i<tamMar;i++)
        {
            if(marcas[i].id==id)
            {
                strcpy(desc,marcas[i].descripcion);
                break;
                retorno=0;
            }
        }
    }
    return retorno;
}

/**
 * \brief Imprime una marca
 * \param unMarca Puntero a la marca que se busca imprimir
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarMarca(eMarca* unMarca)
{
    int retorno=-1;

    if(unMarca!=NULL)
    {
        retorno=0;
        printf("\n%d    %10s \n",unMarca->id,unMarca->descripcion);
    }

    return retorno;
}

/**
 * \brief Imprime el array de marcas
 * \param marcas Array de marcas a ser actualizados
 * \param tamMar limite del array de marcas
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarMarcas(eMarca marcas[],int tamMar)
{
    int retorno=-1;

    printf("\nMARCAS\n\n");
    printf("ID          DESCRIPCION\n");
    if(marcas!=NULL && tamMar>=0)
    {
        retorno=0;
        for(int i=0; i<tamMar; i++)
        {
            mostrarMarca(&marcas[i]);
        }
        printf("\n\n");
    }
    return retorno;
}

/**
 * \brief busca un id en un array de marcas y devuelve la posicion en que se encuentra
 * \param marcas Array de marcas
 * \param tamMar Limite del array de marcas
 * \param idBuscado el valor buscado
 * \return Retorna la posicion en que se encuentra el idBuscado ó -1 (ERROR)
 */
int buscarMarca(eMarca marcas[],int tamMar, int idBuscado)
{
    int retorno=-1;
	int i;

	if(marcas!=NULL && tamMar>0 && idBuscado>=0 )
	{
		for(i=0;i<tamMar;i++)
		{
			if(marcas[i].id==idBuscado)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}



