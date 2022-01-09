//
// Created by isy02 on 03.12.2021.
//

#ifndef UNTITLED_BMP_IMAGE_H
#define UNTITLED_BMP_IMAGE_H

#include "image.h"
#include <inttypes.h>
#include <stdio.h>

#pragma pack(push, 1)
struct bmp_header {
    uint16_t bfType;
    uint32_t bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;//кол-во плоскостей - 1
    uint16_t biBitCount;
    uint32_t biCompression;//сжатие
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;//разрешение устр-ва вывода
    uint32_t biYPelsPerMeter;//разрешение устр-ва вывода
    uint32_t biClrUsed;//цвета из таблицы (0)
    uint32_t biClrImportant;//кол-во важных цветов (все важные - 0)
};
#pragma pack(pop)

/*  deserializer   */
enum read_status  {
    READ_OK = 0,
    READ_INVALID_HEADER,
    READ_ERROR
    /* коды других ошибок  */
};

enum read_status from_bmp( FILE* file, struct image* image );

/*  serializer   */
enum  write_status  {
    WRITE_OK = 0,
    WRITE_ERROR
    /* коды других ошибок  */
};

enum write_status to_bmp( FILE* file, struct image const* image );

#endif //UNTITLED_BMP_IMAGE_H
