//
// Created by isy02 on 02.12.2021.
//

#include "../include/image.h"
#include <inttypes.h>
#include <malloc.h>

void delete_image(struct image* image) {
    free(image->data);
}
