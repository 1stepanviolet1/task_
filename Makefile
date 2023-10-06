
all: print_str get_name main
	gcc main.o get_name.o print_str.o


main: main.c print_str.h get_name.h
	gcc -c main.c

print_str: print_str.c print_str.h
	gcc -c print_str.c

get_name: get_name.c get_name.h
	gcc -c get_name.c

