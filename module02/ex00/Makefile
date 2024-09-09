NAME		=	fixed

CC			=	clang++
INCLUDES	=	INCLUDES
CPPFLAGS	=	-Wall -Werror -Wextra -I$(INCLUDES)
RM			=	rm -rf

SRCS		=	main.cpp	\
				Fixed.cpp

all:	$(NAME)

$(NAME):
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

fclean:
	$(RM) $(NAME)

re:		fclean all

.PHONY:	fclean, all, re