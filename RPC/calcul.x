struct data {
  string arg1<>;
};
typedef struct data data;
struct reponse {
  string ballon<>;
  int errno;
};
typedef struct reponse reponse;
program CALCUL{
  version VERSION_UN{
    reponse CALCUL_MY_STRCAT(data) = 1;
    reponse VALID_BUT(data) = 2;
  } = 1;
} = 0x20000001;
