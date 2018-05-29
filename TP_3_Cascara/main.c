#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "estructuras.h"



int main()
{
    char seguir='s';
    int opcion=0;
    EMovie lista[CANTIDAD];
    inicializarLista(lista);

    while(seguir=='s')
    {
        printf("1- Agregar pel%ccula\n",ii);
        printf("2- Borrar pel%ccula\n",ii);
        printf("3- Modificar pel%ccula\n",ii);
        printf("4- Generar p%cgina web\n",aa);
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
               break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
