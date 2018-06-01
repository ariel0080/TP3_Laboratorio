#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"



// FUNCIONES PARA TOMAR DATOS Y VALIDAR

int ValidarEntero(int min,int max,int dato)
{
    if((dato+1) > min && (dato-1) < max)
        {
            return dato;
        }
    else return -1;
}


int consulta(char* dato, int caracteres)
{
    if(dato!=NULL)
    {
        fflush(stdin);
        fgets(dato,caracteres,stdin);
    int largo=0;
    while (*(dato+largo)!='\n')
        {
        largo++;
        }
    *(dato+largo)='\0';
    return 0;
    }
    else return -1;
}


int stringAenteroPositivo(char* dato) // DEVUELVE EL ENTERO SI ESTA BIEN O -1 SI DA ERROR
{
    int a=0;

    while(isdigit(*(dato+a)))
    {
        a++;
        if(*(dato+a)=='\0') {return atoi(dato);}
    }

    return -1;
}
int pedirTitulo(EMovie* movie,int indice) //todas devuelven 0 si esta ok, -1 si hay error
{
    char aux[21];
    printf("\nIngrese t%ctulo de la pel%ccula: ",ii,ii);
    consulta(aux,50);
    if(set_EMovie_titulo(movie,aux,indice)==1){set_EMovie_titulo(movie,aux,indice);}
    else return 0;
}
int pedirGenero(EMovie* movie,int indice)
{
    char aux[21];
    printf("\nIngrese g%cnero de la pel%ccula: ",ee,ii);
    consulta(aux,50);
    if(set_EMovie_genero(movie,aux,indice)==1){set_EMovie_genero(movie,aux,indice);}
    else return 0;
}
int pedirDuracion(EMovie* movie,int indice)
{
    char aux[21];
    printf("\nIngrese duraci%cn de la pel%ccula: <0-300 mins>",oo,ii);
    consulta(aux,50);
    while(stringAenteroPositivo(aux)==-1 || ValidarEntero(0,300,stringAenteroPositivo(aux))==-1)
    {
        printf("\nNO INGRESO DURACION VALIDA <0-300>\n");
        printf("\nIngrese duraci%cn de la pel%ccula: <0-300 mins>",oo,ii);
        consulta(aux,50);
    }
   set_EMovie_duracion(movie,stringAenteroPositivo(aux),indice);
}
int pedirDescripcion(EMovie* movie,int indice)
{
    char aux[51];
    printf("\nIngrese descripci%cn de la pel%ccula: ",oo,ii);
    consulta(aux,51);
    if(set_EMovie_descripcion(movie,aux,indice)==1){set_EMovie_descripcion(movie,aux,indice);}
    else return 0;
}
int pedirPuntaje(EMovie* movie,int indice)
{
    char auxp[21];
    printf("\nIngrese puntaje de la pel%ccula: ",ii); // en cada validacion
    consulta(auxp,20);
    int p = stringAenteroPositivo(auxp);

    while(p==-1 || ValidarEntero(0,10,p)==-1)
    {
        printf("\nNO INGRESO UN PUNTAJE VALIDO <1-10>\n");
        printf("\nIngrese puntaje de la pel%ccula: ",ii); // en cada validacion
        consulta(auxp,20);
        p = stringAenteroPositivo(auxp);
    }
    set_EMovie_puntaje(movie,p,indice);

}
int pedirLink(EMovie* movie,int indice)
{
    char aux[51];
    printf("\nIngrese link de la im%cgen de la pel%ccula: ",aa,ii);
    consulta(aux,50);
    if(set_EMovie_linkImagen(movie,aux,indice)==1){set_EMovie_linkImagen(movie,aux,indice);}
    else return 0;

}

// INICIALIZAR Y BUSQUEDA DE ESTADO LIBRE

int buscaEstadoLibre (EMovie* lista)
{
    int i=0;
    while (get_EMovie_estado(lista,i) && i < CANTIDAD)
    {
        i++;
        if (i==CANTIDAD)
        {
            return -1;
        }
    }
    return i;
}


