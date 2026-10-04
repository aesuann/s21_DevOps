TARGET = s21_cat
CC = gcc
CFLAGS = -Wall -Wextra -Werror

PREF_OBJ = ./obj/
PREF_SRS = ./SRS/

SRS = $(wildcard *.c)
OBJ = $(patsubst %.c, $(PREF_OBJ)%.o, $(SRS))

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : %.c 
	@mkdir -p obj
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm $(TARGET) $(PREF_OBJ)*.o 

test :
	bash tests.sh