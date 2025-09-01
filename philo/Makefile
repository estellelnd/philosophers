NAME           	= philo

SRCS            = main.c	\
				


OBJ            = $(SRCS:.c=.o)

CFLAGS          =  -Werror  -I . -pthread

all:            $(NAME)

$(NAME)		:	$(OBJ)
		gcc -o $(NAME) $(OBJ)

%.o: %.c philo.h
		gcc $(CFLAGS) -c $< -o $@

clean:
				rm -f $(OBJ)

fclean:         clean
				rm -f $(NAME)

re:             fclean all
