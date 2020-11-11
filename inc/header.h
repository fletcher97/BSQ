#ifndef MAP_H
# define MAP_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_map
{
	int	*obs_count;			//obstacul list
	char empty;				//empty char
	char obstacle;			//obstacle char
	char full;				//full char
	int height;				//map height
	int width;				//map width
	int	biggest_size;		//biggest square found so far
	int pos;				//biggest square's top left corner
	int valid;				//if the map read so far is valid TODO: check nessecity
}				t_map;

extern int	g_error;

/*
** error code map.valid (Currently not in use)
** -1: invalid height
** -2: invalid char params on top of file
*/

/*
** error code g_error (Currently not in use)
** 1: map error
** 2: malloc
** 3: read error
*/

/*
** map.c
*/

t_map	*init(int fd);
int		read_solve_map(int fd);

/*
** process.c
*/

int	process(t_map *map);

/*
** str.c
*/

int	str_len(char *str);
void ft_putstr(char *c);
void ft_putchar(char c);

/*
** reader.c
*/

t_map	*read_map(int fd);
char	*read_line(int fd, int pos);

/*
** solver.c
*/

void	check_g_error(void);

/*
** writefile.c
*/

int		write_map(t_map *map);

#endif
