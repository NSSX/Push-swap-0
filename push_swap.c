#include "swap.h"

t_pile *pile_push(t_pile *pile, int val)
{
    t_pile *new_elem;

    new_elem = malloc(sizeof(new_elem));
    if (new_elem != NULL)
    {
        new_elem->value = val;
        new_elem->before = pile;
        pile = new_elem;
    }
    return(pile);
}


t_pile *create_pile_a(t_pile *pile_a, int argc, char **argv)
{
    int i;

    i = 1;
    while(argc > 1)
    {
        //A changer a l'ecole le - 1 de argc
        pile_a = pile_push(pile_a, ft_atoi(argv[argc - 1]));
        argc--;
    }
    return(pile_a);
}

int is_sort(t_pile *pile_a, t_pile *pile_b)
{
    t_pile *tmp;

    if(pile_a && pile_b == NULL)
    {
        tmp = pile_a;
        while(tmp->before)
        {
            if(tmp->value > tmp->before->value)
                return (0);
            tmp = tmp->before;
        }
        return (1);
    }
    return (0);
}

int is_sort_inverse(t_pile *pile_a, t_pile *pile_b)
{
    t_pile *tmp;

    if(pile_a && pile_b == NULL)
    {
        tmp = pile_a;
        while(tmp->before)
        {
            if(tmp->value < tmp->before->value)
                return (0);
            tmp = tmp->before;
        }
        return (1);
    }
    return (0);
}

//envoyer du plus grand au plus petit dans pile B then repush
/*
void ft_resolve(t_pile *pile_a, t_pile *pile_b)
{
    int a_empty = 0;
    int nb_action = 0;
    while(is_sort(pile_a, pile_b) != 1)
    {
        if(a_empty == 0)
        {
            if(pile_a && pile_a->before && pile_a->value > pile_a->before->value)
            {
                swap_a(&pile_a);
                nb_action++;
            }
            else
            {
                push_b(&pile_a, &pile_b);
                nb_action++;
            }
            if(pile_a == NULL)
                a_empty = 1;
        }
        else
        {
            push_a(&pile_a, &pile_b);
            nb_action++;
            if(pile_b == NULL)
                a_empty = 0;
        }
       //sleep(1.3);
        print_pile(pile_a, pile_b);
    }
    printf("NOMBER ACTION : %d\n",nb_action);
    printf("PILE FINALE : \n");
    print_pile(pile_a, pile_b);
}
*/
int smallest(t_pile *pile_a)
{
    t_pile *tmp;
    int small;

    small = pile_a->value;
    tmp = pile_a->before;
    while(tmp)
    {
        if(tmp->value < small)
        {
            small = tmp->value;
        }
        tmp = tmp->before;
    }
    return (small);
}

void ft_resolve2(t_pile *pile_a, t_pile *pile_b)
{
    int a_empty = 0;
    int nb_action = 0;
    int repush = 0;

    while(is_sort(pile_a, pile_b) != 1)
    {
        if(repush == 0)
        {
            if(pile_a == NULL)
                repush = 1;
            else if(pile_a->value == smallest(pile_a))
            {
                push_b(&pile_a, &pile_b);
                nb_action++;
            }
            else
            {
                rotate_a(&pile_a);
                nb_action++;
            }
        }
        else
        {
            push_a(&pile_a, &pile_b);
            nb_action++;
        }
        print_pile(pile_a, pile_b);
    }
    printf("NOMBER ACTION : %d\n",nb_action);
    printf("PILE FINALE : \n");
    print_pile(pile_a, pile_b);
}

//envoyer l'adresse pour ne pas avoir a renvoyer
int main(int argc, char **argv)
{
    //t_pile *pile_a;
    //t_pile *pile_b;
    t_pile *subs_a;
    t_pile *subs_b;

    //pile_b = NULL;
    //pile_a = NULL;
    subs_a = NULL;
    subs_b = NULL;
    if(argc < 2)
        return(error());
///    pile_a = create_pile_a(pile_a, argc, argv);
    subs_a = create_pile_a(subs_a, argc, argv);
    //ft_resolve(pile_a, pile_b);
//    sleep(3);
    ft_resolve2(subs_a, subs_b);
    return(0);
}
