/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:38:10 by fheaton-          #+#    #+#             */
/*   Updated: 2020/11/11 11:38:10 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

extern int	g_error;

t_map	*read_map(int fd)
{
	t_map	*map;
	int		i;
	char	*line;


	if (!(map = init(fd)))
		return (NULL);
	i = -1;
	while (++i < map->height && (line = read_line(fd, 0)))
	{
		if (!add_line(map, line, i))
			return (NULL);
	}
}

int	add_line(t_map *map, char *line, int i)
{
	int j;

	if (i == 0)
	{
		if(!(map->obs_count = malloc(map->height * str_len(line))))
		{
			free(map);
			free(line);
			g_error = 2;
			return (0);
		}
		j = -1;
		while (line[++j])
		{
			if (line[j] != map->obstacle && line[j] != map->empty)
			{
				free(line);
				return (clear_map(map));
			}
			if (j == 0)
				map->obs_count[i] = (line[i] == map->obstacle ? 1 : 0);
			else
				map->obs_count[i] = (line[i] == map->obstacle ? 1 : 0) +\
					map->obs_count[i - 1];
		}
		return (1);
	}
}