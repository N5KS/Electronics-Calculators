/*
 * lcfCalc.c
 *
 * Simple program to compute either resonant
 * frequency, inductance or capacitance given 
 * two of the other values.
 *
 * K. D. Sarchet
 * January 19, 2024
 *
 * Changes:
 *     January 28, 2024 Changed long doubles to doubles
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

/* Calculate F, given L and C */
double lc2f(double I, double C) {

  double F;

  F = 1.0 / (2.0 * M_PI * sqrt(I * C));
  return(F);
}

/* Calculate C, given L and F */
double lf2c(double I, double F) {

  double C;

  C = 1 / (pow(2.0 * M_PI * F, 2.0) * I);
  return(C);
}

/* Calculate L, given C and F */
double cf2l(double C, double F) {

  double I;

  I = 1 / (pow(2.0 * M_PI * F, 2.0) * C);
  return(I);
}

int main(void) {

    char answer;
    double frequency;
    double inductance;
    double capacitance;

    /* Prompt for the calculation needed */
    while(answer != 'L' && answer != 'C' && answer != 'F') {
        printf("\n        LCF Resonance Calculator\n");
        printf("What do you want to calculate (L C or F): ");
        scanf("%c", &answer);
        answer = toupper(answer);
    }

    switch(answer) {
        case 'C':
            printf("\nCalculation for capacitance\n");
            printf("Enter inductance: ");
            scanf("%lg", &inductance);
            printf("Enter frequency: ");
            scanf("%lg", &frequency);
            capacitance = lf2c(inductance, frequency);
            break;
        case 'L':
            printf("\nCalculation for inductance\n");
            printf("Enter capacitance: ");
            scanf("%lg", &capacitance);
            printf("Enter frequency: ");
            scanf("%lg", &frequency);
            inductance = cf2l(capacitance, frequency);
            break;
        case 'F':
            printf("\nCalculation for frequency\n");
            printf("Enter inductance: ");
            scanf("%lg", &inductance);
            printf("Enter capacitance: ");
            scanf("%lg", &capacitance);
            frequency = lc2f(inductance, capacitance);
	    break;
    }

    printf("\nCapacitance = %.3g\n", capacitance);
    printf("Inductance = %.3g\n", inductance);
    printf("Frequency = %.1f\n", frequency);
    printf("\n");

    return(0);
}
