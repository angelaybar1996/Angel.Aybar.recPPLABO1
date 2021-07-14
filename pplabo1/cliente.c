#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"




/**
 * \brief Busca un id y lo remplaza por su nombre
 * \param id identificador del cliente
 * \param cliente Array de clientes
 * \param tamCli limite del array de clientes
 * \param nombre Array donde se va a cargar el nombre
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int cargarNombreCliente(int id,eCliente clientes[],int tamCli,char nombre[])
{
    int retorno=-1;

    if(clientes!=NULL && tamCli>=0 && id>=3000 && id<=3009)
    {
        for(int i=0;i<tamCli;i++)
        {
            if(clientes[i].id==id)
            {
                strcpy(nombre,clientes[i].nombre);
                break;
                retorno=0;
            }
        }
    }
    return retorno;
}

/**
 * \brief Imprime un cliente
 * \param unCliente Puntero al cliente que se busca imprimir
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarCliente(eCliente* unCliente)
{
    int retorno=-1;

    if(unCliente!=NULL)
    {
        retorno=0;
        printf("\n%d    %10s   %c\n",unCliente->id,unCliente->nombre,unCliente->sexo);
    }

    return retorno;
}

/**
 * \brief Imprime el array de clientes
 * \param clientes Array de clientes a ser actualizados
 * \param tamCli limite del array de clientes
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarClientes(eCliente clientes[],int tamCli)
{
    int retorno=-1;

    printf("\nCLIENTES\n\n");
    printf("ID          NOMBRE  SEXO\n");
    if(clientes!=NULL && tamCli>=0)
    {
        retorno=0;
        for(int i=0; i<tamCli; i++)
        {
            mostrarCliente(&clientes[i]);
        }
        printf("\n\n");
    }
    return retorno;
}

/**
 * \brief busca un id en un array de clientes y devuelve la posicion en que se encuentra
 * \param clientes Array de clientes
 * \param tamCli Limite del array de clientes
 * \param idBuscado el valor buscado
 * \return Retorna la posicion en que se encuentra el idBuscado ó -1 (ERROR)
 */
int buscarCliente(eCliente clientes[],int tamCli, int idBuscado)
{
    int retorno=-1;
	int i;

	if(clientes!=NULL && tamCli>0 && idBuscado>=0 )
	{
		for(i=0;i<tamCli;i++)
		{
			if(clientes[i].id==idBuscado)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

