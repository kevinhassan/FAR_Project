/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RPC_SEMAPHORE_H_RPCGEN
#define _RPC_SEMAPHORE_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct int_and_counter_t {
	int amount;
	int server_counter;
};
typedef struct int_and_counter_t int_and_counter_t;

struct down_arg_t {
	int amount;
	int server_counter;
	int client_id;
};
typedef struct down_arg_t down_arg_t;

#define RPC_SEMAPHORE 0x20002300
#define V1 1

#if defined(__STDC__) || defined(__cplusplus)
#define up 1
extern  int * up_1(int_and_counter_t *, CLIENT *);
extern  int * up_1_svc(int_and_counter_t *, struct svc_req *);
#define down 2
extern  int * down_1(down_arg_t *, CLIENT *);
extern  int * down_1_svc(down_arg_t *, struct svc_req *);
#define set 3
extern  int * set_1(int_and_counter_t *, CLIENT *);
extern  int * set_1_svc(int_and_counter_t *, struct svc_req *);
#define get_server_counter 4
extern  int * get_server_counter_1(int *, CLIENT *);
extern  int * get_server_counter_1_svc(int *, struct svc_req *);
extern int rpc_semaphore_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define up 1
extern  int * up_1();
extern  int * up_1_svc();
#define down 2
extern  int * down_1();
extern  int * down_1_svc();
#define set 3
extern  int * set_1();
extern  int * set_1_svc();
#define get_server_counter 4
extern  int * get_server_counter_1();
extern  int * get_server_counter_1_svc();
extern int rpc_semaphore_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_int_and_counter_t (XDR *, int_and_counter_t*);
extern  bool_t xdr_down_arg_t (XDR *, down_arg_t*);

#else /* K&R C */
extern bool_t xdr_int_and_counter_t ();
extern bool_t xdr_down_arg_t ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_RPC_SEMAPHORE_H_RPCGEN */