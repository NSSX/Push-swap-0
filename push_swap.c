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
    while(argc > 0)
    {
        //A changer a l'ecole le - 1 de argc
        if(argv[argc - 1][0] != '\0'){
        pile_a = pile_push(pile_a, ft_atoi(argv[argc - 1]));
    }
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
                rotate_a(&pile_a, 0);
                nb_action++;
            }
        }
        else
        {
            push_a(&pile_a, &pile_b);
            nb_action++;
        }
    //    print_pile(pile_a, pile_b);
    }
    //printf("NOMBER ACTION : %d\n",nb_action);
    //printf("PILE FINALE : \n");
//    print_pile(pile_a, pile_b);
}

//envoyer l'adresse pour ne pas avoir a renvoyer

int nb_case_tab(int argc, char **argv)
{
     int index_argc;
     int count;
     int i;

     count = 0;
     index_argc = 1;
     while(index_argc < argc)
     {
         i = 0;
         while(argv[index_argc][i] != '\0')
         {
             if(argv[index_argc][i] == ' ')
                {
                    while(argv[index_argc][i] == ' ')
                        i++;
                    if(argv[index_argc][i] != '\0')
                        count++;
                }
            if(argv[index_argc][i] != '\0')
                i++;
         }
         count++;
         index_argc++;
     }
     return (count);
}

int space_here(char *chain)
{
    int i;

    i = 0;
    while(chain[i] != '\0')
    {
        if(chain[i] == ' ')
            return (1);
        i++;
    }
    return (0);
}

char    **cut_tab(int argc, char **argv)
{
    char **my_tab;
    int index_tab;
    int index_argc;
    int i;
    int idep;
    int index_new;

    index_tab = 0;
    index_argc = 1;
    my_tab = (char **)malloc(sizeof(char *) * nb_case_tab(argc, argv));
    while(index_argc < argc)
    {
        i = 0;
        while(argv[index_argc][i] != '\0')
        {
            idep = i;
            while(argv[index_argc][i] != '\0' && argv[index_argc][i] != ' ')
                i++;
            my_tab[index_tab] = (char *)malloc(sizeof(char) * (i - idep) + 2);
            index_new = 0;
            while(idep < i)
            {
                my_tab[index_tab][index_new] = argv[index_argc][idep];
                index_new++;
                idep++;
            }
            my_tab[index_tab][index_new] = '\0';
            index_tab++;
            while(argv[index_argc][i] == ' ')
                i++;
        }
        index_argc++;
    }
    return (my_tab);
}

int check_param(int argc, char **argv)
{
    int index_argc;
    int index_chaine;

    index_argc = 0;
    while(index_argc < argc)
    {
            index_chaine = 0;
            while(argv[index_argc][index_chaine] != '\0')
            {
                if((argv[index_argc][index_chaine] < '0' ||
                argv[index_argc][index_chaine] > '9'))
                {
                    if(index_chaine == 0)
                    {
                        if(argv[index_argc][index_chaine] != '-' &&
                        argv[index_argc][index_chaine] != '+')
                        return (1);
                    }
                    else
                        return (1);
                }
                index_chaine++;
            }
            if(ft_atoi(argv[index_argc]) < INT_MIN ||
             ft_atoi(argv[index_argc]) > INT_MAX)
                return (1);
        index_argc++;
    }
    return(0);
}

int doublon(t_pile *pile, int val)
{
    t_pile *tmp;
    int count;

    count = 0;
    tmp = pile;
    while(tmp)
    {
        if(val == tmp->value)
            count++;
        tmp = tmp->before;
    }
    if(count != 1)
        return (1);
    return (0);
}

int check_doublon(t_pile *pile)
{
    t_pile *tmp;

    tmp = pile;
    while(tmp)
    {
        if(doublon(pile, tmp->value) != 0)
            return (1);
        tmp = tmp->before;
    }
    return (0);
}

int main(int argc, char **argv)
{
    char **new_tab;
    int i = 0;
    int limit = nb_case_tab(argc, argv);
    new_tab = cut_tab(argc, argv);
    if(argc > 1)
    {
        if(check_param(limit, new_tab) != 0)
        {
            ft_putstr("Error\n");
            return (0);
        }
    }

    t_pile *subs_a;
    t_pile *subs_b;

    subs_a = NULL;
    subs_b = NULL;
    if(argc < 2)
        return(error());
    subs_a = create_pile_a(subs_a, limit, new_tab);
    if(check_doublon(subs_a) != 0)
    {
        ft_putstr("Error\n");
        return (0);
    }
    ft_resolve2(subs_a, subs_b);
    return(0);
}
