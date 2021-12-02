#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef post_H_INCLUDED
#define post_H_INCLUDED

typedef struct
{
    int id;
    char user[128];
    int likes;
    int dislikes;
    int  followers;
}Post;

Post* post_new(void);
Post* post_newParametros(char* idStr,char* userStr,char* likesStr, char* dislikesStr, char* followersStr);
void post_delete(Post* this);

int post_setId(Post* this,int id);
int post_getId(Post* this,int* id);

int post_setUser(Post* this,char* user);
int post_getUser(Post* this,char* user);

int post_setLikes(Post* this,int likes);
int post_getLikes(Post* this,int* likes);

int post_setDislikes(Post* this,int dislikes);
int post_getDislikes(Post* this,int* dislikes);

int post_setFollowers(Post* this,int followers);
int post_getFollowers(Post* this,int* followers);

int post_print(Post* this);

#endif // post_H_INCLUDED
