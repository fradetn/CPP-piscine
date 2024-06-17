NAME		=	phonebook

CC			=	clang++
INCLUDES	=	INCLUDES
CPPFLAGS	=	-Wall -Werror -Wextra -I$(INCLUDES)
RM			=	rm -rf

SRCS		=	srcs/Contact.cpp		\
				srcs/PhoneBook.cpp	\
				main.cpp

all:	$(NAME)

$(NAME):
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

fclean:
	$(RM) $(NAME)

re:		fclean all

.PHONY:	fclean, all, re