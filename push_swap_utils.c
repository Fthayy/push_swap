#include <stdio.h>
#include "push_swap.h"

// find_last_five(t_stack *a)
// {

// }

int *BubbleSort(int *numeros,int size)
{
    int i; 
    int tmp;

    while (size >= 0)
    {
        i = 0;
        while (i < size - 1)
		{
            if (numeros[i] > numeros [i+1])
            {
                tmp = numeros[i];
                numeros[i] = numeros[i+1];
                numeros[i+1] = tmp;
            }
            i++;
        }
        size--;
    }
    return (numeros);
}