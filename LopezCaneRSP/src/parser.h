#include <stdio.h>

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPost LinkedList*
 * \return int
 *
 */
int parser_PostFromText(FILE* pFile , LinkedList* pArrayListPost);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPost LinkedList*
 * \return int
 *
 */
int parser_PostToText(FILE* pFile , LinkedList* pArrayListPost);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPost LinkedList*
 * \return int
 *
 */
int parser_PostFromBinary(FILE* pFile , LinkedList* pArrayListPost);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPost LinkedList*
 * \return int
 *
 */
int parser_PostToBinary(FILE* pFile , LinkedList* pArrayListPost);

#endif /* PARSER_H_ */
