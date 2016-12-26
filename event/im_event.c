#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <event2/event.h>
#include <event2/event_struct.h>
#include "type.h"
#include "im_event.h"

struct event_base* s_base; 

int im_add_event(int fd, uint32_t flag, im_event_base_t *args, im_sock_event_callback *callback)
{
	struct event *event = NULL;

	if (!s_base) {
		s_base = event_base_new();
		if (!s_base) {
			goto out;
		}
	}
	event = event_new(s_base, fd, flag|EV_PERSIST, callback, args);
	if (!event) {
		goto out;
	}

	assert(!args->fd && !args->event);
	args->fd = fd;
	args->event = event;
	event_add(event, NULL);

	return 0;
out:
	return -1;
}

void im_del_event(im_event_base_t *args)
{
	if (args->event) {
		event_free(args->event);
		args->event = NULL;
	}
	if (args->fd > 0) {
		close(args->fd);
		args->fd = 0;
	}
}
void im_dispatch_event(void)
{
	if (!s_base) {
		return;
	}
	event_base_dispatch(s_base);
}
