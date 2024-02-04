/*
 *  pvcrCalc.c
 *
 *  Calculate power, voltage, current and resistance
 *  given any 2 of the parameters.
 *
 *  K. D. Sarchet
 *  January 31, 2024
 *
 *  Changes:
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void) {
    float power, voltage, current, resistance;
    char answer;

    printf("Enter first known item (P, V, C, or R): ");
    scanf("%c", &answer);
    answer = toupper(answer);
    printf("You know this item: %c\n", answer);
    return(0);
}
