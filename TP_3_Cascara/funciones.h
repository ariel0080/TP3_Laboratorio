#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


#define CANTIDAD 20
#define aa 	160
#define ee 130
#define ii 161
#define oo 162
#define uu 163
#define nn 167
#define enie 164


typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int estado;
    int id;
}EMovie;



/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie* movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie* lista, char* nombre);

/**
 *  Busca Espacio libre en la estructura para realizar la carga,
 * \param lista la lista de peliculas a ser agregadas en el archivo.
 * \return Indice libre o -1 en caso de no existir
 *
 */
int buscaEstadoLibre (EMovie*);

void inicializarLista(EMovie*);

// FUNCIONES PARA TOMAR DATOS

/**
 *  Funci�n para realizar pedido de datos por telado, se limita la cantidad de caracteres por lo tanto no desvorda
 * \param char* puntero al string donde se van a guardar los datos
 * \param int cantidad de caracteres a guardar, el resto se trunca
 * \return int 0 si realiz� satisfactriamente, -1 si hubo error
 *
 */
int consulta(char*,int);
int stringAenteroPositivo(char*); // DEVUELVE -1 SI NO PUEDE HACER LA CONVERSION
int ValidarEntero(int,int,int); // valida entre min y max y retorna dato o -1 si no valida

int pedirTitulo(EMovie*,int);
int pedirGenero(EMovie*,int);
int pedirDuracion(EMovie*,int);
int pedirDescripcion(EMovie*,int);
int pedirPuntaje(EMovie*,int);
int pedirLink(EMovie*,int);

//SETTERS - DEVUELVEN 1 SI FUE CORRECTO, 0 SI HAY ERROR

int set_EMovie_titulo(EMovie*,char*,int);
int set_EMovie_genero(EMovie*,char*,int);
int set_EMovie_descripcion(EMovie*, char*,int);
int set_EMovie_linkImagen(EMovie*, char*,int);
int set_EMovie_duracion(EMovie*, int,int);
int set_EMovie_puntaje(EMovie*, int,int);
int set_EMovie_estado(EMovie*, int,int);
int set_EMovie_id(EMovie*, int,int);


// GETTERS - DEVUELVEN EL DATO A EXTRAER

void get_EMovie_titulo(EMovie*,int,char*);
void get_EMovie_genero(EMovie*,int,char*);
void get_EMovie_descripcion(EMovie*,int,char*);
void get_EMovie_linkImagen(EMovie*,int,char*);
int get_EMovie_duracion(EMovie*,int);
int get_EMovie_puntaje(EMovie*,int);
int get_EMovie_estado(EMovie*,int);
int get_EMovie_id(EMovie*,int);

// LISTADO DE LAS PELICULAS EN MEMORIA

void ListarPeliculas(EMovie*);
int borrarPelicula(EMovie*);
int hayRegistro(EMovie*);
int buscarxId(EMovie*,int);
int modificarPelicula(EMovie*);

#endif
