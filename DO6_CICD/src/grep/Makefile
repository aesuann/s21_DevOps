TARGET = s21_grep
CC = gcc
CFLAGS = -Wall -Wextra -Werror

PREF_OBJ = ./obj/

SRS = $(wildcard *.c)
OBJ = $(patsubst %.c, $(PREF_OBJ)%.o, $(SRS))

all : $(TARGET) 

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)
$(PREF_OBJ)%.o : %.c 
	@mkdir -p obj
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm $(TARGET) $(PREF_OBJ)*.o 
test : 
	bash tests.sh