#ifndef MAP_H
# define MAP_H

#include <stdlib.h>
#include <unistd.h>

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
	int next_pos;			//next position to check
	int valid;				//if the map read so far is valid TODO: check nessecity
}				t_map;

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

t_map	*init(int fd);
t_map	*read_solve_map(int fd);

#endif
