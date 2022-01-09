//
// Created by isy02 on 02.12.2021.
//

#include <stdbool.h>
#include <stdio.h>

void print_error(const char *message) {
    fprintf(stderr, "%s\n", message);
}

bool input_is_incorrect(int argc) {
    if (argc != 3) {
        print_error("Incorrect input");
    }
    return (argc != 3);
}

FILE* open_to_read(const char* filename) {
    return fopen(filename, "rb");
}

FILE* open_to_write(const char* filename) {
    return fopen(filename, "wb");
}

bool check_file(FILE* file) {
    if (!file) {
        print_error("File cannot found");
    }
    return (!file);
}

