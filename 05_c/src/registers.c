#include "registers.h"

#include <stdio.h>

Register_t ADCCON3 = 0xa14c99f7;

void printRegister(Register_t reg)
{
    printf("0b");

    for (int i = 31; i >= 0; --i) {
        if (reg & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }

    printf("\n");
}

#define DIGEN7 (1 << 23)
#define DIGEN6 (1 << 22)
#define DIGEN0TO5 (0b111111 << 16)
#define CONCLKDIV (0b111111 << 24)
#define VREFSEL (0b111 << 13)

void setRegisters(Register_t* reg)
{
    // TODO
}

struct ADCCON3Reg {
    // TODO
};

void setRegistersStruct(Register_t* _reg)
{
    struct ADCCON3Reg* reg = _reg;
    // TODO
}
