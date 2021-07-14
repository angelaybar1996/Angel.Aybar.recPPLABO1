#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
#define DESC_TAM 19

typedef struct
{
    int id;//comienza en 5000
    char descripcion[DESC_TAM];
}eColor;

int cargarDescripcionColor(int id,eColor colores[],int tamCol,char desc[]);
int mostrarColores(eColor colores[],int tamCol);
int mostrarColor(eColor* unColor);
int buscarColor(eColor colores[],int tamCol, int idBuscado);

#endif // COLOR_H_INCLUDED
