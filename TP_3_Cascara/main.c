#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"




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
        printf("5- Listar pel%cculas\n",ii);
        printf("6- Salir\n");
        printf("7- Listar\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(lista);
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
               break;
            case 5:
               break;
            case 6:
                seguir = 'n';
                break;
            case 7:
                ListarPeliculas(lista);
                break;
        }
    }

    return 0;
}
