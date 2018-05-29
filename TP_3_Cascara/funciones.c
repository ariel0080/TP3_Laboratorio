#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"



// FUNCIONES PARA TOMAR DATOS Y VALIDAR

int ValidarEntero(int min,int max,int dato)
{
    if(dato > min && dato < max)
        {
            return dato;
        }
    else return -1;
}


char* consulta(int caracteres)
{

    char* dato;
    fgets(dato,caracteres,stdin);
    int largo=0;
    while (dato[largo]!='\n')
        {
        largo++;
        }
    dato[largo]='\0';
    return dato;
}

int stringAenteroPositivo(char* dato) // DEVUELVE EL ENTERO SI ESTA BIEN O -1 SI DA ERROR
{
    char* c;
    c = &dato;
    int a=0;

    while(isdigit(*(c+a)))
    {
        a++;
        if(*(c+a)=='\0') {return atoi(dato);}
    }

    return -1;
}
// INICIALIZAR Y BUSQUEDA DE ESTADO LIBRE

int buscaEstadoLibre (EMovie* lista)
{
    int i=0;
    while (get_EMovie_estado(lista,i) && i < CANTIDAD)
    {
        i++;
        if (i==20)
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


//SETTERS (VALIDACION DENTRO DE LOS MISMOS)

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

char* get_EMovie_linkImagen(EMovie* lista,int posicion)
{
    char* link;

    strcpy(link,(lista+posicion)->linkImagen);
    return link;
}
char* get_EMovie_genero(EMovie* lista,int posicion)
{
    char* gen;
    strcpy(gen,(lista+posicion)->genero);
    return gen;
}
char* get_EMovie_descripcion(EMovie* lista, int posicion)
{
    char* desc;
    strcpy(desc,(lista+posicion)->descripcion);
    return desc;
}
char* get_EMovie_titulo(EMovie* lista,int posicion)
{
    char* tit;
    strcpy(tit,(lista+posicion)->titulo);
    return tit;

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

// FUNCIONES DEL MENU

int agregarPelicula(EMovie* movie)
{
    char* aux;
    int indice;
    int durac;
    int punt;
    indice=buscaEstadoLibre(movie);
    if(indice!=-1)
    {
        printf("\nIngrese t%ctulo de la pel%ccula: ",ii,ii);
        aux = consulta(20);
        if(set_EMovie_titulo(movie,aux,indice)==1){set_EMovie_titulo(movie,aux,indice);}
            else return 0;

        printf("\nIngrese g%cnero de la pel%ccula: ",ee,ii);
        aux = consulta(20);
        if(set_EMovie_genero(movie,aux,indice)==1){set_EMovie_genero(movie,aux,indice);}
            else return 0;

        printf("\nIngrese duraci%cn de la pel%ccula: ",oo,ii); // en cada validacion
        aux = consulta(20);
        if(stringAenteroPositivo(aux)!=-1);
        {
            durac = stringAenteroPositivo(aux);
            durac = ValidarEntero(0,300,durac);
            if (durac!=-1)
            {
                if(set_EMovie_duracion(movie,durac,indice)==1){set_EMovie_duracion(movie,durac,indice);} else return 0;
            }

        } else return -1;

        printf("\nIngrese descripci%cn de la pel%ccula: ",oo,ii);
        aux = consulta(50);
        if(set_EMovie_descripcion(movie,aux,indice)==1){set_EMovie_descripcion(movie,aux,indice);}
        else return 0;

        printf("\nIngrese puntaje de la pel%ccula: ",ii); // en cada validacion
        aux = consulta(20);
        if(stringAenteroPositivo(aux)!=-1);
        {
            punt = stringAenteroPositivo(aux);
            punt = ValidarEntero(0,10,punt);
            if (punt!=-1)
            {
                if(set_EMovie_puntaje(movie,punt,indice)==1){set_EMovie_duracion(movie,durac,indice);}
                else return 0;
            }

        }else return -1;


        printf("\nIngrese link de la im%cgen de la pel%ccula: ",aa,ii);
        aux = consulta(50);
        if(set_EMovie_linkImagen(movie,aux,indice)==1){set_EMovie_linkImagen(movie,aux,indice);}
            else return 0;

        if(set_EMovie_estado(movie,1,indice)==1){set_EMovie_estado(movie,1,indice);}
            else return 0;

        if(set_EMovie_id(movie,100+indice,indice)==1){set_EMovie_id(movie,100+indice,indice);}
            else return 0;


    }else return -1;

}

//int borrarPelicula(EMovie* movie)
//void generarPagina(EMovie* lista, char* nombre)

