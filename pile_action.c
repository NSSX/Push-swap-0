#include "swap.h"

void swap_a(t_pile **pile_a)
{
    t_pile *tmp;
    t_pile *tmp_second;
    t_pile *last;

    if(*pile_a && (*pile_a)->before)
    {
        tmp = *pile_a;
        tmp_second = (*pile_a)->before;
        last = (*pile_a)->before->before;
        *pile_a = tmp_second;
        (*pile_a)->before = tmp;
        (*pile_a)->before->before = last;
    }
}

void swap_b(t_pile **pile_b)
{
    t_pile *tmp;
    t_pile *tmp_second;
    t_pile *last;

    if(*pile_b && (*pile_b)->before)
    {
        tmp = *pile_b;
        tmp_second = (*pile_b)->before;
        last = (*pile_b)->before->before;
        *pile_b = tmp_second;
        (*pile_b)->before = tmp;
        (*pile_b)->before->before = last;
    }
}


void swap_a_b(t_pile **pile_a, t_pile **pile_b)
{
    swap_a(pile_a);
    swap_b(pile_b);
}

void rotate_a(t_pile **pile_a)
{
    t_pile *tmp;
    t_pile *ret;

   if(*pile_a && (*pile_a)->before)
    {
        tmp = *pile_a;
        ret = (*pile_a)->before;
        while((*pile_a)->before)
        {
            *pile_a = (*pile_a)->before;
        }
        (*pile_a)->before = tmp;
        (*pile_a)->before->before = NULL;
        *pile_a = ret;
    }
}

void rotate_b(t_pile **pile_b)
{
    t_pile *tmp;
    t_pile *ret;

   if(*pile_b && (*pile_b)->before)
    {
        tmp = *pile_b;
        ret = (*pile_b)->before;
        while((*pile_b)->before)
        {
            *pile_b = (*pile_b)->before;
        }
        (*pile_b)->before = tmp;
        (*pile_b)->before->before = NULL;
        *pile_b = ret;
    }
}


void rotate_a_b(t_pile **pile_a, t_pile **pile_b)
{
    rotate_a(pile_a);
    rotate_b(pile_b);
}

void reverse_rotate_a(t_pile **pile_a)
{
    t_pile *tmp;
    t_pile *last;
    t_pile *parcour;

    if(*pile_a && (*pile_a)->before)
    {
            tmp = *pile_a;
            parcour = *pile_a;
            while(parcour->before->before)
            {
                parcour = parcour->before;
            }
            last = parcour->before;
            parcour->before = NULL;
            last->before = tmp;
            *pile_a = last;
    }
}

void reverse_rotate_b(t_pile **pile_b)
{
    t_pile *tmp;
    t_pile *last;
    t_pile *parcour;

    if(*pile_b && (*pile_b)->before)
    {
            tmp = *pile_b;
            parcour = *pile_b;
            while(parcour->before->before)
            {
                parcour = parcour->before;
            }
            last = parcour->before;
            parcour->before = NULL;
            last->before = tmp;
            *pile_b = last;
    }
}

void reverse_rotate_a_b(t_pile **pile_a, t_pile **pile_b)
{
    reverse_rotate_a(pile_a);
    reverse_rotate_b(pile_b);
}

void push_a(t_pile **pile_a, t_pile **pile_b)
{
    t_pile *tmp;
    t_pile *temp;
    int value;

    if(*pile_b)
    {
        temp = *pile_b;
        tmp = temp->before;
        value = temp->value;
        *pile_a = pile_push(*pile_a, value);
        free(*pile_b);
        *pile_b = NULL;
        *pile_b = tmp;
    }
}

void push_b(t_pile **pile_a, t_pile **pile_b)
{
    t_pile *tmp;
    t_pile *temp;
    int value;

    if(*pile_a)
    {
        temp = *pile_a;
        tmp = temp->before;
        value = temp->value;
        *pile_b = pile_push(*pile_b, value);
        free(*pile_a);
        *pile_a = NULL;
        *pile_a = tmp;
    }
}
