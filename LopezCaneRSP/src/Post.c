#include "Post.h"

Post* post_new(void)
{
	Post* pPost = (Post*) malloc(sizeof(Post));

	pPost ->id = 0;
	strcpy(pPost->user, "Sin Nombre");
	pPost ->likes = 0;
	pPost ->dislikes = 0;
	pPost ->followers = 0;

	return pPost;
}

Post* post_newParametros(char* idStr,char* userStr,char* likesStr, char* dislikesStr, char* followersStr)
{
	int auxId, auxLikes, auxDislikes, auxFollowers;
	Post* pPost = NULL;

	if(idStr != NULL && userStr != NULL && likesStr != NULL && dislikesStr != NULL && followersStr != NULL)
	{
		auxId = atoi(idStr);
		auxLikes = atoi(likesStr);
		auxDislikes = atoi(likesStr);
		auxFollowers = atoi(followersStr);

		Post* auxPost = post_new();
		
		if(auxPost != NULL)
		{
			if(!post_setId(auxPost, auxId) &&
			!post_setUser(auxPost, userStr) &&
			!post_setLikes(auxPost, auxLikes) &&
			!post_setDislikes(auxPost, auxDislikes) &&
			!post_setFollowers(auxPost, auxFollowers))
			{
				pPost = auxPost;
			}
		}
	}
	return pPost;
}

void post_delete(Post* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

int post_setId(Post *this, int id)
{
	int todoOk = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		todoOk = 0;
	}
	return todoOk;
}

int post_getId(Post *this, int *id)
{
	int todoOk = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 0;
	}
	return todoOk;
}

int post_setUser(Post *this, char *user)
{
	int todoOk = -1;

	if(this != NULL && user != NULL && strlen(user) < 128)
	{
		strcpy(this->user, user);
		todoOk = 0;
	}
	return todoOk;
}

int post_getUser(Post *this, char *user)
{
	int todoOk = -1;

	if(this != NULL && user != NULL)
	{
		strcpy(user, this->user);
		todoOk = 0;
	}
	return todoOk;
}

int post_setLikes(Post *this, int likes)
{
	int todoOk = -1;

	if(this != NULL && likes >= 0)
	{
		this->likes = likes;
		todoOk = 0;
	}
	return todoOk;
}

int post_getLikes(Post *this, int *likes)
{
	int todoOk = -1;

	if(this != NULL && likes != NULL)
	{
		*likes = this->likes;
		todoOk = 0;
	}
	return todoOk;
}

int post_setDislikes(Post *this, int dislikes)
{
	int todoOk = -1;

	if(this != NULL && dislikes >= 0)
	{
		this->dislikes = dislikes;
		todoOk = 0;
	}
	return todoOk;
}

int post_getDislikes(Post *this, int *dislikes)
{
	int todoOk = -1;

	if(this != NULL && dislikes != NULL)
	{
		*dislikes = this->dislikes;
		todoOk = 0;
	}
	return todoOk;
}

int post_setFollowers(Post *this, int followers)
{
	int todoOk = -1;

	if(this != NULL && followers >= 0)
	{
		this->followers = followers;
		todoOk = 0;
	}
	return todoOk;
}

int post_getFollowers(Post *this, int *followers)
{
	int todoOk = -1;

	if(this != NULL && followers != NULL)
	{
		*followers = this->followers;
		todoOk = 0;
	}
	return todoOk;
}

int post_print(Post* this)
{
	int todoOk = -1;
	int* id = (int*) malloc(sizeof(int));
	int* likes = (int*) malloc(sizeof(int));
	int* dislikes = (int*) malloc(sizeof(int));
	int* followers = (int*) malloc(sizeof(int));
	char* user = (char*) malloc(sizeof(char) * 256);

	if(this != NULL && id != NULL && user != NULL && likes != NULL && dislikes != NULL && followers != NULL)
	{
		if(!post_getId(this, id) &&
		!post_getUser(this, user) &&
		!post_getLikes(this, likes) &&
		!post_getDislikes(this, dislikes) &&
		!post_getFollowers(this, followers))
		{
			printf("%4d  %18s    %4d        %4d        %4d \n", *id, user, *likes, *dislikes, *followers);
		}
		todoOk = 0;
	}
	free(id);
	free(likes);
	free(dislikes);
	free(followers);
	free(user);

	return todoOk;
}
