/*
 * aes256.h
 *
 *  Created on: Jun 13, 2016
 *      Author: yudylaw
 */

#ifndef AES256_H_
#define AES256_H_

typedef unsigned char uchar;

#ifdef __cplusplus
extern "C" {
#endif

void Encrypt(uchar *in, uchar *out);
void Decrypt(uchar *in, uchar *out);

#ifdef __cplusplus
}
#endif

#endif /* AES256_H_ */
