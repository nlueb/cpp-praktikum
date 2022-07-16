#include "registers.h"
#include "strings.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    const char* a = "test";
    const char* b = "123";
    const char* result = concatenate(a, b);
    printf("%s\n", result);
    char** buffer = (char**)malloc(32);
    const char* src = "Test;;;;123";
    const size_t count = split(buffer, src, ";;");
    printf("%d\n", count);

    printRegister(ADCCON3);

#ifdef USE_STRUCTS
    setRegistersStruct(&ADCCON3);
#else
    setRegisters(&ADCCON3);
#endif

    printRegister(ADCCON3);
}
