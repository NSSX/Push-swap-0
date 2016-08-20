#include <unistd.h>
#include "swap.h"

void ft_putchar(char c)
{
        write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

int	ft_atoi(const char *str)
{
	int number;
	int negativ;
	int index;

	number = 0;
	index = 0;
	negativ = 0;
	while (str[index] == ' ' || str[index] == '\n' || str[index] == '\v' ||
			str[index] == '\t' || str[index] == '\f' || str[index] == '\r')
		index++;
	if (str[index] == '-')
		negativ++;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		number *= 10;
		number += ((int)str[index] - 48);
		index++;
	}
	if (negativ == 1)
		return (-number);
	else
		return (number);
}
