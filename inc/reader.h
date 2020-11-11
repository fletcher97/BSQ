#ifndef READER_H
# define READER_H

#include "map.h"

t_map	*read_map(int fd);
char	*read_line(int fd, int pos);

#endif
