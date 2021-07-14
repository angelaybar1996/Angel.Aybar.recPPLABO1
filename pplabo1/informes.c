#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "informes.h"

/**
 * \brief Menu de opciones de los informes
 * \param trabajos Array de trabajos
 * \param tamTra limite del array de trabajos
 * \param autos Array de autos
 * \param tamAuto limite del array de autos
 * \param servicios Array de servicios
 * \param tamSer limite del array de servicios
 * \param colores Array de colores
 * \param tamCol limite del array de colores
 * \param marcas Array de marcas
 * \param tamMar limite del array de marcas
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int menuInformes(eTrabajo trabajos[],int tamTra,eAuto autos[],int tamAuto,eServicio servicios[],int tamSer,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli,int nextAuto,int nextTrabajo)
{
    int retorno=-1;
    int opcion;

    if(trabajos!=NULL &&tamTra>0 && autos!=NULL &&tamAuto>0 && servicios!=NULL &&tamSer>0 && colores!=NULL &&tamCol>0 && marcas!=NULL &&tamMar>0 && clientes!=NULL &&tamCli>0 )
	{
        do
        {
            if(utn_getNumero(&opcion,
                             "\n\n----------------------------------------\n"
                                               "INFORMES"
                             "\n-------------------------------------------"
                             "\n1.Mostrar autos por color"
                             "\n2.Mostrar autos de una marca seleccionada"
                             "\n3.Mostrar los autos mas viejos"
                             "\n4.Listado de autos separados por marca"
                             "\n5.Cantidad de autos de un color y marca"
                             "\n6.Marcas mas elegidas por los clientes"
                             "\n7.Trabajos realizados a un auto"
                             "\n8.Importe total por los trabajos realizados a un auto"
                             "\n9.Infomar los autos que recibieron un servicio ingresado por el usuario"
                             "\n10.Servicios por fecha"
                             "\n11.Salir\n\n"
                             "Ingrese opcion:","\nError,opcion no valida\n",1,11,2)==0)
            {
                retorno=0;
                switch(opcion)
                {
                    case 1:
                        system("cls");
                        mostrarAutosColor(autos,tamAuto,colores,tamCol,marcas,tamMar,clientes,tamCli);
                        printf("\n\n");
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        marcaAuto(trabajos,tamTra,servicios,tamSer,autos,tamAuto,marcas,tamMar,colores,tamCol,clientes,tamCli);
                        printf("\n\n");
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        listarAutosMasViejos(trabajos,tamTra,servicios,tamSer,autos,tamAuto,colores,tamCol,marcas,tamMar,clientes,tamCli);
                        printf("\n\n");
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        mostrarAutosAllMarcas(autos,tamAuto,colores,tamCol,marcas,tamMar,clientes,tamCli);
                        printf("\n\n");
                        system("pause");
                        break;
                    case 5:
                        system("cls");
                        cantidadColoresMarcas(trabajos,tamTra,servicios,tamSer,autos,tamAuto,marcas,tamMar,colores,tamCol);
                        printf("\n\n");
                        system("pause");
                        break;
                    case 6:
                        system("cls");
                        cantidadAutoMarca(trabajos,tamTra,servicios,tamSer,autos,tamAuto,marcas,tamMar,colores,tamCol);
                        printf("\n\n");
                        system("pause");
                        break;
                    case 7:
                        system("cls");
                        trabajosAuto(trabajos,tamTra,servicios,tamSer,autos,tamAuto,colores,tamCol,marcas,tamMar,clientes,tamCli,nextAuto);
                        printf("\n\n");
                        system("pause");
                        break;
                    case 8:
                        system("cls");
                        totalTrabajosAuto(trabajos,tamTra,servicios,tamSer,autos,tamAuto,colores,tamCol,marcas,tamMar,clientes,tamCli,nextAuto);
                        printf("\n\n");
                        system("pause");
                        break;
                    case 9:
                        system("cls");
                        informarCantidadServicios(trabajos,tamTra,servicios,tamSer,autos,tamAuto,marcas,tamMar,colores,tamCol,clientes,tamCli);
                        printf("\n\n");
                        system("pause");
                        break;
                    case 10:
                        system("cls");
                        listarTotalServiciosFecha(trabajos,tamTra,servicios,tamSer,autos,tamAuto,marcas,tamMar,colores,tamCol,nextAuto);
                        printf("\n\n");
                        system("pause");
                        break;
                }
            }
        }while(opcion!=11);
	}
    return retorno;
}

/**
 * \brief Muestra los autos por color
 * \param autos Array de autos
 * \param tamAuto limite del array de autos
 * \param colores Array de colores
 * \param tamCol limite del array de colores
 * \param marcas Array de marcas
 * \param tamMar limite del array de marcas
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarAutosColor(eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli)
{
    int retorno=-1;
    int idColor;
    int indice;
    int flag=0;

    if(autos !=NULL &&tamAuto>0 && colores!=NULL &&tamCol>0 && marcas!=NULL &&tamMar>0 && colores!=NULL &&tamCli>0 )
	{
	    if( mostrarColores(colores,tamCol)==0 &&
	    utn_getNumero(&idColor,"Ingrese id del color:",
                   "\nError,color no valido\n",5000,5004,2)==0)
	    {
	        indice=buscarColor(colores,tamCol,idColor);

            printf("                      \nCOLOR:%s\n",colores[indice].descripcion);
            printf("--------------------------------------------------------------------------\n");
            printf("Id         Patente             Marca                Color        Modelo   \n");
            printf("--------------------------------------------------------------------------\n");
	        for(int i=0;i<tamAuto;i++)
            {
                if(autos [i].idColor==idColor  && autos[i].isEmpty==0)
                {
                   mostrarAuto(autos[i],marcas,tamMar,colores,tamCol,clientes,tamCli);
                   flag=1;
                }
            }
            if(flag==0)
            {
                printf("\nNo hay autos con este color\n");
            }
	    }
	    retorno=0;
	}
	return retorno;
}

/**
 * \brief Muestra los colores con sus autos
 * \param autos Array de autos
 * \param tamAuto limite del array de autos
 * \param colores Array de colores
 * \param tamCol limite del array de colores
 * \param marcas Array de marcas
 * \param tamMar limite del array de marcas
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarAutosAllMarcas(eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli)
{
    int retorno=-1;
    int flag[]={0,0,0,0,0};

    if(autos !=NULL &&tamAuto>0 && colores!=NULL &&tamCol>0 && marcas!=NULL &&tamMar>0 && clientes!=NULL &&tamCli>0 )
	{
	    for(int i=0;i<tamMar;i++)
        {
            printf("                        \nMARCA: %s\n",marcas[i].descripcion);
            printf("---------------------------------------------------------------------------------\n");
            printf("Id         Patente             Marca                Color        Modelo    Cliente\n");
            printf("---------------------------------------------------------------------------------\n");
            for(int j=0;j<tamAuto;j++)
            {
                if(autos[j].idMarca==marcas[i].id  && autos[j].isEmpty==0)
                {
                   if(mostrarAuto(autos[j],marcas,tamMar,colores,tamCol,clientes,tamCli)==0)
                   {
                      flag[i]=1;
                   }
                }
            }
            if(flag[i]==0)
            {
             printf("\nNo hay autos con esta marca\n");
            }
        }
         retorno=0;
	}
	return retorno;
}

/**
 * \brief Muestra los autos mas viejos
 * \param trabajos Array de trabajos
 * \param tamTra limite del array de trabajos
 * \param servicios Array de servicios
 * \param tamSer limite del array de servicios
 * \param autos Array de autos
 * \param tamAuto limite del array de autos
 * \param colores Array de colores
 * \param tamCol limite del array de colores
 * \param marcas Array de marcas
 * \param tamMar limite del array de marcas
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int listarAutosMasViejos(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli)
{
    int retorno=-1;
    int masViejo=0;

    if(trabajos!=NULL && tamTra>=0 && servicios!=NULL && tamSer>=0 && autos!=NULL && tamAuto>=0 && colores!=NULL && tamCol>=0  && marcas!=NULL && tamMar>=0 && clientes!=NULL && tamCli>=0)
	{
	    for(int i=0;i<tamAuto;i++)
        {
            if(i ==0 || autos[i].modelo<masViejo)
            {
                masViejo=autos[i].modelo;
            }
        }

        for(int j=0;j<tamAuto;j++)
        {
            if(autos[j].modelo==masViejo)
            {
                mostrarAuto(autos[j],marcas,tamMar,colores,tamCol,clientes,tamCli);
            }
        }
	    retorno=0;
	}
	return retorno;
}

/**
 * \brief Informa todos los trabajos de un auto
 * \param trabajos Array de trabajos
 * \param tamTra limite del array de trabajos
 * \param servicios Array de servicios
 * \param tamSer limite del array de servicios
 * \param autos Array de autos
 * \param tamAuto limite del array de autos
 * \param colores Array de colores
 * \param tamCol limite del array de colores
 * \param marcas Array de marcas
 * \param tamMar limite del array de marcas
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int trabajosAuto(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli,int nextAuto)
{
    int retorno=-1;
    int idAuto;

    if(trabajos!=NULL && tamTra>=0 && servicios!=NULL && tamSer>=0 && autos!=NULL && tamAuto>=0 && colores!=NULL && tamCol>=0  && marcas!=NULL && tamMar>=0 && clientes!=NULL && tamCli>=0)
    {
        mostrarAutos(autos,tamAuto,marcas,tamMar,colores,tamCol,clientes,tamCli);
        if(utn_getNumero(&idAuto,"\nIngrese id del auto:","\nError, id no valido",80000,nextAuto,4)==0 &&
           buscarAutoId(autos,tamAuto,idAuto)!=-1)
        {
            printf("\nTrabajos de un Auto");
            printf("\n----------------------------------------------------------------");
            printf("\nId             Patente          Servicio        Fecha     ");
            printf("\n----------------------------------------------------------------");
            for(int i=0;i<tamTra;i++)
            {
                if(trabajos[i].isEmpty==0 && trabajos[i].idAuto==idAuto)
                {
                    mostrarTrabajo(&trabajos[i],autos,tamAuto,servicios,tamSer,marcas,tamMar,colores,tamCol,nextAuto);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

/**
 * \brief Informa el total a pagar de todos los trabajos de un auto
 * \param trabajos Array de trabajos
 * \param tamTra limite del array de trabajos
 * \param servicios Array de servicios
 * \param tamSer limite del array de servicios
 * \param autos Array de autos
 * \param tamAuto limite del array de autos
 * \param colores Array de colores
 * \param tamCol limite del array de colores
 * \param marcas Array de marcas
 * \param tamMar limite del array de marcas
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */

