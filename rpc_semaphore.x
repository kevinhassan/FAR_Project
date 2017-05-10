struct int_and_counter_t {
	int amount;
	int server_counter;
};
struct down_arg_t {
	int amount;
	int server_counter;
	int client_id;
};
program RPC_SEMAPHORE {
	version V1 {
		int up(int_and_counter_t) = 1;
		int down(down_arg_t down_arg) = 2;
		int set(int_and_counter_t) = 3;
		int get_server_counter(int arg) = 4;
	} = 1;
} = 0x20002300;
