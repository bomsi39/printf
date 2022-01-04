# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/25 18:24:09 by dfranke           #+#    #+#              #
#    Updated: 2022/01/04 16:14:38 by dfranke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

AR		=	ar rcs

SRCS	=	ft_printf.c ft_putstuff.c ft_printf_utils.c

OBJS	=	$(SRCS:.c=.o)


all:	$(NAME)

$(NAME):	$(OBJS)
	@	$(AR) $(NAME) $(OBJS)

.c.o:
	@	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@	$(RM) $(OBJS) $(NAME)

fclean:	clean
	@	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
