#ifndef _RT_LAYER_H_
#define _RT_LAYER_H_

#include "list.h"
#include "type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _rt_layer_{
	u32 rtl_flag;	
	u16	rtl_layer;
	u16	rtl_area;
} rt_layer_t;

#ifdef __cplusplus
}
#endif

#endif
