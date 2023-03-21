/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@Student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:22:02 by arabelo-          #+#    #+#             */
/*   Updated: 2023/03/21 19:12:26 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putstr(char *str)
{
	while (*str)
	{
		putchar(*str);
		str++;
	}
	putchar('\n');
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		putchar('-');
		putnbr(-nb);
	}
	else if (nb > 9)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	else
		putchar(nb + 48);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		putstr(par->str);
		putnbr(par->size);
		putchar('\n');
		putstr(par->copy);
		par++;
	}
}

/*char	*ft_strdup(char *str)
{
	char	*copie;
	int		i;

	i = 0;
	copie = (char *)malloc(sizeof(*str) * ft_strlen(str) + 1);
	if (!copie)
		return (NULL);
	while (str[i])
	{
		copie[i] = str[i];
		i++;
	}
	copie[i] = '\0';
	return (copie);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock;

	i = 0;
	stock = (t_stock_str *)malloc(sizeof(*stock) * (ac + 1));
	if (!stock)
		return (NULL);
	while (i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		i++;
	}
	stock[i].str = 0;
	return (stock);
}

int	main(int ac, char **av)
{
    ft_show_tab(ft_strs_to_tab(ac, av));
    return (0);
}*/
