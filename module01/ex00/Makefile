NAME		=	zombie

CC			=	clang++
INCLUDES	=	INCLUDES
CPPFLAGS	=	-Wall -Werror -Wextra -I$(INCLUDES)
RM			=	rm -rf

SRCS		=	srcs/newZombie.cpp		\
				srcs/randomChump.cpp	\
				srcs/Zombie.cpp	\
				main.cpp

all:	$(NAME)

$(NAME):
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

fclean:
	$(RM) $(NAME)

re:		fclean all

.PHONY:	fclean, all, re