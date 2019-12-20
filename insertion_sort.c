#include <stdio.h>

void shift_element (int *arr, int i)
{
    arr = arr+(i-1);
    for (int ind=0; ind<i; ind++)
    {
        *(arr + 1) = *arr;
        arr--;
    }
}

void insertion_sort (int *arr, int len)
{
    for(int ind1=0; ind1<len-1; ind1++)
    {
        if (*(arr+ind1) < *(arr+ind1+1))
        {
            continue;
        }
        else
        {
            int temp=*(arr+ind1+1);
            int i=0;
            while (temp<*(arr+ind1-i) && (ind1-i) >= 0)
            {
              i++;
            }
            shift_element(arr+ind1-i+1, i);
            *(arr+ind1-i+1)=temp; 
        }
    }
}