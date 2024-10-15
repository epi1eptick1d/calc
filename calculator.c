#define ERR_UNKNOWN_OPERATION 1
#define ERR_DIV_BY_ZERO 2

int err_code = 0;

double calculate(double num1, double num2, char operation) {
    err_code = 0;

    double result;
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case 'x':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                err_code = ERR_DIV_BY_ZERO;
                return 0;
            }
            result = num1 / num2;
            break;
        default:
            err_code = ERR_UNKNOWN_OPERATION;
            return 0;
    }
    return result;
}

