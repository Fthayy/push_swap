#include <stdio.h>
#include "push_swap.h"

// find_last_five(t_stack *a)
// {

// }

t_longest while_loop(t_longest longest,int size,int *numeros,int i)
{
    while (i != size)
    {
        while (i != size && numeros[i] > numeros[i+1])
        {
          i++;
          longest.end++;
          longest.start++;
        }
        while (i != size &&numeros[i] < numeros[i+1])
        {
            longest.end += 1;
            i++;
        }
        if ((longest.end - longest.start >= longest.tmpend - longest.tmpstart) || longest.tmpend == 0)
        {
            longest.tmpend = longest.end;
            longest.tmpstart = longest.start;
        }
        longest.start = longest.end;
    }
    return(longest);
}

void find_longest(int *numeros,int size)
{
    t_longest longest;
    int i;

    longest.start = 0;
    longest.end = 0;
    longest.tmpend = 0;
    longest.tmpstart = 0;
    i = 0;

    size = size - 1;
    longest = while_loop(longest,size,numeros,i);
}

int *BubbleSort(int *numeros,int size)
{
    int i; 
    int tmp;
    int *snumbers;
    snumbers = ft_sort_number(numeros,size);
    while (size >= 0)
    {
        i = 0;
        while (i < size - 1)
		{
            if (snumbers[i] > snumbers [i+1])
            {
                tmp = snumbers[i];
                snumbers[i] = snumbers[i+1];
                snumbers[i+1] = tmp;
            }
            i++;
        }
        size--;
    }
    return (snumbers);
}

int *ft_sort_number(int *numeros,int size)
{
    int i = 0;
    int *sortednumbers;
    sortednumbers = malloc(sizeof(int)*size);
    while(i < 5)
    {
        sortednumbers[i] = numeros[i];
        i++;
    }  
    return(sortednumbers);
}
