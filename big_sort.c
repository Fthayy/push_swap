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

int howbig(int size,int nb)
{
    if (nb > size / 2)
        return(size - nb);
    return(nb);
}

t_location FindLoc(int *sortednumbers,t_holder *hold)
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
    while (x > 0)
    {
        z = howbig(hold->b_size,i);
        // printf("tmpnb:%ld\n",tmp->nb);
        location.rank = FindRank(sortednumbers,tmp->nb); // asagıdaki if blokunda kullanmayacagız location.place'de isimize yarıyor if blogu icin farklı bir fonk yaz.
        // printf("location.rank:%d\n",location.rank);
        location.place = howbig(hold->a_size,ft_loc(sortednumbers,hold,location.rank)); // kullanacagımız veri ama size/2'den buyuk olma durumunu da hesapla
        // printf("location.place:%d\n",location.place);
        if ((z + location.place < z + location.tmp_place) || (location.tmp_place + z == 0))
        {   
            location.holdplace = ft_loc(sortednumbers,hold,location.rank); // asagıda kullan
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

void PushHelper(int rank,int place,t_holder *hold)
{
    int i;

    i = 0;
    if (rank > place)
    {
        while (i < rank - place)
        {
            rra(hold->a);
        }
    }
    if (rank < place)
    {
        while (i < place - rank)
        {
            rrb(hold->b);
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
void ft_PushBtoA(t_holder *hold,int *sortednumbers)
{
    int i = 0;  
    int x = 0;
    t_location location;
     while (x++ < hold->b_size) 
     { 
        location = FindLoc(sortednumbers,hold);
        if (location.holdrank > hold->b_size / 2 && location.holdplace > hold->b_size)
        {
            while (i++ < WhichOneBigger(location.holdplace,location.holdplace))
                rrr(hold->a,hold->b);
            PushHelper(location.holdrank,location.holdplace,hold);
        }
        else if (location.holdrank < hold->b_size / 2 && location.holdplace < hold->b_size)
        {
            while (i++ < WhichOneBigger(location.holdplace,location.holdplace))
                rr(hold->a,hold->b);
            PushHelper2(location.holdrank,location.holdplace,hold);
        }
        // pb(hold); // Deger en yukarı geldikten sonra A'ya pushla
    }
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