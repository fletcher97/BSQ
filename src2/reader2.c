/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:55:47 by mgueifao          #+#    #+#             */
/*   Updated: 2020/11/11 22:56:29 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** Free memory and set g_error
*/

int		clear_map(t_map *map)
{
	g_error = 1;
	free(map->obs_count);
	free(map);
	return (0);
}
