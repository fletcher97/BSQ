/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:39:37 by fheaton-          #+#    #+#             */
/*   Updated: 2020/11/11 15:39:37 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	str_len(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *c)
{
	int a;

	a = -1;
	while (c[++a])
		ft_putchar(c[a]);
}
