


all: index_first_negative index_last_negative multi_between_negative multi_before_and_after_negative menu
	gcc -o menu index_first_negative.o index_last_negative.o multi_between_negative.o multi_before_and_after_negative.o menu.o


menu: menu.c index_first_negative.h index_last_negative.h multi_between_negative.h multi_before_and_after_negative.h
	gcc -c menu.c

index_first_negative: index_first_negative.c index_first_negative.h
	gcc -c index_first_negative.c

index_last_negative: index_last_negative.c index_last_negative.h
	gcc -c index_last_negative.c

multi_between_negative: multi_between_negative.c multi_between_negative.h index_first_negative.h index_last_negative.h
	gcc -c multi_between_negative.c

multi_before_and_after_negative: multi_before_and_after_negative.c multi_before_and_after_negative.h index_first_negative.h index_last_negative.h
	gcc -c multi_before_and_after_negative.c

