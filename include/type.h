#ifndef _TYPE_H_
#define _TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef unsigned char u8;

typedef int64_t s64;
typedef int32_t s32;
typedef int16_t s16;
typedef char s8;

#define IM_FAIL 1
#define IM_SUCCESS 0

#define IM_AREA_MAX	128

#define IM_DEV_TYPE_ROUTE	0x01
#define IM_DEV_TYPE_AREA	0x02
#define IM_DEV_TYPE_VIDEO	0x03
#define IM_DEV_TYPE_DISPOSE	0x04

#ifdef __cplusplus
}
#endif

#endif



