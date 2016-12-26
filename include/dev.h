#ifndef _DEV_H_
#define _DEV_H_

#include "list.h"
#include "type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IM_DOMAIN_LEN	128 

typedef struct _im_dev_{
	s8 imd_domain[IM_DOMAIN_LEN]
	s16 imd_port;		
	u32 imd_ip;
} im_dev_t;


#ifdef __cplusplus
}
#endif

#endif
