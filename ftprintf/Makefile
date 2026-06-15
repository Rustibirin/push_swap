# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/06 20:14:53 by rumartin          #+#    #+#              #
#    Updated: 2026/06/15 19:08:09 by rumartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
AR		= ar rcs
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf
MKDIR       = mkdir -p
OBJS_DIR    = obj

SRCS        = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c \
              ft_putunbr.c ft_puthex.c ft_putpointer.c ft_strlen.c

OBJS        = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c
	@$(MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
