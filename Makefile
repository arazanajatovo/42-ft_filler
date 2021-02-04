# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/28 16:07:31 by arazanaj     #+#   ##    ##    #+#        #
#    Updated: 2019/12/12 21:05:24 by arazanaj    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = arazanaj.filler
LIB = libft.a

LIB_PATH = ./libft/

OBJ =	./srcs/main.o \
		./srcs/filler.o

HDR = ./includes/

SDL = -L lib -lSDL2-2.0.0 -lSDL2_image-2.0.0 -lSDL2_ttf-2.0.0

#FLAGS = -Wall -Wextra -Werror
FLAGS = 

.PHONY : all clean cleanlib cleanme fclean fcleanlib fcleanme re

all : $(LIB) $(NAME)

$(NAME) : $(LIB_PATH)$(LIB) $(OBJ) $(HDR)ft_filler.h
	@gcc $(FLAGS) -I $(HDR) $(LIB_PATH)$(LIB) $(SDL) $(OBJ) -o $(NAME)
	@echo "\033[32mcurrent : "$(NAME)" created"

%.o : %.c
	@gcc $(FLAGS) -o $@ -c $^ -I $(HDR) 

$(LIB) :
	@make -C $(LIB_PATH)

clean : cleanlib cleanme

cleanlib :
	@make clean -C $(LIB_PATH)

cleanme :
	@rm -rf $(OBJ)
	@echo "\033[33mcurrent : .o deleted"

fclean : fcleanlib fcleanme

fcleanlib :
	@make fclean -C $(LIB_PATH)

fcleanme : cleanme
	@rm -rf $(NAME)
	@echo "\033[31mcurrent : "$(NAME)" deleted"

re : fclean all
