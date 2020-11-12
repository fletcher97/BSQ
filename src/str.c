/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:39:37 by fheaton-          #+#    #+#             */
/*   Updated: 2020/11/12 11:30:08 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *c)
{
	int a;

	a = -1;
	while (c[++a])
		ft_putchar(c[a]);
}

void	write_buff(char *buff, t_map *map)
{
	write(1, buff, (map->width + 1) * map->height);
	free(buff);
}

char	*gen_buff(t_map *map)
{
	char *buff;
	if(!(buff = malloc((map->width + 1) * map->height + 1)))
		return (NULL);
	buff[(map->width + 1) * map->height] = '\0';
	return (buff);
}
