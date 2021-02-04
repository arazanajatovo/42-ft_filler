# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/16 12:26:52 by arazanaj     #+#   ##    ##    #+#        #
#    Updated: 2019/12/12 18:33:41 by arazanaj    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

OBJ =	./srcs/srcs_check/ft_isalnum.o \
		./srcs/srcs_check/ft_isalpha.o \
		./srcs/srcs_check/ft_isascii.o \
		./srcs/srcs_check/ft_isdigit.o \
		./srcs/srcs_check/ft_isprint.o \
		./srcs/srcs_display/ft_putchar.o \
		./srcs/srcs_display/ft_putchar_fd.o \
		./srcs/srcs_display/ft_putendl.o \
		./srcs/srcs_display/ft_putendl_fd.o \
		./srcs/srcs_display/ft_putnbr.o \
		./srcs/srcs_display/ft_putnbr_fd.o \
		./srcs/srcs_display/ft_putstr.o \
		./srcs/srcs_display/ft_putstr_fd.o \
		./srcs/srcs_lst/ft_lstadd.o \
		./srcs/srcs_lst/ft_lstaddback.o \
		./srcs/srcs_lst/ft_lstdel.o \
		./srcs/srcs_lst/ft_lstdelone.o \
		./srcs/srcs_lst/ft_lstfold.o \
		./srcs/srcs_lst/ft_lstiter.o \
		./srcs/srcs_lst/ft_lstmap.o \
		./srcs/srcs_lst/ft_lstnew.o \
		./srcs/srcs_lst/ft_lstsplit.o \
		./srcs/srcs_math/ft_atoi.o \
		./srcs/srcs_math/ft_itoa.o \
		./srcs/srcs_math/ft_pow.o \
		./srcs/srcs_math/ft_sqrt.o \
		./srcs/srcs_mem/ft_memalloc.o \
		./srcs/srcs_mem/ft_memccpy.o \
		./srcs/srcs_mem/ft_memchr.o \
		./srcs/srcs_mem/ft_memcmp.o \
		./srcs/srcs_mem/ft_memcpy.o \
		./srcs/srcs_mem/ft_memdel.o \
		./srcs/srcs_mem/ft_memmove.o \
		./srcs/srcs_mem/ft_memset.o \
		./srcs/srcs_printf/check.o \
		./srcs/srcs_printf/core.o \
		./srcs/srcs_printf/fct_char.o \
		./srcs/srcs_printf/fct_float.o \
		./srcs/srcs_printf/fct_int.o \
		./srcs/srcs_printf/fct_uint.o \
		./srcs/srcs_printf/ft_litoa_base.o \
		./srcs/srcs_printf/ft_strjoin_clean.o \
		./srcs/srcs_printf/get_input.o \
		./srcs/srcs_printf/init_pars.o \
		./srcs/srcs_printf/init_tab.o \
		./srcs/srcs_printf/parser.o \
		./srcs/srcs_str/ft_bzero.o \
		./srcs/srcs_str/ft_strcat.o \
		./srcs/srcs_str/ft_strchr.o \
		./srcs/srcs_str/ft_strclr.o \
		./srcs/srcs_str/ft_strcmp.o \
		./srcs/srcs_str/ft_strcpy.o \
		./srcs/srcs_str/ft_strdel.o \
		./srcs/srcs_str/ft_strdup.o \
		./srcs/srcs_str/ft_strequ.o \
		./srcs/srcs_str/ft_striter.o \
		./srcs/srcs_str/ft_striteri.o \
		./srcs/srcs_str/ft_strjoin.o \
		./srcs/srcs_str/ft_strlcat.o \
		./srcs/srcs_str/ft_strlen.o \
		./srcs/srcs_str/ft_strmap.o \
		./srcs/srcs_str/ft_strmapi.o \
		./srcs/srcs_str/ft_strncat.o \
		./srcs/srcs_str/ft_strncmp.o \
		./srcs/srcs_str/ft_strncpy.o \
		./srcs/srcs_str/ft_strnequ.o \
		./srcs/srcs_str/ft_strnew.o \
		./srcs/srcs_str/ft_strnstr.o \
		./srcs/srcs_str/ft_strrchr.o \
		./srcs/srcs_str/ft_strsplit.o \
		./srcs/srcs_str/ft_strstr.o \
		./srcs/srcs_str/ft_strsub.o \
		./srcs/srcs_str/ft_strtrim.o \
		./srcs/srcs_str/ft_tolower.o \
		./srcs/srcs_str/ft_toupper.o \
		./srcs/srcs_str/get_next_line.o

HDR += ./includes/

FLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[32mlibft : "$(NAME)" created"

%.o: %.c
	@gcc $(FLAGS) -I $(HDR) -c $^ -o $@

clean:
	@rm -rf $(OBJ)
	@echo "\033[33mlibft : .o deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[33mlibft : "$(NAME)" deleted"

re: fclean all
