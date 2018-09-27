/** @file gen_find_missing_number.c
 *
 * @brief Implement gen_find_missing_number.h functions
 *
 * @author Han Mai
 */

#include <stdio.h>
#include "gen_find_missing_number.h"
#include "gen_common.h"

void gen_find_missing_number_test(int* array, int min, int max, int* missing_num)
{
    int i = 0, value;
    if (array == NULL || min > max || missing_num == NULL) return;

    *missing_num = gen_number_between(min, max);

    i = 0;
    value = min;
    while (value <= max)
    {
        if (value != *missing_num)
        {
            array[i++] = value;
        }
        value++;
    }

    gen_shuffle_array(array, i);
}
