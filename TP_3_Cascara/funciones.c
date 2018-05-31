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
    printf("ESTO ES LO QUE INGRESA POR PUNTAJE: %d INDICE %d\n",p,indice);system("pause");
    set_EMovie_duracion(movie,p,indice);
    printf("LEo lo ingresado desde la estructura: %d indice: %d\n",movie[indice].puntaje,indice);system("pause");
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

    for(int i=0;i<CANTIDAD;i++)
    {
        if(get_EMovie_estado(movie,i)==1)
        {
            char t[20];
            char g[20];
            char d[51];
            int du,pun,id;

            get_EMovie_titulo(movie,i,t);printf("Titulo: %s\n",t);
            get_EMovie_genero(movie,i,g);printf("Genero: %s\n",g);
            get_EMovie_descripcion(movie,i,d);printf("Descripcion: %s\n",d);
            du =get_EMovie_duracion(movie,i);printf("Duracion: %d\n",du);
            pun=get_EMovie_puntaje(movie,i);printf("Calificacion: %d\n",pun);
            id=get_EMovie_id(movie,i);printf("ID: %d\n\n",id);



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
        //set_EMovie_duracion(movie,111,indice);
        //set_EMovie_puntaje(movie,9,indice);
        pedirDescripcion(movie,indice);
        pedirPuntaje(movie, indice);
        pedirLink(movie, indice);

        if(set_EMovie_estado(movie,1,indice)==1){set_EMovie_estado(movie,1,indice);}
            else return 0;

        if(set_EMovie_id(movie,100+indice,indice)==1){set_EMovie_id(movie,100+indice,indice);}
            else return 0;
        printf("\n DURACION: %d\n",movie[indice].duracion);
        printf("\n PUNTAJE: %d\n",movie[indice].puntaje);
        system("pause");


    } else printf("\n\nLO SIENTO - NO HAY ESPACIO LIBRE EN MOMERIA PARA CARGAR OTRO REGISTRO. BORRE ALGUNO Y VUELVA A INTENTAR\n\n");

}

//int borrarPelicula(EMovie* movie)
//void generarPagina(EMovie* lista, char* nombre)

