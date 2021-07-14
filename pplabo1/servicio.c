#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "servicio.h"



/**
 * \brief Imprime el array de servicios
 * \param servicios Array de servicios a ser actualizados
 * \param tamSer Limite del array de servicios
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarServicios(eServicio servicios[], int tamSer)
{
    int retorno=-1;

    printf("\n     Lista de Servicios  \n");
    printf("--------------------------\n");
    printf("Id     Descripcion  Precio\n");
    printf("--------------------------\n");
    if(servicios!=NULL && tamSer>=0)
    {
        retorno=0;
        for(int i=0; i<tamSer; i++)
        {
            mostrarServicio(&servicios[i]);
        }
        printf("\n\n");
    }
    return retorno;
}

/**
 * \brief Imprime un servicio
 * \param unServicio Puntero al servicio que se busca imprimir
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarServicio(eServicio* unServicio)
{
    int retorno=-1;

    if(unServicio!=NULL)
    {
        retorno=0;
        printf("\n%d    %10s  %.2f\n",unServicio->id,unServicio->descripcion,unServicio->precio);
    }

    return retorno;
}

/**
 * \brief Busca un id y lo remplaza por su descripcion
 * \param id identificador del idServicio
 * \param servicios Array de servicios
 * \param tamSer Limite del array de servicios
 * \param desc Array donde se va a cargar la descripcion
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int cargarDescripcionServicio(int id,eServicio servicios[],int tamSer,char desc[])
{
    int retorno=-1;

    if(servicios!=NULL && tamSer>=0 && id>=20000 && id<=20003 && desc!=NULL)
    {
        for(int i=0;i<tamSer;i++)
        {
            if(servicios[i].id==id)
            {
                strcpy(desc,servicios[i].descripcion);
                break;
                retorno=0;
            }
        }
    }
    return retorno;
}