int totalTrabajosAuto(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli,int nextAuto)
{
   int retorno=-1;
   int idAuto;
   float total=0;

    if(trabajos!=NULL && tamTra>=0 && servicios!=NULL && tamSer>=0 && autos!=NULL && tamAuto>=0 && colores!=NULL && tamCol>=0  && marcas!=NULL && tamMar>=0 && clientes!=NULL && tamCli>=0)
    {

        mostrarAutos(autos,tamAuto,marcas,tamMar,colores,tamCol,clientes,tamCli);
        if(utn_getNumero(&idAuto,
                                 "\nIngrese id del auto:",
                                 "\nError, id no valido",80000,nextAuto,4)==0 &&
           buscarAutoId(autos,tamAuto,idAuto)!=-1)
        {
             printf("\nTotal a pagar de los trabajos de un auto\n");
             printf("--------------------------------------------");

            for(int i=0;i<tamTra;i++)
            {
                if(trabajos[i].isEmpty==0 && trabajos[i].idAuto==idAuto)
                {
                    for(int j=0;j<tamSer;j++)
                    {
                        if(trabajos[i].idServicio==servicios[j].id)
                        {
                            total=total+servicios[j].precio;
                        }
                    }
                }
            }
            retorno=0;
            printf("\n\nTotal a pagar:$ %.2f",total);
        }
    }
    return retorno;
}

