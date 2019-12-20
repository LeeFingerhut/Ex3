CC=gcc
AR=ar
OBJECTS_MAIN_SORT=main_sort.o
OBJECTS_MAIN_TXT=main_txt.o
OBJECTS_LIB_S0RT=insertion_sort.o
OBJECTS_LIB_TXT=txtfind.o
FLAGS= -Wall -g

all: isort txtfind

isort: $(OBJECTS_MAIN_SORT) libmysort.a 
	$(CC) $(FLAGS) -o isort $(OBJECTS_MAIN_SORT) libmysort.a 
libmysort.a: $(OBJECTS_LIB_S0RT) insertion_sort.h
	$(AR) -rcs libmysort.a $(OBJECTS_LIB_S0RT)
insertion_sort.o: insertion_sort.c insertion_sort.h
	$(CC) $(FLAGS) -c -fPIC insertion_sort.c
main_sort.o: main_sort.c insertion_sort.c insertion_sort.h 
	$(CC) $(FLAGS) -c main_sort.c 

txtfind: $(OBJECTS_MAIN_TXT) libmytxtfind.a 
	$(CC) $(FLAGS) -o txtfind $(OBJECTS_MAIN_TXT) libmytxtfind.a 
libmytxtfind.a: $(OBJECTS_LIB_TXT) txtfind.h
	$(AR) -rcs libmytxtfind.a $(OBJECTS_LIB_TXT)
txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c -fPIC txtfind.c
main_txt.o: main_txt.c txtfind.c txtfind.h 
	$(CC) $(FLAGS) -c main_txt.c 

.PHONY: clean isort txtfind

clean:
	rm -f *.o *.a txtfind isort
