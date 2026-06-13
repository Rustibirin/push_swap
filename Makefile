# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framirez <framirez@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/03 10:51:14 by rumartin          #+#    #+#              #
#    Updated: 2026/06/13 11:11:44 by framirez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf
MKDIR       = mkdir -p
OBJS_DIR    = obj
PRINTF_DIR	= ./ftprintf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

SRCS        = main.c errors.c ft_complex.c ft_complex_utils.c ft_simple.c \
			  ft_split.c ft_split_utils.c parser.c parser_utils.c push.c \
			  swap.c rotate.c reverse_rotate.c bench.c ft_medium.c ft_medium_utils.c
OBJS        = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o  $(NAME)
$(PRINTF): FORCE
	make -C $(PRINTF_DIR)

$(OBJS_DIR)/%.o: %.c
	@$(MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)
	make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(PRINTF_DIR) fclean
	
re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE