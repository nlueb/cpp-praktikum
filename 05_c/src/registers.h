/*
 * Pseudo registers.
 */

#include <stdint.h>

typedef uint32_t Register_t;

extern Register_t ADCCON3;

/**
 * Helper function to print out the register in binary format,
 * not required from students. But can be used to check if
 * both variants (structs and bit operators) are
 * producing the correct output.
 */
void printRegister(Register_t reg);

void setRegisters(Register_t* reg);

void setRegistersStruct(Register_t* reg);
