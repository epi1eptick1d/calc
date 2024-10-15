#include <stdio.h>
#include <stdlib.h>

#include "calculator.c"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <number1> <operation> <number2>\n", argv[0]);
        return 1;
    }

    double num1 = atof(argv[1]);
    char operation = argv[2][0];
    double num2 = atof(argv[3]);

    double result = calculate(num1, num2, operation);
    if (err_code != 0) {
         printf("Error: ");
         switch (err_code) {
             case ERR_UNKNOWN_OPERATION:
                 printf("unknown operation");
                 break;
             case ERR_DIV_BY_ZERO:
                 printf("devision by 0");
                 break;
         }
         printf("\n");
    } else {
        printf("%f\n", result);
    }
    return 0;
}

