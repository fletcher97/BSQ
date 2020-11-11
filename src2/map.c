#include "header.h"

/*
** Creates a new t_map struct and initializes all values with 0.
**
** Returnss NULL if the memory couldn't be allocated.
*/

static t_map	*new_map()
{
	t_map	*map;

	if (!(map = malloc(sizeof(t_map))))
	{
		g_error = 2;
		return (NULL);
	}
	map->obs_count = 0;
	map->empty = 0;
	map->obstacle = 0;
	map->full = 0;
	map->height = 0;
	map->width = 0;
	map->biggest_size = 0;
	map->pos = 0;
	map->valid = 0;
	return (map);
}

/*
** Set the map parameter with the first line
*/

static t_map	*set_params(t_map *map, char *params)
{
	int i;

	i = 0;
	while (params[i] >= '0' && params[i] <= '9')
		map->height = (map->height * 10) + (params[i++] - '0');
	if (map->height <= 0)
	{
		map->valid = -1;
		return (map);
	}
	if (params[i])
		map->empty = params[i++];
	if (params[i])
		map->obstacle = params[i++];
	if (params[i])
		map->full = params[i++];
	if (params[i] || !map->empty || !map->obstacle || !map->full ||\
		map->empty == map->obstacle || map->empty == map->full ||\
		map->obstacle == map->full)
		map->valid = -2;
	return (map);
}

/*
** Creates and initializes the map with the parameters on the first line.
**
** Returns NULL if memory can't be allocated or the parameters are wrong.
*/

t_map	*init(int fd)
{
	char	*params;
	t_map	*map;

	if (!(map = new_map()))
		return (NULL);
	if (!(params = read_line(fd, 0)))
	{
		free(map);
		return (NULL);
	}
	map = set_params(map, params);
	if (map->valid < 0)
	{
		g_error = 1;
		free(map);
		map = NULL;
	}
	free(params);
	return (map);
}

t_map	*read_solve_map(int fd)
{
	t_map	*map;

	if(!(map = read_map(fd)))
		return (NULL);
	if (map->valid < 0)
	{
		if(map->obs_count)
			free(map->obs_count);
		free(map);
		return (NULL);
	}
	return (map);
}
