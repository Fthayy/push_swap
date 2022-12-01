#include <stdio.h>
#include "push_swap.h"

// B'deki locunu bul A'ya gitmesi icin kac adım gerektigine bak. Diger sayıya gec locunu bul A'ya gitmesi icin
// kac adım gitmesi gerektigini bul onceki adımdan daha kucukse bunu genel adım yap. En sonda en az adım 
// gerektirenin konumu size/2'den buyukse rra ile kucukse ra ile en uste al ve A'daki yerine pushla.
// Egere hem A'daki yeriyle B'deki yerinin size / 2 kısımı aynı taraftaysa konumu gelene kadar veya en uste
// gelene kadar rrr veya rr yap.

int FindRank(int *sortednumbers,t_holder *hold)
{
    t_stack *tmp = hold->b;
    int i = 0;
    while (i < 15)
    {
        if (tmp->nb == sortednumbers[i])
            return (i);
        i++;
    }
    return (0);
}

int ft_loc(int *sortednumbers,int rank,t_holder *hold)
{
    int i = 0;
    t_stack *tmp = hold->a;
    while(hold->a_size != 0)
    {
        if(sortednumbers[rank] == tmp->nb)
        {
            if (i > hold->a_size / 2)
                return (hold->a_size - i);
            return(i);
        }
        tmp = tmp->next;
        i++;
    }
    return (0);
}



t_location FindLoc(int *sortednumbers,t_holder *hold)
{
    t_stack *tmp;
    t_location location;

    tmp = hold->b;
    location.rank = 0;
    location.tmp_rank = 0;
    location.place = 0;
    location.tmp_place = 0;
    while (hold->b_size != 0)
    {
        location.rank = FindRank(sortednumbers,hold);
        location.place = ft_loc(sortednumbers,location.rank,hold);
        if ((location.rank + location.place < location.tmp_rank + location.tmp_place) ||(location.tmp_place + location.tmp_rank == 0))
        {
            location.tmp_rank = location.rank;
            location.tmp_place = location.place;
        }
        tmp = tmp->next;
    }
    return(location);
}

// void findAPlace(t_holder *hold,t_location location) // Location bulup B'yi pushladıktan sonra ne yapacak belli degil ?
// {
//     int i = 0;
//     while (hold->a_size != 0) // A bitmedigi surece ???????
//     {
//         if (location.rank > hold->b_size / 2) // eger A'nin ortasından asagidaysa rra kullan
//         {
//             while (i++ < hold->b_size - location.rank)
//                 rra(hold->a);
//         }
//         else // eger A'nin ortasından yukarıdaysa ra kullan
//         {
//             while (i++ < location.rank)
//                 ra(hold->a);
//         }
//         findAPlace(hold,location);
//     }
// }

void ft_PushBtoA(t_holder *hold,int *sortednumbers)
{
    int i = 0;
    t_location location;
    location = FindLoc(sortednumbers,hold);
    while (hold->b_size != 0) // B bitmedigi surece
    {
        if (location.rank > hold->b_size / 2) // eger B'nin ortasından asagidaysa rra kullan
        {
            while (i++ < hold->b_size - location.rank)
                rrb(hold->b);
        }
        else // eger B'nin ortasından yukarıdaysa ra kullan
        {
            while (i++ < location.rank)
                rb(hold->b);
        }
        findAPlace(hold,location);
        pb(hold); // Deger en yukarı geldikten sonra A'ya pushla
    }
}

void big_sort(t_holder *hold,int *numeros,int size,t_longest longest,int *sortednumbers)
{
    t_stack *tmp;
    int i = 0;
    int x = 0;
    tmp = hold->a;
    sortednumbers = numeros;
    while(i < size - (longest.tmpend - longest.tmpstart))
    {
        if (hold->a->nb < numeros[longest.tmpstart])
        {
            if (hold->b_size == 0 && hold->a->nb < numeros[longest.tmpstart])
                ra(hold->a);
            else if (hold->b_size != 0 && hold->a->nb > ft_lstlastnmb(hold->a)->nb)
                ra(hold->a);
            else
                pb(hold);
        }
        else if (hold->a->nb == numeros[longest.tmpstart])
            while (x < longest.tmpend - longest.tmpstart + 1)
            {
                ra(hold->a);
                x++;
            }
        else
            pb(hold); 
        i++;
    }
    // ft_PushBtoA(hold,sortednumbers); // B'den A'ya pushlama asamasi
}