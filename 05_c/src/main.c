#include "registers.h"
#include "strings.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    char** buffer = (char**)malloc(32);
    const char* src = "Test;;;;123";
    const size_t count = split(buffer, src, ";;");
}
