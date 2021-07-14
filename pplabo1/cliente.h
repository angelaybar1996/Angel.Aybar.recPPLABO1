
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#define TAM_NOMBRE 50
#define TAM_LOCALIDAD 50


typedef struct{

    int id;
    char nombre[TAM_NOMBRE];
    char sexo;
    char localidad[TAM_LOCALIDAD];
}eCliente;



int cargarNombreCliente(int id,eCliente clientes[],int tamCli,char nombre[]);
int cargarLocalidadCliente(int id,eCliente clientes[],int tamCli,char localidad[]);
int mostrarClientes(eCliente clientes[],int tamCli);
int mostrarCliente(eCliente* unCliente);
int buscarCliente(eCliente clientes[],int tamCli, int idBuscado);


#endif // CLIENTE_H_INCLUDED
