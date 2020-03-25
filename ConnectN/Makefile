connectn.out: main.o board_set.o valid_input.o output.o
	gcc -g -Wall -Werror -o connectn.out main.o board_set.o valid_input.o output.o
    
main.o: main.c board_set.h valid_input.h output.h
	gcc -g -Wall -Werror -c main.c
    
valid_input.o: valid_input.c valid_input.h board_set.h output.h
	gcc -g -Wall -Werror -c valid_input.c
    
board_set.o: board_set.c board_set.h valid_input.h
	gcc -g -Wall -Werror -c board_set.c
     
output.o: output.c output.h valid_input.h
	gcc -g -Wall -Werror -c output.c
    
clean:
	Rm -fr *.o *.out