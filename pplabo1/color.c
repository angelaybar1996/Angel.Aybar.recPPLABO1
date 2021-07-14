#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"
//#include "utn.h"



/**
 * \brief Busca un id y lo remplaza por su descripcion
 * \param id identificador del color
 * \param colores Array de colores
 * \param tamCol limite del array de colores
 * \param desc Array donde se va a cargar la descripcion
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int cargarDescripcionColor(int id,eColor colores[],int tamCol,char desc[])
{
    int retorno=-1;

    if(colores!=NULL && tamCol>=0 && id>=5000 && id<=5004)
    {
        for(int i=0;i<tamCol;i++)
        {
            if(colores[i].id==id)
            {
                strcpy(desc,colores[i].descripcion);
                break;
                retorno=0;
            }
        }
    }
    return retorno;
}

/**
 * \brief Imprime un color
 * \param unColor Puntero al color que se busca imprimir
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarColor(eColor* unColor)
{
    int retorno=-1;

    if(unColor!=NULL)
    {
        retorno=0;
        printf("\n%d    %10s \n",unColor->id,unColor->descripcion);
    }

    return retorno;
}

/**
 * \brief Imprime el array de colores
 * \param colores Array de colores a ser actualizados
 * \param tamCol limite del array de colores
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarColores(eColor colores[],int tamCol)
{
    int retorno=-1;

    printf("\nCOLORES\n\n");
    printf("ID          DESCRIPCION\n");
    if(colores!=NULL && tamCol>=0)
    {
        retorno=0;
        for(int i=0; i<tamCol; i++)
        {
            mostrarColor(&colores[i]);
        }
        printf("\n\n");
    }
    return retorno;
}

/**
 * \brief busca un id en un array de colores y devuelve la posicion en que se encuentra
 * \param  colores Array de colores
 * \param tamCol Limite del array de colores
 * \param idBuscado el valor buscado
 * \return Retorna la posicion en que se encuentra el idBuscado ó -1 (ERROR)
 */
int buscarColor(eColor colores[],int tamCol, int idBuscado)
{
    int retorno=-1;
	int i;

	if(colores!=NULL && tamCol>0 && idBuscado>=0 )
	{
		for(i=0;i<tamCol;i++)
		{
			if(colores[i].id==idBuscado)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}



