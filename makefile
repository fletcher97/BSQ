CC = gcc
CFLAGS = -Wall -Werror -Wextra

EXEC = bsq

BIN_DIR = .
SRC_DIR = src2
INC_DIR = inc
OBJ_DIR = obj

main.o = header.h
map.o = header.h
process.o = header.h
reader.o = header.h
reader2.o = header.h
solve.o = header.h
str.o = header.h
write_map.o = header.h

OBJ = main.o map.o process.o reader.o reader2.o solve.o str.o write_map.o

vpath %.o $(OBJ_DIR)
vpath %.h $(INC_DIR)
vpath %.c $(SRC_DIR)

.PHONY : clean fclean re all

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(addprefix $(OBJ_DIR)/, $(OBJ)) -o $(BIN_DIR)/$@

%.o : %.c $($@)
	$(CC) -c $< -I $(INC_DIR) -o $(OBJ_DIR)/$@

clean :
	rm -f $(addprefix $(OBJ_DIR)/, $(OBJ))

fclean : clean
	rm -f $(EXEC)

re : fclean all
