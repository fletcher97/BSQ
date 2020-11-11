#include "map.h"

extern int	g_error;

int	clear_map(t_map *map)
{
	g_error = 1;
	free(map->obs_count);
	free(map);
	return (0);
}

/*
** In case of error free map
**
** return 1 on sucess 0 otherwise
*/

int process(t_map *map, char *line, int depth)
{
	int i;
	int obs;

	i = -1;
	if(depth == 0)
		return first_line(map, line);
	while (line[++i])
	{
		obs = 0;
		if (line[i] == map->obstacle)
			map->valid = 1;
		if (line[i] == map->obstacle)
			obs = 1;
		else if(line[i] != map->empty)
			return (clear_map(map));
		if (i == 0)
			map->obs_count[depth * map->width] =\
				map->obs_count[(depth - 1) * map->width] + obs;
		else
			map->obs_count[depth * map->width + i] =\
				map->obs_count[depth * map->width + i - 1] +\
				map->obs_count[(depth - 1) * map->width + i] -\
				map->obs_count[(depth - 1) * map->width + i - 1] + obs;
	}
	return (check_placements(map, depth));
}

int	first_line(t_map *map, char *line)
{
	int i;

	if(!(map->obs_count = malloc(map->height * str_len(line))))
	{
		free(map);
		g_error = 2;
		return (0);
	}
	i = -1;
	while (line[++i])
	{
		if (line[i] != map->obstacle && line[i] != map->empty)
			return (clear_map(map));
		if (i == 0)
			map->obs_count[i] = (line[i] == map->obstacle ? 1 : 0);
		else
			map->obs_count[i] = (line[i] == map->obstacle ? 1 : 0) +\
				map->obs_count[i - 1];
	}
	return (1);
}

/*
** check possible square placement
*/

int	check_placements(t_map *map, int depth)
{
	int can_check;
	if (map->next_pos / map->width == 0) //next pos is in the first line
		return (check_placements_first_line(map, depth));
	can_check = 1;
	while (can_check)
	{
		if (map->pos == map->next_pos)
			can_check = check_bigger(map, depth);
		else
			can_check = check_next(map, depth);
	}
	return (1);
}

int	check_bigger(t_map *map, int depth)
{
	if (map->pos + map->width * (map->biggest_size) + (map->biggest_size)\
		> map->width * (depth + 1))
		return (0);
	if (map->pos % map->width == 0)
	{
		if (map->obs_count[map->pos + (map->biggest_size) + (map->biggest_size)]\
			- map->obs_count[map->pos - map->width + map->biggest_size] == 0)
			map->biggest_size++;
		else
			map->next_pos++;
	}
	else
		if (map->obs_count[map->pos + (map->biggest_size) + (map->biggest_size)]\
			- map->obs_count[map->pos - map->width + map->biggest_size] == 0)
			map->biggest_size++;
		else
			map->next_pos++;
	return (1);
}