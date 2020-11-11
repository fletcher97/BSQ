/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:20:02 by fheaton-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/11/11 19:03:34 by mgueifao         ###   ########.fr       */
=======
/*   Updated: 2020/11/11 19:09:52 by fheaton-         ###   ########.fr       */
>>>>>>> 9838f511800d15a414b34044585ea085437224fb
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
