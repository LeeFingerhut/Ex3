#include <stdio.h>
#include "insertion_sort.h"

#define ARR_LENGTH 50

void print_arr(int *arr, int len)
{
    for(int i=0; i<len; i++)
    {
        if(i==len-1)
        {
            printf("%d", arr[i]);
        }
        else
        {
            printf("%d,", arr[i]);
        }    
    }
    printf("\n");
}


int main()
{
    int arr[ARR_LENGTH] = {0};
    for(int i=0; i<ARR_LENGTH; i++)
    {
        if (scanf ("%d", (arr+i)) != 1)
        {
            printf ("Error, exiting\n");
            return 1;
        }
    }
    insertion_sort(arr, ARR_LENGTH);
    print_arr(arr, ARR_LENGTH);
    return 0;
}
