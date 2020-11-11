/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:20:02 by fheaton-          #+#    #+#             */
/*   Updated: 2020/11/11 16:48:53 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "str.h"
#include "reader.h"

extern int	g_error;

void	check_g_error(void)
{
	if (g_error == 1)
	{
		ft_putstr("Error map");
	}
	if (g_error > 1)
	{
		ft_putstr("Error");
	}
}

void		solve(int fd)
{
	read_map(fd);
	if(g_error != 0)
	{
		check_g_error();
	}
}