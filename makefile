CC = gcc
CFLAGS = -g -Wall -std=c90

all: ru_na_pandemia

# programa:ru_na_pandemia
ru_na_pandemia: 
	$(CC) ru_na_pandemia.c $(CFLAGS) -o ru_na_pandemia

clean :
	rm -f ru_na_pandemia