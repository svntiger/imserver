#ifndef _RT_AREA_H_
#define _RT_AREA_H_

#include "list.h"
#include "type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _rt_area_{
	u32 rta_flag;	
	rt_sock_t
	struct head_list rta_head;
} rt_area_t;

#ifdef __cplusplus
}
#endif

#endif
