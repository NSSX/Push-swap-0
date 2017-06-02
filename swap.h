#ifndef SWAP_H
# define SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct       s_pile
{
    int             value;
    struct s_pile   *before;
}                   t_pile;

typedef struct      s_engine
{
    t_pile      pile_a;
    t_pile      pile_b;
}                  t_engine;

void ft_putstr(char *str);
void ft_putchar(char c);
long int  ft_atoi(const char *str);
void print_pile(t_pile *pile, t_pile *pile2);
int error(void);
void swap_a(t_pile **pile_a, int hide);
void swap_b(t_pile **pile_b, int hide);
void swap_a_b(t_pile **pile_a, t_pile **pile_b);
void rotate_a(t_pile **pile_a, int hide);
void rotate_b(t_pile **pile_b, int hide);
void rotate_a_b(t_pile **pile_a, t_pile **pile_b);
void reverse_rotate_a(t_pile **pile_a, int hide);
void reverse_rotate_b(t_pile **pile_b, int hide);
void reverse_rotate_a_b(t_pile **pile_a, t_pile **pile_b);
t_pile *pile_push(t_pile *pile, int val);
void push_a(t_pile **pile_a, t_pile **pile_b);
void push_b(t_pile **pile_a, t_pile **pile_b);
void	ft_putnbr(int n);
#endif
