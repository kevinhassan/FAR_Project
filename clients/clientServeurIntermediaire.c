// tcp_serveur.c

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#define TAILLE 256

int main(void) {

  char port[8];
  char *pos;
  char buffer[256];
  char root[256] = "public_ballon";
  FILE* fichier = NULL;

  /* Renseignement du port d'écoute */
  printf("Port d'écoute : ");
  fgets(port, 8, stdin);
  if ((pos=strchr(port, '\n')) != NULL) *pos = '\0';

  if(strlen(port)==0){
     port[0] = '8';
     port[1] = '0';
  }

  /* Socket et contexte d'adressage du serveur */
  struct sockaddr_in sin;
  int sock;
  socklen_t recsize = sizeof(sin);
  pid_t pid;

  /* Socket et contexte d'adressage du client */
  struct sockaddr_in csin;
  int csock;
  socklen_t crecsize = sizeof(csin);

  /* Creation d'une socket */
  sock = socket(AF_INET, SOCK_STREAM, 0);

  /* Configuration */
  sin.sin_addr.s_addr = htonl(INADDR_ANY);  /* Adresse IP automatique */
  sin.sin_family = AF_INET;                 /* Protocole familial (IP) */
  sin.sin_port = htons(atoi(port));               /* Listage du port */
  bind(sock, (struct sockaddr*)&sin, recsize);


  /* Demarrage du listage (mode server) */
  listen(sock, 5);

  printf("Serveur %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));

while(1){

  /* Attente d'une connexion client */
  csock = accept(sock, (struct sockaddr*)&csin, &crecsize);
  printf("Un client se connecte avec la socket %d de %s:%d\n",
         csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));

  pid = fork();

  if(pid == 0){

    /* Attente du message du client et affichage */
    recv(csock, buffer, TAILLE,0);
    printf("Message du client n°%d: %s", csock, buffer);

    /* Verification de la demande*/
    char *tok = strtok(buffer, " ");

    if(strcmp(tok, "GET") == 0){
      printf("Requete acceptée\n");

      //On récupère la page demandée dans tok
      tok = strtok(NULL, " ");
      if(strcmp(tok, "/") == 0){
           strcat(tok, "ballon.txt");
      }
      strcat(root, tok);
      printf("Tentative d'ouverture de -%s-\n",root);

      fichier = fopen(root, "r");

      if (fichier != NULL){
          printf("Envoi des données...\n");
          send(csock, "HTTP/1.1 200 OK\n\n", 17, 0);
          while(fgets(buffer, TAILLE, fichier) != NULL){
	          send(csock, buffer, strlen(buffer), 0);
          }
	  printf("Terminé\n");
	  fclose(fichier);
      }else{
        printf("Page non existante\n");

        // Envoie du message au client

	send(csock, "HTTP/1.1 404 NOT FOUND\n\n", 24, 0);
        char buffer[32] = "La page n'existe pas";
        send(csock, buffer, sizeof(buffer), 0);
      }
    }else{
      printf("Requete rejetée\n");
      /* Envoie du message au client */
      char buffer[32] = "Bad Request";
      send(csock, buffer, 32, 0);
    }
    /* Fermeture de la socket client */
	shutdown(csock,2);
    close(csock);
    exit(0);
  }
}

close(sock);

return EXIT_SUCCESS;

}//main
