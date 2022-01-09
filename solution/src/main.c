#include "../include/image.h"
#include "../include/bmp-image.h"
#include "../include/io-manager.h"
#include "../include/rotator.h"
#include <stdio.h>

int main( int argc, char** argv ) {
    if (input_is_incorrect(argc)) return 100;//Проверяем количество аргументов

    struct image picture; //Исходное изображение
    struct image result_picture; //Изображение-результат преобразований

    //Открываем файлы из которых читаем и куда записываем
    FILE* file = open_to_read(argv[1]);
    //if (check_file(file)) return 200; //провер очка, потом переделаю в свич-кейсы
    FILE* new_file = open_to_write(argv[2]);

    switch (from_bmp(file, &picture)) { //Читаем из файла в структуру
        case (READ_INVALID_HEADER):
            return 200;
        case (READ_ERROR):
            return 300;
        case (READ_OK):
            break;
    } 

    result_picture = rotate(&picture); //Поворачиваем

    switch (to_bmp(new_file, &result_picture)) { //Записываем результат в файл
        case (WRITE_ERROR):
            return 400;
        case (WRITE_OK):
            break;
    }

    //Закрываем файлы и освобождаем память
    fclose(file);
    fclose(new_file);

    delete_image(&picture);
    delete_image(&result_picture);

    return 0;
}