void inicializarLista(EMovie* lista)
{
    for(int i=0;i<CANTIDAD;i++)
    {
        set_EMovie_estado(lista,0,i);
    }

}

int hayRegistro(EMovie* lista) // recorre la estructura en busca de registros validos, 1 si hay, 0 si esta vacia
{
    int i=0;
    while (!get_EMovie_estado(lista,i) && i < CANTIDAD)
    {
        i++;
        if (i==CANTIDAD)
        {
            return 0;
        }
    }
    return 1;
}

int buscarxId(EMovie* movie,int id)
{
    for(int a=0;a<CANTIDAD;a++)
    {
        int id_a=get_EMovie_id(movie,a);

        if(id_a==id){return a;}
    }

    printf("\n\n EL ID INGRESADO NO ES VALIDO. NO SE BORRARA NINGUN REGISTRO\n");
    system("pause");
    return -1;
}


//SETTERS

int set_EMovie_titulo(EMovie* lista, char* titulo,int posicion)
{
    if(lista!=NULL)
    {
        strcpy((lista+posicion)->titulo,titulo);
        return 1;
    }
    return 0;
}
int set_EMovie_genero(EMovie* lista, char* genero, int posicion)
{
    if(lista!=NULL)
    {
        strcpy((lista+posicion)->genero, genero);
        return 1;
    }
    return 0;
}
int set_EMovie_descripcion(EMovie* lista, char* descripcion, int posicion)
{
    if(lista!=NULL)
    {
        strcpy((lista+posicion)->descripcion, descripcion);
        return  1;
    }
    return 0;
}
int set_EMovie_linkImagen(EMovie* lista, char* linkImagen, int posicion)
{
    if(lista!=NULL)
    {
        strcpy((lista+posicion)->linkImagen, linkImagen);
        return  1;
    }
    return 0;
}
int set_EMovie_duracion(EMovie* lista, int duracion,int posicion)
{
    if(lista!=NULL)
    {
        (lista+posicion)->duracion = duracion;
        return  1;
    }
    return 0;
}
int set_EMovie_puntaje(EMovie* lista, int puntaje, int posicion)
{
    if(lista!=NULL)
    {
        (lista+posicion)->puntaje = puntaje;
        return 1;
    }
    return 0;
}
int set_EMovie_estado(EMovie* lista, int estado, int posicion)
{
    if(lista!=NULL)
    {
        (lista+posicion)->estado = estado;
        return  1;
    }
    return 0;
}
int set_EMovie_id(EMovie* lista, int id, int posicion)
{
    if(lista!=NULL)
    {
        (lista+posicion)->id = id;
        return 1;
    }
    return 0;
}


//GETTERS

void get_EMovie_linkImagen(EMovie* lista,int posicion, char* l)
{
    strcpy(l,(lista+posicion)->linkImagen);
}
void get_EMovie_genero(EMovie* lista,int posicion,char* g)
{

    strcpy(g,(lista+posicion)->genero);

}
void get_EMovie_descripcion(EMovie* lista, int posicion, char* d)
{

    strcpy(d,(lista+posicion)->descripcion);

}
void get_EMovie_titulo(EMovie* lista,int posicion,char* t)
{

    strcpy(t,(lista+posicion)->titulo);


}
int get_EMovie_duracion(EMovie* lista,int posicion)
{
    int dur;
    dur = (lista+posicion)->duracion;
    return dur;
}
int get_EMovie_puntaje(EMovie* lista,int posicion)
{
    int pun;
    pun = (lista+posicion)->puntaje;
    return pun;

}
int get_EMovie_estado(EMovie* lista,int posicion)
{
    int est;
    est = (lista+posicion)->estado;
    return est;
}
int get_EMovie_id(EMovie* lista, int posicion)
{
    int i;
    i = (lista+posicion)->id;
    return i;
}

//LISTAR PELICULAS

