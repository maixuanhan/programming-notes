/** @file gen_find_missing_number.h
 *
 * @brief Generate an array of 99 element whose value is from 1 to 100,
 *        one value is missing.
 *
 * @author Han Mai
 */

#ifndef GEN_FIND_MISSING_NUMBER_TESTCASE
#define GEN_FIND_MISSING_NUMBER_TESTCASE

#ifdef __cplusplus
extern "C" {
#endif

/* The array should be able contain minimum of (max - min) elements */
void gen_find_missing_number_test(int* array, int min, int max, int* missing_num);

#ifdef __cplusplus
}
#endif

#endif // GEN_FIND_MISSING_NUMBER_TESTCASE
