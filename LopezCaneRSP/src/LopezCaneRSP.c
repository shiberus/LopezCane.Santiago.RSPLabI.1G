#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Post.h"
#include "Util.h"
#include <time.h>

int main(void) {
	setbuf(stdout, NULL);
	srand(time(NULL));

	int* option = (int*) malloc(sizeof(int));
	int* fail = (int*) malloc(sizeof(int));
	char* path = (char*) malloc(sizeof(char) * 20);
	LinkedList* listaPosts = ll_newLinkedList();
	LinkedList* nuevaLista = NULL;

	if(option != NULL && fail != NULL && path != NULL && listaPosts != NULL)
	{
		do{
			printf("*** Menu de Opciones ***\n\n");
			printf("1- Cargar los datos de los posts\n");
			printf("2- Listar posts\n");
			printf("3- Asignar estadisticas\n");
			printf("4- Filtrar por mejores posteos\n");
			printf("5- Filtrar por haters\n");
			printf("6- Ordenar posts\n");
			printf("7- Guardar los datos de los posts\n");
			printf("8- Finalizar programa\n");
			scanf("%d", option);

			switch(*option)
			{
				case 1:
					if(ll_isEmpty(listaPosts) || preguntar("Ya hay posts cargados, desea sobreescribirlos?"))
					{
						ll_clear(listaPosts);

						*fail = ingresarNombreArchivo(path);

						if(*fail)
						{
							pausar("Oh oh, hubo un error");
						}
						else
						{
							*fail = controller_loadFromText(path,listaPosts);

							if(*fail)
							{
								pausar("Oh oh, hubo un error");
							}
							else
							{
								pausar("Los datos se cargaron exitosamente");
							}
						}
					}
					else
					{
						pausar("Operacion cancelada");
					}
					break;

				case 2:
					if(!ll_isEmpty(listaPosts))
					{
						controller_ListPost(listaPosts);
						pausar(NULL);
					}
					else
					{
						pausar("No hay posts cargados");
					}
					break;

				case 3:
					if(!ll_isEmpty(listaPosts))
					{
						nuevaLista = ll_map(listaPosts, controller_assignValues);
						if(nuevaLista != NULL)
						{
							pausar("Operacion exitosa");
						}
					}
					else
					{
						pausar("No hay posts cargados");
					}
					break;

				case 4:
					if(!ll_isEmpty(listaPosts))
					{
						nuevaLista = ll_filter(listaPosts, controller_filtrarLikes);
						if(nuevaLista != NULL)
						{
							*fail = controller_saveAsText("mejoresPosts.csv", nuevaLista);

							if(!(*fail))
							{
								pausar("Operacion exitosa");
							}
						}
					}
					else
					{
						pausar("No hay posts cargados");
					}
					break;

				case 5:
					if(!ll_isEmpty(listaPosts))
					{
						nuevaLista = ll_filter(listaPosts, controller_filtrarHaters);
						if(nuevaLista != NULL)
						{
							*fail = controller_saveAsText("haters.csv", nuevaLista);

							if(!(*fail))
							{
								pausar("Operacion exitosa");
							}
						}
					}
					else
					{
						pausar("No hay posts cargados");
					}
					break;

				case 6:
					if(!ll_isEmpty(listaPosts))
					{
						if(!controller_sortPost(listaPosts))
						{
							pausar("Operacion exitosa");
						}
					}
					else
					{
						pausar("No hay posts cargados");
					}
					break;

				case 7:
					if(!ll_isEmpty(listaPosts))
					{
						*fail = ingresarNombreArchivo(path);

						if(*fail)
						{
							pausar("Oh oh, hubo un error");
						}
						else
						{
							*fail = controller_saveAsText(path,listaPosts);

							if(*fail)
							{
								pausar("Oh oh, hubo un error");
							}
							else
							{
								pausar("Los datos se guardaron exitosamente");
							}
						}
					}
					break;

				case 8:
					printf("Apruebeme profe.");
					break;

				default:
					pausar("Opcion invalida");
					break;
			}

		}
		while(*option != 8);
	}
	else
	{
		printf("No se pudo inicializar el programa.");
	}
	free(option);
	free(fail);
	free(path);

    return 0;
}
