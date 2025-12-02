all:
	gcc -o main *.c -g -Wextra -Wall -Werror 
clear:
	rm -rf *.o
principal:
	gcc -c *.c -g