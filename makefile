CC = gcc
CFLAGS = -Wall -Werror -Wextra

EXEC = bsq

BIN_DIR = bin
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

bsq.o = bsq.h

OBJ = bsq.o

vpath %.o $(OBJ_DIR)
vpath %.h $(INC_DIR)
vpath %.c $(SRC_DIR)

all : $(EXEC)

$(EXEC) : $(OBJ_CLIENT)
	$(CC) -g $(addprefix $(OBJ_DIR)/, $(OBJ)) -o $(BIN_DIR)/$@

%.o : %.c $($@)
	$(CC) -g -c $< -I $(INC_DIR) -o $(OBJ_DIR)/$@

.PHONY : clean
clean :
	find $(OBJ_DIR) -type f -delete
	find $(BIN_DIR) -type f -delete
