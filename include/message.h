#ifndef _RT_MESSAGE_H_
#define _RT_MESSAGE_H_

#include "list.h"
#include "type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MANAGE_MESSAGE_TYPE	0x01
#define DATA_MESSAGE_TYPE	0x00

typedef struct _base_message_{
#if 0
IM_DEV_TYPE_ROUTE	0x01
IM_DEV_TYPE_VIDEO	0x02
IM_DEV_TYPE_DISPOSE	0x03
#endif

        u32  bm_from_dev_type_flag:4,
        	bm_message_type_flag:1,
		:27;
	union {
		u8 bm_from_layer;
		u8 bm_from_area;
	};
} im_base_message_t;


typedef struct _manage_message_{
	im_base_message_t mm_base;
	s8 mm_msg[0];	
} im_manage_message_t;

typedef struct _data_message_{
	im_base_message_t dm_base;
	s8 mm_msg[0];	
} im_data_message_t;


#ifdef __cplusplus
}
#endif

#endif
