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
#define BLOCK_SIZE 128

void *
calcul_null_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */

	return (void *) &result;
}
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

reponse *
calcul_my_strcat_1_svc(data *argp, struct svc_req *rqstp)
{
	static reponse result;
	int size = strlen(argp->arg1);
	char *rep = malloc((size+1)*sizeof(char));
	char* ballon = cryptBallon(argp->arg1);
    rep = ballon;
    result.ballon = rep;
	return &result;
}
