/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@Student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:04:42 by arabelo-          #+#    #+#             */
/*   Updated: 2023/03/21 11:18:07 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/* #include <stdio.h> */
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{	
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
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

/*int	main(int ac, char **av)
{
	t_stock_str	*a;

	if (ac > 1)
	{
		a = ft_strs_to_tab(ac, av);
		while (a->str)
		{
			printf("String: %s\n", a->str);
			printf("Copy: %s\n", a->copy);
			printf("Size: %d\n", a->size);
			a++;
		}
	}
	return (0);
}*/
