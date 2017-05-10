#include "rpc_sem_lib/rpc_semaphore_lib.h"

int
main (int argc, char *argv[])
{
	char *host;
	int client_id;

	if (argc < 3) {
		printf ("usage: %s server_host client_number\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	client_id = atoi(argv[2]);

	sem_init(host, client_id);
	sem_up(1);
	//sem_set(4);
	sem_finalize();
exit (0);
}
