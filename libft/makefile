# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaurel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 01:26:55 by amaurel           #+#    #+#              #
#    Updated: 2018/10/13 17:52:28 by amaurel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_NAME =		ft_printf get_next_line \

SRC_STORAGE =	stock_buff stock_args get_type get_type2 get_conversion \
				get_flags1 get_flags2 get_flags3 fts_stock_args \
				fts_stock_args2 fts_stock_args3 fts_stock_args4
			
SRC_TOOLS =		tools_nbr tools_putbuffer tools_unicode1 tools_unicode2 \
				tools_float

SRC_CONV =		ft_int fts_hexa ft_usage fts_oct ft_uns fts_point ft_char \
				ft_binary ft_str ft_percent ft_wchar ft_wstr ft_bonus_n \
				ft_hexfloat ft_hexfloat2

SRC_BONUS =		bonus1 bonus2

SRC = 	$(addsuffix .c, \
		$(SRC_NAME) \
		$(addprefix storage/, $(SRC_STORAGE)) \
		$(addprefix tools/, $(SRC_TOOLS)) \
		$(addprefix fts_conv/, $(SRC_CONV)) \
		$(addprefix bonuses/, $(SRC_BONUS)))

SRC_NAME_LIBFT =	putchar putstr memset bzero memcpy memccpy memmove memchr \
					memcmp strlen strdup strcpy strncpy strcat strncat strlcat \
					strchr strrchr strstr strnstr strcmp strncmp atoi isalpha \
					isdigit isalnum isascii isprint toupper tolower putendl \
					putnbr putchar_fd putstr_fd putendl_fd putnbr_fd memalloc \
					memdel strnew strdel strclr striter striteri strmap strmapi \
					strequ strnequ strsub strjoin strrev strtrim strsplit itoa \
					lstnew lstdelone lstdel lstadd lstiter lstmap atoi_base \
					itoa_base convert_base convert_base_int pow sqrt factorial \
					is_prime strcapitalize atointmax_t

SRC_LIBFT_c = $(addsuffix .c, $(SRC_NAME_LIBFT))
SRC_FT_LIBFT = $(addprefix ft_, $(SRC_LIBFT_c))
SRC_LIBFT = $(addprefix libft/, $(SRC_FT_LIBFT))

OBJ =	$(addsuffix .o, \
		$(SRC_NAME) $(SRC_STORAGE) $(SRC_TOOLS) $(SRC_CONV) $(SRC_BONUS))

OBJ_LIBFT = $(SRC_FT_LIBFT:.c=.o)

HD = ./include/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC) $(HD)ft_printf.h
	@$(CC) $(CFLAGS) -c $(SRC) $(SRC_LIBFT) -I$(HD) 
	@ar rc $(NAME) $(OBJ) $(OBJ_LIBFT)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) $(OBJ_LIBFT)

fclean: clean
	@rm -f $(NAME)

re: fclean all
