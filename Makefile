# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 13:14:48 by ffrau             #+#    #+#              #
#    Updated: 2022/03/22 01:14:34 by ffrau            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

P1		=	checker/
P2		=	errors/
P3		=	img_utils/
P4		=	map_utils/
P5		=	utils/

SL_SRC	=	so_long.c							\
			$(P1)checker_utils.c				\
			$(P1)checker.c						\
			$(P2)errors.c						\
			$(P3)img_util.c						\
			$(P3)img_coins_loop.c				\
			$(P3)img_enemy_mv.c					\
			$(P3)img_map_fill.c					\
			$(P4)map_end_game.c					\
			$(P4)map_key_helper.c				\
			$(P4)map_key_manager.c				\
			$(P4)map_loader.c					\
			$(P4)map_render.c					\
			$(P5)util_int.c						\
			$(P5)util_memory.c					\
			$(P5)util_str_manipulation.c		\
			$(P5)util_string.c					\
			$(P5)util_time.c					\

SL_OBJ	=	$(SL_SRC:.c=.o)

%.o: %.c
			$(CC) ${CFLAGS} -g -c $< -o $@ 

MLX		=	./libmlx.dylib


RM		=	rm -fr


$(NAME):	$(SL_OBJ)
			make -C ./minilibx
			@mv minilibx/libmlx.dylib ../so_long
			$(CC) $(CFLAGS) -o $(NAME) $(SL_OBJ) $(MLX)
			@(echo "\033[32mSO_LONG>> Compiled\033[0m")

all:		$(NAME)

clean:
			make clean -C minilibx
			rm -f *.o
			rm -f ./*/*.o
			@echo "\033[33mSO_LONG>> Deleted \".o\" files\033[0m"

fclean:		clean
			rm -rf $(NAME)
			@echo "\033[33mSO_LONG>> Project cleaned\033[0m"

re:			fclean all
			@echo "\033[0;92mSO_LONG>> Project cleaned and recompiled\033[0m"

re.all:		fclean

.PHONY:		all clean fclean re