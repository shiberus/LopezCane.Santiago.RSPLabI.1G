#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED

/** \brief Carga los datos de los posteos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPost LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPost);


/** \brief Listar posteos
 *
 * \param pArrayListPost LinkedList*
 * \return int
 *
 */
int controller_ListPost(LinkedList* pArrayListPost);

/** \brief Ordenar posteos
 *
 * \param pArrayListPost LinkedList*
 * \return int
 *
 */
int controller_sortPost(LinkedList* pArrayListPost);

/** \brief Guarda los datos de los posteos en el archivo data.csv (modo texto).
 *
 * \param pArrayListPost LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPost);

/** \brief Busca un posteo por su Id.
 *
 * \param pArrayListPost LinkedList*
 * \param id int
 * \return int indice en que se encuentra el posteo
 *
 */
int controller_findPostById(LinkedList* pArrayListPost, int id);


/** \brief Compara el id de dos posteos.
 *
 * \param first void* puntero al primer posteo
 * \param second void* puntero al segundo posteo
 * \return int -1, 0 o 1 si el primero es mas pequeño, igual o mas grande que el segundo
 *
 */
int controller_compareIds(void* first, void* second);

/** \brief toma un posteo y le asigna valores random
 *
 * \param pElement void* puntero al posteo
 * \return void* puntero al posteo transformado o NULL si hay un error
 *
 */
void* controller_assignValues(void* pElement);

/** \brief toma un posteo y verifica que supere los 3000 likes
 *
 * \param pElement void* puntero al posteo
 * \return int 1 si cumple 0 si no
 *
 */
int controller_filtrarLikes(void* this);

/** \brief toma un posteo y verifica que supere los dislikes superen los likes
 *
 * \param pElement void* puntero al posteo
 * \return int 1 si cumple 0 si no
 *
 */
int controller_filtrarHaters(void* this);

/** \brief toma dos posteos y compara sus followers
 *
 * \param first void* puntero al primer posteo
 * \param second void* puntero al segundo posteo
 * \return int -1, 0 o 1 si el primero es mas pequeño, igual o mas grande que el segundo
 *
 */
int controller_compareFollowers(void* first, void* second);



#endif // controller_H_INCLUDED
