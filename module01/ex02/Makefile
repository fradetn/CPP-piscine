NAME		=	references

CC			=	clang++
CPPFLAGS	=	-Wall -Werror -Wextra
RM			=	rm -rf

SRCS		=	main.cpp

all:	$(NAME)

$(NAME):
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

fclean:
	$(RM) $(NAME)

re:		fclean all

.PHONY:	fclean, all, re