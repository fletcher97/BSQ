/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:20:02 by fheaton-          #+#    #+#             */
/*   Updated: 2020/11/11 22:00:28 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern int	g_error;

void	check_g_error(void)
{
	if (g_error == 1)
		ft_putstr("Error map\n");
	else if (g_error > 1)
		ft_putstr("Error\n");
}
