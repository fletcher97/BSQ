/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:20:02 by fheaton-          #+#    #+#             */
/*   Updated: 2020/11/11 20:04:02 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern int	g_error;

void	check_g_error(void)
{
	if (g_error == 1)
		ft_putstr("Error map");
	else if (g_error > 1)
		ft_putstr("Error");
	else
		ft_putstr("\n");
}

void		solve(int fd)
{
	read_map(fd);
	if(g_error != 0)
	{
		check_g_error();
	}
}
