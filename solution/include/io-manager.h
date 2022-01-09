//
// Created by isy02 on 02.12.2021.
//

#ifndef UNTITLED_IO_MANAGER_H
#define UNTITLED_IO_MANAGER_H
#include <stdbool.h>

bool input_is_incorrect(int argc);
void print_error(const char* message);
FILE* open_to_read(const char* filename);
FILE* open_to_write(const char* filename);
bool check_file(FILE* file);

#endif //UNTITLED_IO_MANAGER_H
