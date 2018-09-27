/** @file gen_common.h
 *
 * @brief Common code for test case generator
 *
 * @author Han Mai
 */

#ifndef GEN_COMMON
#define GEN_COMMON

#ifdef __cplusplus
extern "C" {
#endif

int gen_number_between(int min, int max);
void gen_shuffle_array(int* array, int size);

#ifdef __cplusplus
}
#endif

#endif // GEN_COMMON
