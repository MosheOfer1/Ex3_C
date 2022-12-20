
CC=gcc

FLAGS= -Wall


all: isort‬‬ txtfind

txtfind:findTxt.c
	$(CC) $(FLAGS) findTxt.c -o txtfind
	

isort‬‬:sort.c
	$(CC) $(FLAGS) sort.c -o isort
	

.PHONY: clean all

clean:
	rm -f txtfind & rm -f isort
	
