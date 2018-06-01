#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"




int main()
{

    char seguir='s';
    int opcion=0;
    EMovie lista[CANTIDAD];
    inicializarLista(lista);
    leerArchivo(lista);

    while(seguir=='s')
    {
        system("cls");
        printf("\tBASE DE DATOS DE PELICULAS\n");
        printf("\t==========================\n");
        printf("\n\n\n\t1- Agregar pel%ccula\n",ii);
        printf("\t2- Borrar pel%ccula\n",ii);
        printf("\t3- Modificar pel%ccula\n",ii);
        printf("\t4- Generar p%cgina web\n",aa);
        printf("\t5- Listar pel%cculas\n",ii);
        printf("\t6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(lista);
                guardarArchivo(lista);
                break;
            case 2:
                borrarPelicula(lista);
                guardarArchivo(lista);
                break;
            case 3:
                modificarPelicula(lista);
                guardarArchivo(lista);
               break;
            case 4:
                system("cls");
                printf("Ingrese nombre del archivo .html: \n");
                fflush(stdin);
                char n[300]={};
                scanf("%s",n);
                crearHtml(lista,n);
               break;
            case 5:
                ListarPeliculas(lista);
                printf("\nPeliculas: %d\n\n",contarPeliculas(lista));
                system("pause");
                break;
            case 6:
                seguir = 'n';
                break;


        }
    }

    return 0;
}
