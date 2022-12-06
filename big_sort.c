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

int ft_loc(int *sortednumbers, t_holder *hold,int rank,int size) 
{
    int ret;
    int i;
    t_stack *tmp3;
    int x;
    size = 3;

    tmp3 = hold->a;
    ret = 500;
    i = 0;
    // printf("ilk:%d\n",sortednumbers[rank]);
    // printf("iki:%ld\n",ft_lstlastnmb(hold->a)->nb);
    if (sortednumbers[rank] > ft_lstlastnmb(hold->a)->nb)
    {
        // printf("check");
        return(hold->a_size);
    }
    while (i < hold->a_size)
    {
        if (((FindRank(sortednumbers,tmp3->nb) - rank < ret - rank)) && ((FindRank(sortednumbers,tmp3->nb) - rank) > 0))  
        {
            // printf("iceri:%d\n",i);
            ret = FindRank(sortednumbers,tmp3->nb);
            x = i;
        }
        i++;
        tmp3 = tmp3->next;
    }
    // printf("x:%d\n",x);
    return(x);
}

int howbig(int size,int nb)
{
    if (nb > size / 2)
        return(size - nb);
    return(nb);
}
t_location FindLoc(int *sortednumbers,t_holder *hold,int size)
{
    t_stack *tmp;
    t_location location;
    int x;
    int i;
    int z;
    i = 0;

    x = hold->b_size;
    tmp = hold->b;
    location.rank = 0;
    location.tmp_rank = 0;
    location.place = 0;
    location.tmp_place = 0;
    while (tmp != NULL)
    {
        z = howbig(hold->b_size,i);
        // printf("tmpnb:%ld\n",tmp->nb);
        location.rank = FindRank(sortednumbers,tmp->nb); 
        // printf("location.rank:%d\n",location.rank);
        location.place = howbig(hold->a_size,ft_loc(sortednumbers,hold,location.rank,size)); // kullanacagımız veri ama size/2'den buyuk olma durumunu da hesapla
        // printf("location.place:%d\n",location.place);
        if ((z + location.place < z + location.tmp_place) || (location.tmp_place + z == 0))
        {   
            location.holdplace = ft_loc(sortednumbers,hold,location.rank,size); // asagıda kullan
            location.holdrank = i; // asagida kullan
            location.tmp_rank = z;
            location.tmp_place = location.place;
        }
        tmp = tmp->next;
        x--;
        i++;
    }
    return(location);
}

int WhichOneBigger(int nb1,int nb2)
{
    if (nb1 > nb2)
        return(nb2);
    return(nb1);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void PushHelper(int rank,int place,t_holder *hold)
{
    int i;

    i = 0;
    if (rank > place)
    {
        while (i < rank - place)
        {
            rra(hold);
        }
    }
    if (rank < place)
    {
        while (i < place - rank)
        {
            rrb(hold);
        }
    }
}

void PushHelper2(int rank,int place,t_holder *hold)
{
    int i;

    i = 0;
    if (rank > place)
    {
        while (i < rank - place)
        {
            ra(hold->a);
            i++;
        }
    }
    if (rank < place)
    {
        while (i < place - rank)
        {
            rb(hold->b);
            i++;
        }
    }
}
void ft_PushBtoA(t_holder *hold,int *sortednumbers,int size)
{
    int i = 0;  
    t_location location;
     while (hold->b_size > 0) 
     { 
        i = 0;
        location = FindLoc(sortednumbers,hold,size);
        // // printf("tmpnb:%ld\n",hold->b->next->nb);
        //  printf("location.place:%d\n",location.holdplace);
        //  printf("location.rank:%d\n",location.holdrank);
        // // // if (location.holdrank > hold->b_size / 2 && location.holdplace > hold->a_size / 2)
        // // {
        // //     while (i++ < WhichOneBigger(location.holdplace,location.holdplace))
        // //         rrr(hold);
        // //     PushHelper(location.holdrank,location.holdplace,hold);
        // // }
        // // else if (location.holdrank < hold->b_size / 2 && location.holdplace < hold->a_size / 2)
        // // {
        // //     while (i++ < WhichOneBigger(location.holdplace,location.holdplace))
        // //         rr(hold->a,hold->b);
        // //     PushHelper2(location.holdrank,location.holdplace,hold);
        // // }
        // // else
        while (i++ < location.holdrank)
            rb(hold->b);
        i = 0;
        while (i++ < location.holdplace)
            ra(hold->a);
        hold = pa(hold); // Deger en yukarı geldikten sonra A'ya pushla
        i = 0;
        while (i++ < location.holdplace)
            hold->a = rra(hold);
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void big_sort(t_holder *hold,int *numeros,int size,t_longest longest,int *sortednumbers)
{
    t_stack *tmp;
    int i = 0;
    int x = 0;
    int y = 0;
    tmp = hold->a;
    while(i < size - (longest.tmpend - longest.tmpstart))
    {
        if (hold->a->nb < numeros[longest.tmpstart])
        {
            if (y == 0 && hold->a->nb < numeros[longest.tmpstart])
            {    
                ra(hold->a);
                y = 1;
            }  
            else if (y == 1 && hold->a->nb > ft_lstlastnmb(hold->a)->nb)
            {    
                ra(hold->a);
                y = 1;
            }  
            else
                hold = pb(hold);
        }
        else if (hold->a->nb == numeros[longest.tmpstart])
            while (x < longest.tmpend - longest.tmpstart + 1)
            {
                ra(hold->a);
                x++;
                y = 1;
            }
        else
            hold = pb(hold);
        i++;
    }
    ft_PushBtoA(hold,sortednumbers,size); // B'den A'ya pushlama asamasi
}