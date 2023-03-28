# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 13:09:57 by fmalizia          #+#    #+#              #
#    Updated: 2023/03/28 12:55:36 by jcarlen          ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

SRCS =	RPN.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}

CXX  = g++

RM  = rm -f

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

run: $(NAME)
	@printf "\noutput\n\n"
	@./out
	@printf "\n\n\n"
	@ make fclean

re:		fclean all

.PHONY:	all clean fclean re run