#include "header.h"

int	g_error;

int	clear_map(t_map *map)
{
	g_error = 1;
	free(map->obs_count);
	free(map);
	return (0);
}

/*
** Reads a line from fd up to '\n' and returns a string containing the content
** without the LF.
**
** Returns NULL if a read error occured or the memory couldn't be allocated.
*/

char	*read_line(int fd, int pos)
{
	char c;
	int i;
	char *line;

	i = read(fd, &c, 1);
	if (i == -1)
		g_error = 3;
	if (i == -1)
		return (NULL);
	if (!i || c == '\n' || c == '\r')
	{
		if (!(line = malloc(pos + 1)))
			g_error = 2;
		if (g_error != 0)
			return (NULL);
		line[pos] = '\0';
	}
	else
	{
		line = read_line(fd, pos + 1);
		if (!line)
			return (NULL);
		line[pos] = c;
	}
	return (line);
}

int	add_line(t_map *map, char *line, int i)
{
	int j;

	//first line
	j = -1;
	if (i == 0)
	{
		if(!(map->obs_count = malloc(sizeof(int) * map->height * str_len(line))))
		{
			free(map);
			free(line);
			g_error = 2;
			return (0);
		}
		map->width = str_len(line);
		while (line[++j])
		{
			if (line[j] != map->obstacle && line[j] != map->empty)
			{
				free(line);
				return (clear_map(map));
			}
			map->obs_count[j] = (line[j] == map->obstacle ? 1 : 0);
			if (j != 0)
				map->obs_count[j] += map->obs_count[j - 1];
		}
	return (1);
	}
	else
	{
		while (line[++j])
		{
			if (line[j] != map->obstacle && line[j] != map->empty)
			{
				free(line);
				return (clear_map(map));
			}
			map->obs_count[j + map->width * i] = (line[j] == map->obstacle ? 1 : 0);
			if (j == 0)
				map->obs_count[j + map->width * i] += map->obs_count[j + map->width * (i - 1)];
			else
				map->obs_count[j + map->width * i] += map->obs_count[j + map->width * (i - 1)]\
					+map->obs_count[j + map->width * i - 1] - map->obs_count[j + map->width * (i - 1) - 1];
		}
	}
	free(line);
	return (1);
}

t_map	*read_map(int fd)
{
	t_map	*map;
	int		i;
	char	*line;

	if (!(map = init(fd)))
		return (NULL);
	i = -1;
	while (++i < map->height && (line = read_line(fd, 0)))
		if (!add_line(map, line, i))
		{
			if (map->obs_count)
				free(map->obs_count);
			free(map);
			return (NULL);
		}
	if (g_error != 0)
		return (NULL);
	while (line = read_line(fd, 0))
		if (str_len(line) > 0)
		{
			clear_map(map);
			return (NULL);
		}
	if (g_error != 0)
		return (NULL);
	return (map);
}
