//
// Created by isy02 on 02.12.2021.
//

#ifndef UNTITLED_IMAGE_H
#define UNTITLED_IMAGE_H
#include <inttypes.h>

struct pixel { uint8_t b, g, r; };

struct image {
    uint64_t width, height;
    struct pixel* data;
};

void delete_image(struct image* image);

#endif //UNTITLED_IMAGE_H
