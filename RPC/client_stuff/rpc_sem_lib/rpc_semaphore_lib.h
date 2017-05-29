#include "rpc_semaphore.h"
#include "callback_svc.c"
#include "rpc_semaphore_clnt.c"
#include <stdlib.h>

CLIENT *clnt;
int SERVER_COUNTER_BEGIN = 0;
int *server_counter;
int rpc_semaphore_client_id;

void sem_up(int amount) {
	int_and_counter_t  up_1_arg;
	int *result_1;

	up_1_arg.amount = amount;

	do {
		server_counter = get_server_counter_1(server_counter, clnt);
		if (server_counter == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}

		up_1_arg.server_counter = *server_counter;

		result_1 = up_1(&up_1_arg, clnt);
		if (result_1 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
	} while (*result_1 == -1);
}

void sem_down(int amount) {
	down_arg_t  down_1_arg;
	int *result_2;

	down_1_arg.client_id = rpc_semaphore_client_id;
	down_1_arg.amount = amount;

	do {
		server_counter = get_server_counter_1(server_counter, clnt);
		if (server_counter == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}

		down_1_arg.server_counter = *server_counter;

		result_2 = down_1(&down_1_arg, clnt);
		if (result_2 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
	} while (*result_2 == -1);
	//wait for results
	fd_set readfs;
	readfs = svc_fdset;
	switch (select(32, &readfs, NULL, NULL, NULL)) {
		default:
			svc_getreqset(&readfs);
	}
}

void sem_set(int amount) {
	int  *result_3;
	int_and_counter_t  set_1_arg;

	set_1_arg.amount = amount;

	do {
		server_counter = get_server_counter_1(server_counter, clnt);
		if (server_counter == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}

		set_1_arg.server_counter = *server_counter;

		result_3 = set_1(&set_1_arg, clnt);
		if (result_3 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}

	} while (*result_3 == -1);
}

void sem_init(char *host, int client_id) {
	server_counter = &SERVER_COUNTER_BEGIN;
	rpc_semaphore_client_id = client_id;
#ifndef	DEBUG
	clnt = clnt_create (host, RPC_SEMAPHORE, V1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	register_server(client_id);
}

void sem_finalize() {
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}
