
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int buscaEstadoLibre (EMovie lista[])
{
    int i=0;
    while (lista[i].estado == 1 && i < CANTIDAD)
    {
        i++;
        if (i==20)
        {
            return -1;
        }
    }
    return i;
}


void inicializarLista(EMovie lista[])
{
    for(int i=0;i<CANTIDAD;i++)
    {
        lista[i].estado = 0;
    }

}
