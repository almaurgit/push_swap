# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaurel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/13 15:57:01 by amaurel           #+#    #+#              #
#    Updated: 2018/10/14 20:18:06 by amaurel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap

LIB = libft/libft.a

SRCS = ./srcs

SRC_CK1 =	checker.c fts_checker.c get_pile_a.c tools.c \
			tools3.c instructions.c quicksort.c common_tools.c

SRC_CK = $(addprefix $(SRCS)/, $(SRC_CK1))

SRC_PS1 =	push_swap.c get_pile_a.c quicksort.c fts_checker.c sort_list.c \
		 	small_lists.c tools.c tools2.c tools3.c list_inst.c instructions.c \
		 	common_tools.c

SRC_PS = $(addprefix $(SRCS)/, $(SRC_PS1))

HD = ./includes/

CFLAGS = -Wall -Werror -Wextra

LFLAGS = -L libft/ -lft

OBJ_CK = $(SRC_CK1:.c=.o)

OBJ_PS = $(SRC_PS1:.c=.o)

CC = gcc

all: lib $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(SRC_CK)
	@$(CC) $(CFLAGS) -I$(HD) -c $(SRC_CK)
	@gcc $(OBJ_CK) $(LFLAGS) -o $@
	@echo "\033[32m./checker"

$(PUSH_SWAP): $(SRC_PS)
	@$(CC) $(CFLAGS) -c $(SRC_PS) -I$(HD)
	@gcc $(OBJ_PS) $(LFLAGS) -o $@
	@echo "\033[32m./push_swap"

lib:
	@make -C libft/
	@echo "\033[32mlibft.a"

clean_ck:
	@rm -f $(OBJ_CK)

clean_ps:
	@rm -f $(OBJ_PS)

clean: clean_ck clean_ps
	@make clean -C libft/

fclean_ck: clean_ck
	@rm -f $(CHECKER)

fclean_ps: clean_ps
	@rm -f $(PUSH_SWAP)

fclean: fclean_ps fclean_ck
	@make fclean -C libft/

re: fclean all
