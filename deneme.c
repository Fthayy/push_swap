// void ra(t_stack *a)
// {
//     t_stack *tmp;
//     t_stack *tmp2;
//     long int hold = a->nb;
//     tmp2 = a;
//     tmp = a;
//     while(tmp->next != NULL)
//     {
//         a->nb = tmp->next->nb;
//         a = a->next;
//         tmp = tmp->next;
//     }
//     a = tmp2;
//     if (tmp->next == NULL)
//         ft_lstlastnmb(a)->nb = hold;
// }

// void rra(t_stack *a)
// {
//     t_stack *tmp;
//     t_stack *tmp2;
//     tmp2 = a;
//     tmp = a;
//     long int hold = ft_lstlastnmb(a)->nb;
//     while(tmp != NULL)
//     {
//         a->next->nb = tmp->nb;
//         a = a->next;
//         tmp = tmp->next;
//     }
//     a = tmp2;
//     if(tmp == NULL)
//         a->nb = hold;
// }