/**
 * \brief Informa la cantidad de servicios realizados por fecha
 * \param trabajos Array de trabajos
 * \param tamTra limite del array de trabajos
 * \param servicios Array de servicios
 * \param tamSer limite del array de servicios
 * \param autos Array de autos
 * \param tamAuto limite del array de autos
 * \param colores Array de colores
 * \param tamCol limite del array de colores
 * \param marcas Array de marcas
 * \param tamMar limite del array de marcas
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int listarTotalServiciosFecha(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol,int nextAuto)
{
    int retorno=-1;
    eFecha fechaAux;
    int contador[]={0,0,0,0,0};

    if(trabajos!=NULL && tamTra>=0 && servicios!=NULL && tamSer>=0 && autos!=NULL && tamAuto>=0 && colores!=NULL && tamCol>=0  && marcas!=NULL && tamMar>=0)
    {
        printf("\nServicios por fecha\n");
        printf("-----------------------");

        if(utn_getNumero(&fechaAux.dia,
                                 "\nIngrese fecha"
                                 "\nDia:",
                                 "\nError, dia no validado",1,31,4)==0 &&
           utn_getNumero(&fechaAux.mes,
                                 "Mes:",
                                 "\nError, mes no validado",1,12,4)==0 &&
           utn_getNumero(&fechaAux.anio,
                                 "Anio:",
                                 "\nError, anio no validado",1,3000,4)==0)

        {
            printf("\n----------------------------------------------------------------");
            printf("\nId             Patente          Servicio        Fecha   ");
            printf("\n----------------------------------------------------------------");
            for(int i=0;i<tamTra;i++)
            {
                for(int j=0;j<tamSer;j++)
                {
                    if( trabajos[i].isEmpty==0 &&
                        trabajos[i].idServicio==servicios[j].id &&
                        trabajos[i].fecha.dia==fechaAux.dia &&
                        trabajos[i].fecha.mes==fechaAux.mes &&
                        trabajos[i].fecha.anio==fechaAux.anio)
                    {
                        mostrarTrabajo(&trabajos[i],autos,tamAuto,servicios,tamSer,marcas,tamMar,colores,tamCol,nextAuto);
                        contador[j]++;
                    }
                }
            }
            printf("\n\n");
            for(int i=0;i<tamSer;i++)
            {
                printf("\ncantidad de %s: %d",servicios[i].descripcion,contador[i]);
            }
            printf("\n\n");
        }
    }
    return retorno;
}

/**
 * \brief El usuario ingresa un color y una marca y se informa cuantos autos hay de ese color y esa marca
 * \param trabajos Array de trabajos
 * \param tamTra limite del array de trabajos
 * \param servicios Array de servicios
 * \param tamSer limite del array de servicios
 * \param autos Array de autos
 * \param tamAuto limite del array de autos
 * \param colores Array de colores
 * \param tamCol limite del array de colores
 * \param marcas Array de marcas
 * \param tamMar limite del array de marcas
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int cantidadColoresMarcas(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol)
{
    int retorno=-1;
    int idColor;
    int idMarca;
    int contador=0;

    if(trabajos!=NULL && tamTra>=0 && servicios!=NULL && tamSer>=0 && autos!=NULL && tamAuto>=0 && colores!=NULL && tamCol>=0  && marcas!=NULL && tamMar>=0)
    {
        mostrarColores(colores,tamCol);
        if(utn_getNumero(&idColor,"\nIngrese id del color:","\nError,id no valido",5000,5004,2)==0)
        {
            mostrarMarcas(marcas,tamMar);
            if(utn_getNumero(&idMarca,"\nIngrese id de la marca:","\nError,id no valido",1000,1004,2)==0)
            {
                for(int j=0;j<tamAuto;j++)
                {
                    if(autos[j].isEmpty==0 && autos[j].idColor==idColor && autos[j].idMarca==idMarca)
                    {
                           contador++;
                    }
                }
                printf("\n\nHay %d autos de ese color y esa marca\n",contador);
                printf("\n\n");
                retorno=0;
            }
        }
    }
    return retorno;
}

/**
 * \brief Informa la marca que mas hay y cuantos son
 * \param trabajos Array de trabajos
 * \param tamTra limite del array de trabajos
 * \param servicios Array de servicios
 * \param tamSer limite del array de servicios
 * \param autos Array de autos
 * \param tamAuto limite del array de autos
 * \param colores Array de colores
 * \param tamCol limite del array de colores
 * \param marcas Array de marcas
 * \param tamMar limite del array de marcas
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int cantidadAutoMarca(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol)
{
    int retorno=-1;
    int contador[tamCol];
    int mayor=0;

    if(trabajos!=NULL && tamTra>=0 && servicios!=NULL && tamSer>=0 && autos!=NULL && tamAuto>=0 && colores!=NULL && tamCol>=0  && marcas!=NULL && tamMar>=0)
    {
       for(int i=0;i<tamMar;i++)
       {
           contador[i]=0;
            for(int j=0;j<tamAuto;j++)
            {
                if(autos[j].isEmpty==0 && marcas[i].id==autos[j].idMarca)
                {
                    contador[i]++;
                }
            }
            printf("\nMarca %s: %d",marcas[i].descripcion,contador[i]);
            if(i==0 || contador[i]>mayor)
            {
                mayor=contador[i];
            }
       }
       for(int i=0;i<tamMar;i++)
       {
           if(contador[i]==mayor)
           {
               printf("\nHay mas autos marca %s ",marcas[i].descripcion);
               printf("\n\n");
           }
       }
       retorno=0;
    }
    return retorno;
}

/**
 * \brief Se ingresa un servicio y se informa cuantos autos tuvieron ese servicio
 * \param trabajos Array de trabajos
 * \param tamTra limite del array de trabajos
 * \param servicios Array de servicios
 * \param tamSer limite del array de servicios
 * \param autos Array de autos
 * \param tamAuto limite del array de autos
 * \param colores Array de colores
 * \param tamCol limite del array de colores
 * \param marcas Array de marcas
 * \param tamMar limite del array de marcas
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int informarCantidadServicios(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli)
{
    int retorno=-1;
    int idServicio;

    if(trabajos!=NULL && tamTra>=0 && servicios!=NULL && tamSer>=0 && autos!=NULL && tamAuto>=0 && colores!=NULL && tamCol>=0  && marcas!=NULL && tamMar>=0 && clientes!=NULL && tamCli>=0)
    {
        mostrarServicios(servicios,tamSer);
        if(utn_getNumero(&idServicio,"\nIngrese id del servicio:","\nError,id no valido",20000,20003,2)==0)
        {
            for(int i=0;i<tamAuto;i++)
            {
                if(autos[i].isEmpty==0)
                {
                    for(int j=0;j<tamTra;j++)
                    {
                        if(trabajos[j].idAuto==autos[i].id && trabajos[j].isEmpty==0 && trabajos[j].idServicio==idServicio)
                        {
                            printf("\n\nFECHA %d/%d/%d",trabajos[j].fecha.dia,trabajos[j].fecha.mes,trabajos[j].fecha.anio);
                            printf("\n--------------------------------------------------------------------------------");
                            printf("\nId           Patente             Marca               Color           Modelo     Cliente");
                            printf("\n--------------------------------------------------------------------------------");
                            mostrarAuto(autos[i],marcas,tamMar,colores,tamCol,clientes,tamCli);

                        }
                    }
                }
            }
        }
    }
    return retorno;
}

/**
 * \brief Muestra los autos por marca seleccionada
 * \param trabajos Array de trabajos
 * \param tamTra limite del array de trabajos
 * \param servicios Array de servicios
 * \param tamSer limite del array de servicios
 * \param autos Array de autos
 * \param tamAuto limite del array de autos
 * \param colores Array de colores
 * \param tamCol limite del array de colores
 * \param marcas Array de marcas
 * \param tamMar limite del array de marcas
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int marcaAuto(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamSer,eAuto autos[],int tamAuto,eMarca marcas[],int tamMar,eColor colores[],int tamCol,eCliente clientes[],int tamCli)
{
    int retorno=-1;
    int idMarca;

    if(trabajos!=NULL && tamTra>=0 && servicios!=NULL && tamSer>=0 && autos!=NULL && tamAuto>=0 && colores!=NULL && tamCol>=0  && marcas!=NULL && tamMar>=0 && clientes!=NULL && tamCli>=0)
	{
	    mostrarMarcas(marcas,tamMar);
	    if(utn_getNumero(&idMarca,"\nIngrese id de una marca:","\nError,el id no es valido",1000,1004,2)==0)
        {
            printf("--------------------------------------------------------------------------------\n");
            printf("Id           Patente             Marca               Color           Modelo      Cliente\n");
            printf("--------------------------------------------------------------------------------\n");
            for(int j=0;j<tamAuto;j++)
            {
                if(autos[j].isEmpty==0 && autos[j].idMarca==idMarca)
                {
                    mostrarAuto(autos[j],marcas,tamMar,colores,tamCol,clientes,tamCli);
                }
            }

        }
	retorno=0;
	}
	return retorno;
}

