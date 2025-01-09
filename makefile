# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 10:39:54 by oyuhi             #+#    #+#              #
#    Updated: 2025/01/09 11:13:49 by oyuhi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = cc 
CFLAGS = -Wall -Wextra -Werror


SRCS =  a_main_error_free.c \
		a_ft_split_ifrom1.c \
		b_stack_init_and_atol.c \
		c_isvalid_stack.c \
		d_cal_cost_rotation.c \
		d_ft_sort.c \
		d_sort_helper.c \
		operation_push.c \
		operation_reverse_rotate.c \
		operation_rotate.c \
		operation_swap.c \
		utils_lst.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) :  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re