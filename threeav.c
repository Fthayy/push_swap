char *ft_threeav(char *a)
{
    if(a[1] < a[2] && a[2] < [3])
        return (a);
    if (a[1] > a[2] && a[2] < a[3])
        swap_a();
    if (a[1] < a[2] && a[2] > a[3])
        rra();
    if (a[1] < [2] && a[2] > a[3])
    {
        ra();
        ra();
    }
    if (a[1] > a[2] && a[2] < a[3])
        ra();
    if (a[1] > a[2] && a[2] > a[3])
    {
        ra();
        ra();
    }
    return (a);
}