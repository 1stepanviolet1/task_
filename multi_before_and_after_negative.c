#include "multi_before_and_after_negative.h"


int
multi_before_and_after_negative(int arr[], size_t len_arr)
{
    int mult = 1;
    int l_index = index_first_negative(arr, len_arr);
    int r_index = index_last_negative(arr, len_arr);
    size_t i;
    for ( i = 1; i < l_index; ++i)
        mult *= arr[i];

    for ( i = r_index; i < len_arr; ++i)
        mult *= arr[i];

    return mult;

}

