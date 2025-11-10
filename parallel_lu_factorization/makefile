CC		= gcc
RM		= rm -f
SOURCE		= main.c
OBJECT		= main.o
EXECUTABLE	= lu
CFLAGS		= -O3 -g -Wall -Wextra -Wpedantic -Wno-alloc-size-larger-than
ALL_FLAGS	= -fopenmp -fsanitize=address,leak -lm

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECT)
   	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECT) $(ALL_FLAGS)

$(OBJECT): $(SOURCE)
	$(CC) $(CFLAGS) $(ALL_FLAGS) -c -o $(OBJECT) $(SOURCE)

execute: $(EXECUTABLE)
	./$(EXECUTABLE) 500 4

clean:
	$(RM) $(OBJECT) $(EXECUTABLE)
