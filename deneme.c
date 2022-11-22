#include "libft/libft.h"
#include <stdio.h>
int main()
{
    int i = 0;
    t_list *a =ft_lstnew("fatih");
    t_list *b =ft_lstnew("selam");
    t_list *c =ft_lstnew("ahsd");
    t_list *d =ft_lstnew("fsaafa");
    while(i < 3)
    {
        ft_lstadd_back(&a,b);
        b =ft_lstnew("afsfsf");
        ft_lstadd_back(&a,b);
        b =ft_lstnew("fsaasfsfffa");
        ft_lstadd_back(&a,b);
        i++;
    }
    printf("%s",a->next->content);
}
