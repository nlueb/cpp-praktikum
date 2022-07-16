#include "registers.h"

#include <stdint.h>
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
        if (i % 4 == 0 && i != 0) {
            printf("_");
        }
    }

    printf("\n");
}
#define _DIGEN7 (1 << 23)
#define _DIGEN6 (1 << 22)
#define _DIGEN0TO5 (0b111111 << 16)
#define _CONCLKDIV (0b111111 << 24)
#define _VREFSEL (0b111 << 13)

void setRegisters(Register_t* reg)
{
    // Clear Digital Enable 0-5
    *reg &= ~_DIGEN0TO5;
    *reg |= _DIGEN6 + _DIGEN7;
    // Clear Clock
    *reg &= ~_CONCLKDIV;
    *reg |= (30 << 24);
    // Clear Voltage Reference
    *reg &= ~_VREFSEL;
    *reg |= (0b110 << 13);
}

struct ADCCON3Reg {
    uint32_t ADINSEL : 6;
    uint32_t GSWTRG : 1;
    uint32_t GLSWTRG : 1;
    uint32_t RQCNVRT : 1;
    uint32_t SAMP : 1;
    uint32_t UPDRDY : 1;
    uint32_t UPDIEN : 1;
    uint32_t TRGSUSP : 1;
    uint32_t VREFSEL : 3;
    uint32_t DIGEN : 8;
    uint32_t CONCLKDIV : 6;
    uint32_t ADCSEL : 2;
};

#define BITAT(pos) (1 << pos)

void setRegistersStruct(Register_t* _reg)
{
    struct ADCCON3Reg* reg = (struct ADCCON3Reg*)_reg;
    reg->DIGEN = BITAT(6) | BITAT(7);
    reg->CONCLKDIV = 30;
    reg->VREFSEL = 0b110;
}
