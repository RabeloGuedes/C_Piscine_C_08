/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:04:42 by arabelo-          #+#    #+#             */
/*   Updated: 2023/03/20 20:25:16 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
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
	copie = (char *)malloc(sizeof(*str) * ft_strlen(str));
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
	int		i;
	t_stock_str	*stock;

	i = 0;
	stock = (t_stock_str *)malloc(sizeof(*stock) * ac);
	while (i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		i++;
	}
	return (stock);
}

int	main(int ac, char **av)
{
	t_stock_str	*a;
	int	i;
	int	j;
	a = ft_strs_to_tab(ac, av);
	i = 0;
	while (i < ac)
	{
//		printf("Size: %d", *a->size);
		while (*a->*str)
		{
			printf("String: %c", *a->*str);
			str++;
		}
		printf("Copie: %c", *a->copy);
		i++;
		a++;
	}
	return (0);
}
