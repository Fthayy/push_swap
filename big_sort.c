#include <stdio.h>
#include "push_swap.h"

// B'deki locunu bul A'ya gitmesi icin kac adım gerektigine bak. Diger sayıya gec locunu bul A'ya gitmesi icin
// kac adım gitmesi gerektigini bul onceki adımdan daha kucukse bunu genel adım yap. En sonda en az adım 
// gerektirenin konumu size/2'den buyukse rra ile kucukse ra ile en uste al ve A'daki yerine pushla.
// Egere hem A'daki yeriyle B'deki yerinin size / 2 kısımı aynı taraftaysa konumu gelene kadar veya en uste
// gelene kadar rrr veya rr yap.

int FindRank(int *sortednumbers,int nb)
{   
    int i = 0;
    while (i < 500)
    {
        if (nb == sortednumbers[i])
            return (i);
        // printf("%d",i);
        // printf("sortednumbers[i]=%d\n",sortednumbers[i]);
        i++;
    }
    return (0);
}

int ft_loc(int *sortednumbers, t_holder *hold,int rank) // AMAC gonderilen sayının rankından kucuk ve yakın olan sortednumbers degerini bulmak
{
    int ret;
    int i;
    t_stack *tmp2;
    t_stack *tmp3;
    int x;

    tmp3 = hold->a;
    tmp2 = hold->b;
    ret = 500;
    i = 0;
    while (i < hold->a_size)
    {
        // printf("check:%d\n",(FindRank(sortednumbers,tmp3->nb) - rank));
        if (((FindRank(sortednumbers,tmp3->nb) - rank < ret - rank)) && ((FindRank(sortednumbers,tmp3->nb) - rank) > 0))  
        {
            ret = FindRank(sortednumbers,tmp3->nb);
            x = i;
        }
        i++;
        tmp3 = tmp3->next;
    }
    return(x);
}




t_location FindLoc(int *sortednumbers,t_holder *hold)
{
    t_stack *tmp;
    t_location location;
    int x;

    x = hold->b_size;
    tmp = hold->b;
    location.rank = 0;
    location.tmp_rank = 0;
    location.place = 0;
    location.tmp_place = 0;
    while (x > 0)
    {
        printf("tmpnb:%ld\n",tmp->nb);
        location.rank = FindRank(sortednumbers,tmp->nb);
        printf("location.rank:%d\n",location.rank);
        location.place = ft_loc(sortednumbers,hold,location.rank);
        printf("location.place:%d\n",location.place);
        if ((location.rank + location.place < location.tmp_rank + location.tmp_place) || (location.tmp_place + location.tmp_rank == 0))
        {
            location.tmp_rank = location.rank;
            location.tmp_place = location.place;
        }
        tmp = tmp->next;
        x--;
    }
    return(location);
}

void findAPlace(t_holder *hold,t_location location) // Location bulup B'yi pushladıktan sonra ne yapacak belli degil ?
{
    int i = 0;
    while (hold->a_size != 0) // A bitmedigi surece ???????
    {
        if (location.rank > hold->b_size / 2) // eger A'nin ortasından asagidaysa rra kullan
        {
            while (i++ < hold->b_size - location.rank)
                rra(hold->a);
        }
        else // eger A'nin ortasından yukarıdaysa ra kullan
        {
            while (i++ < location.rank)
                ra(hold->a);
        }
        findAPlace(hold,location);
    }
}

void ft_PushBtoA(t_holder *hold,int *sortednumbers)
{
    // int i = 0;  
    // int x = 0;
    t_location location;
    location = FindLoc(sortednumbers,hold);
    // while (x++ < hold->b_size) // B bitmedigi surece || burayı fixlemen lazım 
    // {
    //     if (location.rank > hold->b_size / 2) // eger B'nin ortasından asagidaysa rra kullan
    //     {
    //         while (i++ < hold->b_size - location.rank)
    //             rrb(hold->b);
    //     }
    //     else // eger B'nin ortasından yukarıdaysa ra kullan
    //     {
    //         while (i++ < location.rank)
    //             rb(hold->b);
    //     }
    //     findAPlace(hold,location);
    //     pb(hold); // Deger en yukarı geldikten sonra A'ya pushla
    // }
}

void big_sort(t_holder *hold,int *numeros,int size,t_longest longest,int *sortednumbers)
{
    t_stack *tmp;
    int i = 0;
    int x = 0;
    tmp = hold->a;
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
    ft_PushBtoA(hold,sortednumbers); // B'den A'ya pushlama asamasi
}