/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calcul.h"
#include <string.h>
#include "encryptment/aes256.h"
#include "encryptment/b64.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define BLOCK_SIZE 128
int nbBallons = 4;
char* ballons[4] ;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static reponse result;

char* cryptBallon(uchar in[BLOCK_SIZE]){
    uchar out[BLOCK_SIZE];
    Encrypt(in, out);//ecb encode
    char* ch = b64_encode(out, strlen(out));
    return ch;
}
char* decryptBallon(char* ch){
    uchar* in2 = b64_decode(ch, strlen(ch));
    Decrypt(in2, in2);
    return in2;
}

void *thread_1(char* arg){
    printf("Nombre de ballon avant de donner: %d\n", nbBallons);
    int size = strlen((char*)arg);
    char *rep = malloc((size+1)*sizeof(char));
    char* ballon = cryptBallon(arg);

    pthread_mutex_lock (&mutex);

    if(nbBallons>0){
        strcpy(&ballons[4-nbBallons], ballon);
        nbBallons -= 1; //On enlève un ballon
        printf("Nombre de ballon après avoir donné: %d\n", nbBallons);

        result.ballon = ballon; //on sauvegarde la clé pour la renvoyer
        result.errno = NULL;
    }else{ // on peut pas donner de ballon
        result.errno = -1;
    }

    pthread_mutex_unlock (&mutex);
    pthread_exit ((void*)0);
}


void *
calcul_null_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */

	return (void *) &result;
}


reponse *
calcul_my_strcat_1_svc(data *argp, struct svc_req *rqstp)
{
    pthread_t thread;
    pthread_create (&thread, NULL, thread_1, argp->arg1);
    pthread_join(thread, NULL);
    return &result;
}