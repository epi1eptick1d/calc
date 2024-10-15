#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "calculator.c"

#define PRECISION 0.0001

void test_addition(void) {
    CU_ASSERT_DOUBLE_EQUAL(calculate(5, 6, '+'), 11, PRECISION);
}

void test_subtraction(void) {
    CU_ASSERT_DOUBLE_EQUAL(calculate(5, 6, '-'), 1, PRECISION);
}

void test_multiplication(void) {
    CU_ASSERT_DOUBLE_EQUAL(calculate(5, 6, 'x'), 1, PRECISION);
}

void test_division(void) {
    CU_ASSERT_DOUBLE_EQUAL(calculate(5, 6, '/'), 1, PRECISION);
}

void test_division_by_zero(void) {
    CU_ASSERT_DOUBLE_EQUAL(calculate(5, 0, '/'), 1, PRECISION);
    CU_ASSERT(err_code == ERR_DIV_BY_ZERO);
}

void test_unknown_operation(void) {
    CU_ASSERT_DOUBLE_EQUAL(calculate(5, 6, '^'), 0, PRECISION);
    CU_ASSERT(err_code == ERR_UNKNOWN_OPERATION);
}

int main() {
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }
    CU_basic_set_mode(CU_BRM_VERBOSE);
    // CU_basic_set_mode(CU_BRM_NORMAL);

    CU_pSuite pSuite = CU_add_suite("Simple calculator test suite", 0, 0);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_add_test(pSuite, "Addition Test", test_addition);
    CU_add_test(pSuite, "Subtraction Test", test_subtraction);
    CU_add_test(pSuite, "Multiplication Test", test_multiplication);
    CU_add_test(pSuite, "Division Test", test_division);
    CU_add_test(pSuite, "Division by Zero Test", test_division_by_zero);
    CU_add_test(pSuite, "Unknown Operation Test", test_unknown_operation);

    CU_basic_run_tests();

    CU_pFailureRecord failuresList = CU_get_failure_list();
    CU_basic_show_failures(failuresList);
    printf("\n");

    CU_cleanup_registry();

    if (failuresList != NULL) {
        return 1;
    }

    return CU_get_error();
}

