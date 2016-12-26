#ifndef _RT_SOCK_H_
#define _RT_SOCK_H_

#include "list.h"
#include "type.h"
#include "im_event.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct _rt_sock_ {
	im_event_base_t rts_base;//must the first member
        u32  rts_client_flag:1,
		:31;
	struct head_list rts_node;
	struct head_list rts_head_message;
} rt_sock_t;

#ifdef __cplusplus
}
#endif

#endif
