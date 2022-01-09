//
// Created by isy02 on 02.12.2021.
//

#include "../include/bmp-image.h"
#include "../include/image.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t get_padding(uint32_t width) {
    return (width % 4);
}

static bool check_header( struct bmp_header* header ) {
    return (header->bfType != 0x4d42 || header->biBitCount != 24);
}

static void write_data(FILE* file, struct image const* image) {
    const size_t FILL = 0;
    for (size_t i = 0; i < image->height; i++) {
        fwrite(&(image->data[i * image->width]),sizeof(struct pixel), image->width, file);
        fwrite(&FILL, 1, get_padding(image->width), file);
    }
}

static void read_data(struct bmp_header* header, FILE* file, struct image const* image) {
    for (size_t i = 0; i < header->biHeight; i++) {
        fread(&(image->data[i * image->width]), sizeof(struct pixel), header->biWidth, file);
        fseek( file, get_padding(header->biWidth), SEEK_CUR);
    }
}

static struct bmp_header fill_header(struct image const* image) {
    return (struct bmp_header) {
            .bfType = 0x4D42,//0x4D42 - бмп
            .bfileSize = (sizeof(struct bmp_header) +
                    image->height * image->width * sizeof(struct pixel) +
                    image->height * get_padding(image->width)),//реальный размер файла
            .bOffBits = sizeof(struct bmp_header),
            .biSize = 40,//размер структуры
            .biWidth = image->width,//ширина картинки
            .biHeight = image->height,//высота картинки
            .biBitCount = 24,//24-битные пикселы
            .biSizeImage = image->height * image->width * sizeof(struct pixel) +
                    get_padding(image->width) * image->height,//размер картинки в байтах
    };
}

enum read_status from_bmp(FILE* file, struct image* image){
    if (!file || !image) return READ_ERROR;
    struct bmp_header* header = malloc(sizeof(struct bmp_header));//память под шапку
    fread(header, sizeof(struct bmp_header), 1, file);
    if (check_header(header)) return READ_INVALID_HEADER;

    image->data = malloc(sizeof(struct pixel) * header->biWidth * header->biHeight);//память под данные
    image->width = header->biWidth;
    image->height = header->biHeight;

    read_data(header, file, image);
    
    free(header);
    return READ_OK;
}

enum write_status to_bmp(FILE* file, struct image const* image) {
    if (!file || !image) return WRITE_ERROR;
    struct bmp_header header = fill_header(image);//заполняем шапку
    if (check_header(&header)) return WRITE_ERROR;//проверяем шапку
    fwrite(&header, sizeof(struct bmp_header), 1, file);

    write_data(file, image);
    return WRITE_OK;
}
