/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:04:43 by fheaton-          #+#    #+#             */
/*   Updated: 2020/11/11 22:04:43 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
/*
** obstacul list
** empty char
** obstacle char
** full char
** map height
** map width
** biggest square found so far
** biggest square's top left corner
** if the map read so far is valid TODO: check nessecity
*/

typedef struct	s_map
{
	int		*obs_count;
	char	empty;
	char	obstacle;
	char	full;
	int		height;
	int		width;
	int		biggest_size;
	int		pos;
	int		valid;
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

t_map		*init(int fd);
int			read_solve_map(int fd);

/*
** process.c
*/

int			process(t_map *map);

/*
** str.c
*/

int			str_len(char *str);
void		ft_putstr(char *c);
void		ft_putchar(char c);

/*
** reader.c
*/

t_map		*read_map(int fd);
char		*read_line(int fd, int pos);

/*
** solver.c
*/

void		check_g_error(void);

/*
** writefile.c
*/

int			write_map(t_map *map);

#endif
