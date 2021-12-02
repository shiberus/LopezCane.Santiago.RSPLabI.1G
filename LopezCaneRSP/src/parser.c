#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Post.h"


int parser_PostFromText(FILE* pFile , LinkedList* pArrayListPost)
{
	int todoOk = -1;
	Post* pPost;
	char* idAux = (char*) malloc(sizeof(char) * 256);
	char* userAux = (char*) malloc(sizeof(char) * 256);
	char* likesAux = (char*) malloc(sizeof(char) * 256);
	char* dislikesAux = (char*) malloc(sizeof(char) * 256);
	char* followersAux = (char*) malloc(sizeof(char) * 256);

	if(idAux != NULL && userAux != NULL && likesAux != NULL && dislikesAux != NULL && followersAux != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, userAux, likesAux, dislikesAux, followersAux);

		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, userAux, likesAux, dislikesAux, followersAux))
			{
				pPost = post_newParametros(idAux, userAux, likesAux, dislikesAux, followersAux);
				if(pPost != NULL)
				{
					ll_add(pArrayListPost,pPost);
					todoOk = 0;
				}
				else
				{
					post_delete(pPost);
					todoOk = -1;
					break;
				}
			}
			else
			{
				post_delete(pPost);
				break;
			}
		}
		while(!feof(pFile));
	}
	free(idAux);
	free(userAux);
	free(likesAux);
	free(dislikesAux);
	free(followersAux);

    return todoOk;
}

int parser_PostToText(FILE* pFile , LinkedList* pArrayListPost)
{
	int todoOk = -1;
	int* tam = (int*) malloc(sizeof(int));
	int* id = (int*) malloc(sizeof(int));
	char* user = (char*) malloc(sizeof(char) * 256);
	int* likes = (int*) malloc(sizeof(int));
	int* dislikes = (int*) malloc(sizeof(int));
	int* followers = (int*) malloc(sizeof(int));
	Post* pPost;

	if (pFile != NULL && pArrayListPost != NULL && tam != NULL && id != NULL &&
	user != NULL && likes != NULL && dislikes != NULL && followers != NULL)
	{
		*tam = ll_len(pArrayListPost);

		fprintf(pFile,"id,user,likes,dislikes,followers\n");

		for(int i = 0; i < *tam; i++)
		{
			pPost = (Post*) ll_get(pArrayListPost, i);

			if(!post_getId(pPost,id) &&
			!post_getUser(pPost,user) &&
			!post_getLikes(pPost,likes) &&
			!post_getDislikes(pPost,dislikes) &&
			!post_getFollowers(pPost,followers))
			{
				fprintf(pFile,"%d,%s,%d,%d,%d\n", *id, user, *likes, *dislikes, *followers);
			}
		}
		todoOk = 0;
	}
	free(tam);
	free(id);
	free(user);
	free(likes);
	free(dislikes);
	free(followers);

	return todoOk;
}
