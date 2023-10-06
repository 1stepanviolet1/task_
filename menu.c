#include <stdio.h>

#include "index_first_negative.h"
#include "index_first_negative.h"
#include "multi_between_negative.h"
#include "multi_before_and_after_negative.h"


#define STR_SIZE 65536
#define ARR_SIZE 21

char str[STR_SIZE];

size_t fill_str();
size_t fill_arr(int[]);

size_t check_arr(int[], size_t);


int main(int argc, char **argv)
{
    fill_str();

    int arr[ARR_SIZE];

    size_t len_arr = fill_arr(arr);

    size_t _f = check_arr(arr, len_arr);

    if (!_f)
    {
        printf("%s\n", "Данные некорректны");
        return 0;
    }

    switch (arr[0])
    {
    case 0:
        printf("%d\n", index_first_negative(arr, len_arr) - 1);
        break;
    
    case 1:
        printf("%d\n", index_last_negative(arr, len_arr) - 1);
        break;
    
    case 2:
        printf("%d\n", multi_between_negative(arr, len_arr));
        break;
    
    case 3:
        printf("%d\n", multi_before_and_after_negative(arr, len_arr));
        break;
    
    default:
        printf("%s\n", "Данные некорректны");
        break;

    }


    return 0;

}


size_t
fill_str()
{
    int iter = 0;

    char ch = getchar();
    while (ch != '\n')
    {
        str[iter++] = ch;
        ch = getchar();

    }
    
    str[iter] = '\0';

    return iter + 1;

}


size_t
fill_arr(int arr[])
{
    int iter_arr = 0;
    char *iter_str = str;
    int n, len;

    while (sscanf(iter_str, "%d%n", &n, &len) == 1)
    {
        arr[iter_arr++] = n;
        iter_str += len;

    }

    return iter_arr;
    
}


size_t 
check_arr(int arr[], size_t len_arr)
{
    for (size_t i = 0; i < len_arr; ++i)
    {
        if (arr[i] < 0)
            return 1;

    }

    return 0;

}

