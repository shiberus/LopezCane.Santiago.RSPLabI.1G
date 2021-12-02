#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED


/** \brief Pide al usuario un user con un minimo y maximo de caracteres
 *
 * \param destino char* user donde se guarda el input
 * \param mensaje char* mensaje que se le muestra al usuario
 * \param min int minimo de caracteres
 * \param max int maximo de caracteres
 * \return int (0) todo Ok (-1) error
 *
 */
int ingresarUser(char *destino, char *mensaje, int min, int max);


/** \brief Valida que un user solo contenga letras y espacios
 *
 * \param str[] char el user a ser evaluado
 * \return int (0) si es valido (-1) si es invalido
 *
 */
int validarLetras(char *str);

/*
 * \brief pide un número entero
 * \param pResultado int* puntero para guardar el número entero
 * \param mensaje char* mensaje para el usuario
 * \param mensajeError char* mensaje de error si no es valido
 * \param minimo int minimo aceptado
 * \param maximo int maximo aceptado
 * \param reintentos int cantidad de reintentos
 * \return 0 si ha salido ok. -1 si no lo logro
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/*
 * \brief detiene la ejecucion del programa hasta que el usuario presione enter
 * \param mensaje char* mensaje para el usuario
 */
void pausar(char* mensaje);

/*
 * \brief consulta al usuario si desea cancelar la operacion
 * \param mensaje char* mensaje para el usuario
 * \return 1 para cancelar. 0 para continuar
 */
int cancelarOperacion(char* mensaje);

/*
 * \brief hace una pregunta de si/no al usuario
 * \param mensaje char* mensaje para el usuario
 * \return 1 para si. 0 para no
 */
int preguntar(char* mensaje);

/*
 * \brief permite al usuario ingresar el nombre de un archivo csv
 * \param path char* puntero a donde se guarda el nombre
 * \return 0 si ha salido ok. -1 si no lo logro
 */
int ingresarNombreArchivo(char* path);
#endif // UTIL_H_INCLUDED
