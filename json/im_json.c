#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <event2/event.h>
#include <event2/event_struct.h>
#include "type.h"
#include "im_event.h"

struct event_base* s_base; 

static int json_get_s32(s32 *dst, json_t *json, char *key)
{
        json_t *jval = NULL;
	assert(json && dst && key);

        jval = json_object_get(json, key);
        if (!jval || !json_is_integer(jval)){
                return IM_FAIL;
        }

        *dst = (s32)json_integer_value(jval);
        return IM_SUCCESS;
}

static int json_get_u32(u32 *dst, json_t *json, char *key)
{
        json_t *jval = NULL;
	assert(json && dst && key);

        jval = json_object_get(json, key);
        if (!jval || !json_is_integer(jval)){
                return IM_FAIL;
        }

        *dst = (u32)json_integer_value(jval);
        return IM_SUCCESS;
}

static int json_get_u16(u16 *dst, json_t *json, char *key)
{
        json_t *jval = NULL;
	assert(json && dst && key);

        jval = json_object_get(json, key);
        if (!jval || !json_is_integer(jval)){
                return IM_FAIL;
        }

        *dst = (u16)json_integer_value(jval);
        return IM_SUCCESS;
}


static int json_get_string(char *dst_buf, int *dst_buf_len, json_t *json, char *key)
{
        json_t *jval = NULL;
	const char *str = NULL;
	assert(json && dst_buf && key);

        jval = json_object_get(json, key);
        if (!jval || !json_is_string(jval)){
                return IM_FAIL;
        }
	str = json_string_value(jval);
	if (!str) {
                return IM_FAIL;
	}

        memcpy(dst_buf, str, strlen(str) + 1);
	if (dst_buf_len) {
		*dst_buf_len = strlen(str);
	}

        return IM_SUCCESS;
}


int im_json_prev_dispose_key(json_t *array, im_dev_t **devs, u32 *len)
{
	int ret = 0;
	u32 i = 0;
	s32 size = 0;
	json_t *obj = NULL;
	im_dev_t *dev_s = NULL;
	im_dev_t *tmp_dev = NULL;

	if (!json_is_array(array)) {
		return IM_FAIL;
	}
	size = json_array_size(array);
	if (size <= 0) {
		return IM_FAIL;
	}

	dev_s = calloc(size, sizeof(im_dev_t));
	if (!dev_s) {
		return IM_FAIL;
	}

	for (i = 0; i < size; i++) {
		tmp_dev = &dev_s[i];
		obj = json_array_get(array, i);
		ret = json_get_string(tmp_dev->imd_domain, NULL, obj, "addr");
		ret |= json_get_u16(&tmp_dev->imd_port, obj, "port");
		if (ret) {
			goto out;
		}
	}

	*len = size;
	*devs = dev_s;
	return 0;
out:
	free(dev_s);
	return ret;
}





int im_json_next_dispose_key(json_t *array, im_dev_t **devs, u32 *len)
{
	return im_json_prev_dispose_key(array, devs, len);
}

