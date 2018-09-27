/** @file gen_common.c
 *
 * @brief Implement gen_common.h functions
 *
 * @author Han Mai
 */

#include "gen_common.h"
#include <stdlib.h>
#include <time.h>

static int _gen_initialized_ = 0;
static void gen_init();
static void swap(int* a, int* b);

static void gen_init()
{
    if (!_gen_initialized_)
    {
        srand(time(NULL));
        _gen_initialized_ = 1;
    }
}

static void swap(int* a, int* b)
{
    int t;
    if (a == NULL || b == NULL) return;
    t = *a;
    *a = *b;
    *b = t;
}

int gen_number_between(int min, int max)
{
    gen_init();
    return rand() % (max - min + 1) + min;
}

void gen_shuffle_array(int* array, int size)
{
    int i, temp_index;

    if (array == NULL) return;

    for (i = 0; i < size; ++i)
    {
        temp_index = gen_number_between(0, size - 1);
        swap(&array[i], &array[temp_index]);
    }
}
