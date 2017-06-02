#include <openssl/aes.h>
#include <stdio.h>
#include <stdlib.h>
#include "aes256.h"

// Fill in actual key here
static const uchar ckey[] = "VsuKiZvQpe2R+TSiWNRdBlNS";

void Encrypt(uchar *in, uchar *out)
{
    static int firstRun = 1;
    static AES_KEY encryptKey;

    if (firstRun == 1)
    {
        AES_set_encrypt_key(ckey, 256, &encryptKey);
        firstRun = 0;
    }   

    int i;
    for(i = 0;i <= strlen(in)/16;i++)
    {
    	AES_ecb_encrypt(in + i*16, out + i*16, &encryptKey, AES_ENCRYPT);
    }

//    AES_ecb_encrypt(in, out, &encryptKey, AES_ENCRYPT);
//    AES_ecb_encrypt(&in[AES_BLOCK_SIZE], &out[AES_BLOCK_SIZE], &encryptKey, AES_ENCRYPT);

}

void Decrypt(uchar *in, uchar *out)
{
    static int firstRun = 1;
    static AES_KEY decryptKey;

    if (firstRun == 1)
    {
        AES_set_decrypt_key(ckey, 256, &decryptKey);
        firstRun = 0;
    }   

    int i;
    for(i = 0;i <= strlen(in)/16;i++)
    {
    	AES_ecb_encrypt(in + i*16, out + i*16, &decryptKey, AES_DECRYPT);
    }

//    AES_ecb_encrypt(in, out, &decryptKey, AES_DECRYPT);
//    AES_ecb_encrypt(&in[AES_BLOCK_SIZE], &out[AES_BLOCK_SIZE], &decryptKey, AES_DECRYPT);

}

