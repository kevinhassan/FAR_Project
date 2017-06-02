


test: main.o aes256.o decode.o encode.o
	gcc -o test main.o aes256.o encode.o decode.o -lssl -lcrypto
	ar rc libaes_base64.a aes256.o encode.o decode.o

main.o: b64.h aes256.h main.c
	gcc -c main.c -o main.o

aes256.o: aes256.h aes256.c
	gcc -c aes256.c -o aes256.o

decode.o: b64.h decode.c
	gcc -c decode.c -o decode.o

encode.o: b64.h encode.c
	gcc -c encode.c -o encode.o
    
clean:
	rm -f test *.o
