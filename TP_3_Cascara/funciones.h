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
    char titulo[100];
    char genero[100];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[200];
    int estado;
    int id;
}EMovie;





/**
 *  Busca Espacio libre en la estructura para realizar la carga,
 * \param lista la lista de peliculas a ser agregadas en el archivo.
 * \return Indice libre o -1 en caso de no existir
 *
 */
int buscaEstadoLibre (EMovie*);

/**
 * Cuenta la cantidad de peliculas Válidas dentro de la estructuta y devuelve la cantidad
 * \param EMovie*
 * \return int
 *
 */
int contarPeliculas(EMovie*);
/**
 *  Inicializa el arreglo para que en el campo estado no exista basura
 * \param EMovie*
 * \return void
 *
 */
void inicializarLista(EMovie*);

// FUNCIONES PARA TOMAR DATOS

/**
 *  Función para realizar pedido de datos por telado, se limita la cantidad de caracteres por lo tanto no desvorda
 * \param char* puntero al string donde se van a guardar los datos
 * \param int cantidad de caracteres a guardar, el resto se trunca
 * \return int 0 si realizó satisfactriamente, -1 si hubo error
 *
 */
int consulta(char*,int);
/**
 * Convierte char* a entero, si no puede convertir devuelve -1
 * \param char*
 * \return int
 *
 */
int stringAenteroPositivo(char*); // DEVUELVE -1 SI NO PUEDE HACER LA CONVERSION
/**
 * Valida rango de un entero, retorna -1 si no valida
 * \param int minimo
 * \param int maximo
 * \param int entero a validad
 * \return int
 *
 */
int ValidarEntero(int,int,int); // valida entre min y max y retorna dato o -1 si no valida

/** Funcion que genera la consulta del titulo a cargar en la estructura
 *
 * \param EMovie*
 * \param int indice donde se guarda el dato
 * \return int
 *
 */
int pedirTitulo(EMovie*,int);
/** \brief
 * Funcion que genera la consulta del género a cargar en la estructura
 * \param EMovie*
 * \param indice donde se guarda el dato
 * \return int
 *
 */
int pedirGenero(EMovie*,int);
/**
 *  Funcion que genera la consulta del la duracion a cargar en la estructura
 * \param EMovie*
 * \param indice
 * \return int
 *
 */
int pedirDuracion(EMovie*,int);
/**
 * Funcion que genera la consulta de la descripcion a cargar en la estructura
 * \param EMovie*
 * \param indice
 * \return int
 *
 */
int pedirDescripcion(EMovie*,int);
/**
 * Funcion que genera la consulta del puntaje a cargar en la estructura
 * \param EMovie*
 * \param indice
 * \return int
 *
 */
int pedirPuntaje(EMovie*,int);
/**
 * Funcion que genera la consulta del link de la imagen a cargar en la estructura
 * \param EMovie*
 * \param indice
 * \return int
 *
 */
int pedirLink(EMovie*,int);

//SETTERS - DEVUELVEN 1 SI FUE CORRECTO, 0 SI HAY ERROR

/* EL BLOQUE DE SETTERS Y GETTERS CARGAN Y TOMAN DATOS DE LA ESTRUCTUTA, A TODOS SE LES PASA LA ESTRUCTURA Y EL INDICE A LEER O SETEAR*/

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

/** LISTA PELICULAS EN MEMORIA
 *
 * \param EMovie*
 * \return void
 *
 */
void ListarPeliculas(EMovie*);
/**
 * PONE EL ESTADO DE UN REGISTRO EN INVALIDO, PARA QUE PUEDA SER PISADO POR OTRA PELICULA A CARGAR
 * \param EMovie*
 * \return int
 *
 */
int borrarPelicula(EMovie*);
/**
 * SIMPLEMENTE BUSCA AL MENOS 1 REGISTRO EN LA ESTRUCTURA
   recorre la estructura en busca de registros validos, 1  si hay, 0 si esta vacia
 * \param EMovie*
 * \return int
 *
 */
int hayRegistro(EMovie*);
/**
 * RELACION ID DE UNA PELICULA CON SU INDICE DENTRO DEL ARRAY DE ESTRUCTURAS
 * \param EMovie*
 * \param ID
 * \return int INDICE
 *
 */
int buscarxId(EMovie*,int);
/** FUNCION PARA MODIFICAR CAMPOS DE UN REGISTRO PELICULA
 *
 * \param EMovie*
 * \return int
 *
 */
int modificarPelicula(EMovie*);

// ARCHIVOS

/**
 * VUELCA LA ESTRUCTURA QUE ESTA EN MEMORIA A ARCHIVO
 * \param EMovie*
 * \return void
 *
 */
void guardarArchivo(EMovie*);
/**
 * LEE UN ARCHIVO CON ESTRUCTURAS DEL TIPO EMOVIE Y LO VUELCA EN MEMORIA (INICIALIZA LA ESTRUCTURA CON DATOS)
 * \param EMovie*
 * \return void
 *
 */
void leerArchivo(EMovie*);
/**
 * CREA EL ARCHIVO HTML A MOSTRAR,
 * \param EMovie*
 * \param char* NOMBRE DEL ARCHIVO
 * \return void
 *
 */
void crearHtml(EMovie*,char*);
#endif
