#include "map.h"

int	process(t_map *map)
{
	int i;
	int j;
	int done;

	i = -1;
	done = 0;
	while (++i < map->height && done < 3)
	{
		j = -1;
		done = 0;
		while (++j < map->width && done < 2)
			while(!(done = check(i, j, map)))
			{
				map->biggest_size++;
				map->pos = i * map->width + j;
			}
	}
}

int	check(int r, int c, t_map *map)
{
	int current;

	if (r + map->biggest_size > map->height)
		return (3);
	if (c + map->biggest_size > map->width)
		return (2);
	current = map->obs_count[c + map->biggest_size + ((r + map->biggest_size) * map->width)];
	if (c == 0 && r == 0 && current != 0)
		return (1);
	if (r == 0 && (current - map->obs_count[(c - 1) + (r + map->biggest_size) * map->width]))
		return (1);
	if (c == 0 && (current - map->obs_count[c + map->biggest_size + (r - 1) * map->width]))
		return (1);
	if (current - map->obs_count[(c - 1) + (r + map->biggest_size) * map->width]\
		- map->obs_count[c + map->biggest_size + (r - 1) * map->width]
		+ map->obs_count[c - 1 + (r - 1) * map->width])
		return (1);
	map->pos = r * (map->width) + c;
	return (0);
}
