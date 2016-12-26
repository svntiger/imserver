#ifndef _IM_EVENT_H_
#define _IM_EVENT_H_

#include "list.h"
#include "type.h"

#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <event2/event.h>
#include <event2/event_struct.h>
#include "type.h"



typedef struct _im_event_base_ {
	int fd;
	struct event *event;
} im_event_base_t


typedef void im_sock_event_callback(int fd, uint32_t flag, im_event_base_t *args);

extern struct event_base* s_base; 

extern int im_add_event(int fd, uint32_t flag, im_event_base_t *args, im_sock_event_callback *callback);

extern void im_del_event(im_event_base_t *args);

extern void im_dispatch_event(void);


#ifdef __cplusplus
}
#endif

#endif

