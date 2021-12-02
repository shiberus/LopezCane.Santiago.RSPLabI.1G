#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "Util.h"
#include "Post.h"


int controller_loadFromText(char* path , LinkedList* pArrayListPost)
{
	int todoOk = -1;
	int* fail = (int*) malloc(sizeof(int));
	
	FILE* pFile;
	
	if(path != NULL && pArrayListPost != NULL && fail != NULL)
	{
		*fail = 1;
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			*fail = parser_PostFromText(pFile, pArrayListPost);

			if (!(*fail))
			{
				todoOk = 0;
			}
		}
		fclose(pFile);
	}
	free(fail);

	return todoOk;
}

int controller_ListPost(LinkedList* pArrayListPost)
{
	int todoOk = -1;
	int* tam = (int*) malloc(sizeof(int));

	Post* pPost;

	if(pArrayListPost != NULL && tam != NULL)
	{
		*tam = ll_len(pArrayListPost);

		printf("   id  |       user       | likes |  dislikes  |  followers \n");
		printf("------------------------------------------------------------- \n");
		for(int i = 0; i < *tam; i++)
		{
			pPost = (Post*) ll_get(pArrayListPost, i);

			if(pPost != NULL)
			{
				post_print(pPost);
			}
		}
		todoOk = 0;
	}
	free(tam);

	return todoOk;
}

int controller_sortPost(LinkedList* pArrayListPost)
{
    int todoOk = -1;

	if(pArrayListPost != NULL)
	{
		todoOk = ll_sort(pArrayListPost, controller_compareFollowers, 0);
	}

	return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPost)
{
    int todoOk = -1;
	int* fail = (int*) malloc(sizeof(int));

	if(path != NULL && pArrayListPost != NULL && fail != NULL)
	{
		*fail = 1;
		FILE* f = fopen(path,"w");
		if(f != NULL)
		{
			*fail = parser_PostToText(f, pArrayListPost);

			if(!(*fail))
			{
				todoOk = 0;
			}

			fclose(f);
		}
	}
	free(fail);

    return todoOk;
}

int controller_compareFollowers(void* first, void* second)
{
	int resultado = 0;
	int* firstFollowers = (int*) malloc(sizeof(int));
	int* secondFollowers = (int*) malloc(sizeof(int));

	Post* firstPost;
	Post* secondPost;

	if(first != NULL && second != NULL && firstFollowers != NULL && secondFollowers != NULL)
	{
		firstPost = (Post*) first;
		secondPost = (Post*) second;

		if(!post_getFollowers(firstPost, firstFollowers) && !post_getFollowers(secondPost, secondFollowers))
		{
			resultado = *firstFollowers - *secondFollowers;
		}
	}
	free(firstFollowers);
	free(secondFollowers);

	return resultado == 0 ? 0 : resultado > 0 ? 1 : -1;	
}

void* controller_assignValues(void* pElement)
{
	int likes = (rand() % (5000 - 500 + 1)) + 500;
	int dislikes = (rand() % (3500 - 300 + 1)) + 300;
	int followers = (rand() % (20000 - 10000 + 1)) + 10000;
	Post *posteo = NULL;

	if(pElement != NULL)
	{
		posteo = (Post*) pElement;

		if(post_setLikes(posteo, likes) ||
		post_setDislikes(posteo, dislikes) ||
		post_setFollowers(posteo, followers))
		{
			posteo = NULL;
		}
	}

	return posteo;
}

int controller_filtrarLikes(void* this)
{
	int likes, resultado = 0;
	Post* posteo = NULL;

	if(this != NULL)
	{
		posteo = (Post*) this;
		if(!post_getLikes(posteo, &likes))
		{
			resultado = likes > 3000;
		}
	}

	return resultado;
}

int controller_filtrarHaters(void* this)
{
	int likes, dislikes, resultado = 0;
	Post* posteo = NULL;

	if(this != NULL)
	{
		posteo = (Post*) this;
		if(!post_getLikes(posteo, &likes) && !post_getDislikes(posteo, &dislikes))
		{
			resultado = dislikes > likes;
		}
	}

	return resultado;
}
