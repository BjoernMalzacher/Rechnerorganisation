/**
 * Karlsruher Institut fuer Technologie
 * Institut fuer Technische Informatik (ITEC) 
 * Vorlesung Rechnerorganisation
 *
 * Autor: 
 * Matrikelnummer: 2353051
 * Tutoriumsnummer: 08
 * Name des Tutors: Sandro Negri
 *
 */

#include <stdio.h>
#include <stdint.h>

/**
 * Extract the sign from the floating point number (given as an uint32_t).
 *
 * \param number Number to operate on (in IEEE 754 single precision format).
 * \return Value of the sign bit (0 if the sign is positive, 1 otherwise).
 */
static int fpsign(uint32_t number)
{
    return number >> 31;
}

/**
 * Extract the mantissa from the floating point number (given as an uint32_t).
 *
 * \param number Number to operate on (in IEEE 754 single precision format).
 * \return Value of the mantisse.
 */
static int fpmantissa(uint32_t number) {
   return number & 8388607;
}

/**
 * Extract the exponent from the floating point number (given as an uint32_t).
 *
 * \param number Number to operate on (in IEEE 754 single precision format).
 * \return Value of the exponent.
 */
static int fpexponent(uint32_t number) {
    return (number &4278190080) >> 23;

}


#ifndef TEST
/**
 * main method
 * Queries the number to use as input parameter for the function calls
 *
 * \param argc unused
 * \param argv unused
 * \return returns 0
 */
int main(int argc, char* argv[])
{
    float number = 0;
    uint32_t numberuint = 0;
    
    printf("Bitte geben Sie eine Gleitkommazahl ein:\n> ");
    // for visual studio
    // scanf_s("%f", &number);
    scanf("%f", &number);
    
    numberuint = *((uint32_t*)&number);
    
    printf("Vorzeichen: %d\n", fpsign(numberuint));
    printf("Mantisse:   %d\n", fpmantissa(numberuint));
    printf("Exponent:   %d\n", fpexponent(numberuint));
    
    return 0;
}
#endif
