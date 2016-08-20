#include "swap.h"

int error(void)
{
    ft_putstr("not now bro\n");
    return (0);
}

void print_pile(t_pile *pile, t_pile *pile2)
{
    t_pile *tmp;
    t_pile *tmp2;

   tmp2 = pile2;
    tmp = pile;
    printf("pile A : ");
    while(tmp)
    {
        printf("%d ",tmp->value);
        tmp = tmp->before;
    }
    printf("\npile B : ");
    while(tmp2)
    {
        printf("%d ",tmp2->value);
        tmp2 = tmp2->before;
    }
    printf("\n---------\n");
}