void ListarPeliculas(EMovie* movie)
{
    printf("\nTITULO\t\tGENERO\t\t\MIN\t\tCAL\t\tID\n");
    printf("\===================================================================\n\n");

    for(int i=0;i<CANTIDAD;i++)
    {
        if(get_EMovie_estado(movie,i)==1)
        {
            char t[30];
            char g[30];
            int du,pun,id;
            get_EMovie_titulo(movie,i,t);
            get_EMovie_genero(movie,i,g);



            printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\n",t,g,get_EMovie_duracion(movie,i),get_EMovie_puntaje(movie,i),get_EMovie_id(movie,i));

        }
    }
}

// FUNCIONES DEL MENU

int agregarPelicula(EMovie* movie)
{
    int indice;
    indice=buscaEstadoLibre(movie);
    if(indice!=-1)
    {
        pedirTitulo(movie,indice);
        pedirGenero(movie,indice);
        pedirDuracion(movie,indice);
        pedirDescripcion(movie,indice);
        pedirPuntaje(movie, indice);
        pedirLink(movie, indice);

        if(set_EMovie_estado(movie,1,indice)==1){set_EMovie_estado(movie,1,indice);}
            else return 0;

        if(set_EMovie_id(movie,100+indice,indice)==1){set_EMovie_id(movie,100+indice,indice);}
            else return 0;



    } else printf("\n\nLO SIENTO - NO HAY ESPACIO LIBRE EN MOMERIA PARA CARGAR OTRO REGISTRO. BORRE ALGUNO Y VUELVA A INTENTAR\n\n");

}

int borrarPelicula(EMovie* movie)
{
    // verificar que exita algo para borrar,sino no hacer nada

    if(hayRegistro(movie))
    {
        system("cls");
        char dato[10];
        int id;
        ListarPeliculas(movie);

        printf("\n\n\tIngrese id de pel%ccula a borrar: ",ii);
        consulta(dato,10);
        id = stringAenteroPositivo(dato);
        if(id!=-1 && ValidarEntero(0,2001,id)!=-1)
        {
            int indice = buscarxId(movie,id);
            if(indice!=-1){set_EMovie_estado(movie,0,indice);}
            else {printf("\nID INEXISTENTE\n");system("pause");return 0;}
        }else {printf("\n\nID INVALIDO\n");system("pause");}

    }
    else
    {
        printf("\nNO ES POSIBLE EJECUTAR LA ACCION REQUERIDA PORQUE NO HAY ELEMENTOS EN LA BASE DE DATOS\n\n");
        system("pause");
    }


}

int modificarPelicula(EMovie* movie)
{
    if(hayRegistro(movie))
    {
    system("cls");
    ListarPeliculas(movie);
    printf("\n\nIngrese id de pel%ccula a modificar: ",ii);
    char dato[10];
    int id;
    consulta(dato,10);
    id = stringAenteroPositivo(dato);
    if(id!=-1 && ValidarEntero(0,2001,id)!=-1)
        {
            int indice = buscarxId(movie,id);
            if(indice!=-1)
            {   int opcion;
                char salir = 'n';
                while(salir = 'n')
                {
                    system("cls");
                    printf("Ingrese campo a modificar:\n1-Titulo\n2-G%cnero\n3-Duraci%cn\n4-Descripci%cn\n5-Puntaje\n6-Link Imagen\n7-Salir",ee,oo,oo);
                    opcion=getch();
                    switch(opcion)
                    {
                    case 1:
                        pedirTitulo(movie,indice);
                    case 2:
                        pedirGenero(movie,indice);
                    case 3:
                        pedirDuracion(movie,indice);
                    case 4:
                        pedirDescripcion(movie,indice);
                    case 5:
                        pedirPuntaje(movie,indice);
                    case 6:
                        pedirLink(movie,indice);
                    case 7:
                        salir='s';
                    }
                }


            }
            else {printf("\nID INEXISTENTE\n");system("pause");return 0;}
        }else {printf("\n\nID INVALIDO\n");system("pause");}

    }
    else
    {
        printf("\nNO ES POSIBLE EJECUTAR LA ACCION REQUERIDA PORQUE NO HAY ELEMENTOS EN LA BASE DE DATOS\n\n");
        system("pause");
    }

}

//void generarPagina(EMovie* lista, char* nombre)


