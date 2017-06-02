struct data {
  string arg1<>;
  string arg2<>;
};
typedef struct data data;
struct reponse {
  string ballon<>;
  int errno;
};
typedef struct reponse reponse;
program CALCUL{
  version VERSION_UN{
    void CALCUL_NULL(void) = 0;
    reponse CALCUL_MY_STRCAT(data) = 1;
  } = 1;
} = 0x20000001;
