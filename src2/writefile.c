/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writefile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:33:03 by fheaton-          #+#    #+#             */
/*   Updated: 2020/11/11 11:55:35 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "str.h"
#include "reader.h"

int		write_file(t_map *map)
{
	char *arr;
	int a;
	int malloc_size;

	if (!(map = read_map(fd)))
	{
		return (0);
	}
	if (!(arr = malloc(malloc_size)))
	{
		return (0);
	}
	while (read(fd, &arr[a], 1))
		if ( == map->pos)
			while (a < size)
				write(fd, "X", 1);
		a++;
	close(fd);
}
