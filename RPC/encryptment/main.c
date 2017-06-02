#include <string.h>
#include "aes256.h"
#include "b64.h"
#include <stdio.h>

#define BLOCK_SIZE 128

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
int main(int argc, char **argv)
{
  int i;
  uchar in[BLOCK_SIZE] = "Id de ballon ! coucou -123456789-090909";
  uchar out[BLOCK_SIZE];
  char* ballon = cryptBallon(in);
  printf("Apres encodage en base64 : %s\n",ballon);

  char* decrypt = decryptBallon(ballon);
  printf("%s\n",decrypt );
  // uchar* in2 = b64_decode(ch, strlen(ch));
  // uchar out2[BLOCK_SIZE];
  // Decrypt(in2, out2);
  // printf("%s\n",out2 );
  return 0;
}
