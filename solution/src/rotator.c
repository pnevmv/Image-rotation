//
// Created by isy02 on 05.12.2021.
//

#include "../include/rotator.h"
#include "../include/image.h"
#include <stdlib.h>

struct image rotate(struct image const* image) {
    //Чтобы не перепутать, меняем ширину и высоту местами
    size_t height = image->width;
    size_t width = image->height;

    struct image result = {
            .width = width,
            .height = height,
            .data = malloc(sizeof(struct pixel) * image->width * image->height)
    };

    for (size_t i = 0; i < image->width; i++) {
        for (size_t j = 0; j < image->height; j++) {
            result.data[i * result.width + j] =  image->data[(image->height - 1 - j) * image->width + i];
        }
    }

    return result;
}
