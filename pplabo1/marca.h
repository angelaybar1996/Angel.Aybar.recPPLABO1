#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED
#define DESC_TAM 19

typedef struct
{
    int id;//comienza en 1000
    char descripcion[DESC_TAM];
}eMarca;

int cargarDescripcionMarca(int id,eMarca marcas[],int tamMar,char desc[]);
int mostrarMarcas(eMarca marcas[],int tamMar);
int mostrarMarca(eMarca* unMarca);
int buscarMarca(eMarca marcas[],int tamMar, int idBuscado);

#endif // MARCA_H_INCLUDED
