/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:13:40 by mgueifao          #+#    #+#             */
/*   Updated: 2020/11/11 21:29:03 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char *argv[])
{
	int i;
	int fd;

	i = 0;
	if (argc > 1)
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd != -1)
			{
				if (i > 1)
					ft_putstr("\n");
				read_solve_map(fd);
				check_g_error();
				close(fd);
			}
			else
				ft_putstr("Error\n");
		}
	else
	{
		read_solve_map(0);
		check_g_error();
	}
	return (0);
}
