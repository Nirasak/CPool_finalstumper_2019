##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\
		src/rush3.c	\
		src/error.c	\

TESTS	=	src/rush3.c	\
		src/error.c	\
		tests/test_rush3.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	rush3

CFLAGS	=	-W -Wall -I include/

LDFLAGS	=	-L lib/my -lmy

UNITFLAGS	=	-lcriterion --coverage

EXECTESTS	=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:
	make -C lib/my
	$(CC) $(TESTS) $(CFLAGS) $(LDFLAGS) $(UNITFLAGS) -o $(EXECTESTS)
	./$(EXECTESTS) && gcovr && gcovr --exclude tests/ --branches

clean:
	rm -f *~
	rm -f $(OBJ)
	rm -f *gc*
	make clean -C lib/my

fclean:	clean
	rm -f $(NAME)
	rm -f $(EXECTESTS)
	make fclean -C lib/my

re:	fclean all

.PHONY:	all clean fclean re
