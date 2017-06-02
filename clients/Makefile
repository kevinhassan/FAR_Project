# Makefile

GCC=gcc
FILES=clientRobot.c clientServeurIntermediaire.c
OBJ=$(FILES:%.c=%.o)
BIN=clientRobot clientServeurIntermediaire

all: $(OBJ)
	$(GCC) -o clientRobot clientRobot.o
	$(GCC) -o clientServeurIntermediaire clientServeurIntermediaire.o

clean:
	rm -f *~ *.o $(BIN)

.SUFFIXES: .c .o

.zf.res:
	$(GCC) -c $<
