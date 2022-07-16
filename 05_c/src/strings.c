#include "strings.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenate(const char* a, const char* b)
{
    const size_t len_a = strlen(a);
    const size_t len_b = strlen(b);
    // Plus 1 for \0 termination
    char* const result = (char*)malloc(len_a + len_b + 1);
    strcpy(result, a);
    strcpy(result + len_a, b);
    return result;
}

int split(char** dest, const char* src, const char* split_str)
{
    const size_t len_split_str = strlen(split_str);

    size_t number_of_parts = 0;
    size_t number_of_bytes_to_copy = 0;
    char* location = NULL;

    do {
        location = strstr(src, split_str);
        if (location == NULL)
            number_of_bytes_to_copy = strlen(src);
        else
            number_of_bytes_to_copy = location - src;
        dest[number_of_parts] = (char*)malloc(number_of_bytes_to_copy + 1);
        if (number_of_bytes_to_copy > 0)
            strncpy(dest[number_of_parts], src, number_of_bytes_to_copy);
        dest[number_of_parts][number_of_bytes_to_copy] = '\0';
        src += number_of_bytes_to_copy + len_split_str;
        number_of_parts++;
    } while (location);

    // Pointer is no longer useable
    src = NULL;

    return number_of_parts;
}
