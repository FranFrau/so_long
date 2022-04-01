/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:09:57 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/31 15:16:35 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "minilibx/mlx.h"
# include "errors/sl_errors.h"

typedef struct s_check_map
{
	int		space;
	int		wall;
	int		collectible;
	int		exit;
	int		pos;
	int		enemy;
	bool	correct;
}			t_check_map;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	char	*floor;
	char	*exit;
	char	*exit2;
	char	*wall;
	char	*coin;
	char	*play1;
	char	*play2;
	char	*play3;
	char	*play4;
}			t_win;

typedef struct s_img
{
	void	*enem;
	void	*spaw;
	void	*floo;
	void	*exit;
	void	*exit2;
	void	*wall;
	void	*coin;
	void	*play1;
	void	*play2;
	void	*play3;
	void	*play4;
}			t_img;

typedef enum e_game
{
	IN_GAME,
	W_GAME,
	L_GAME,
}	t_game;

typedef struct s_map
{
	t_check_map	check;
	t_win		win;
	t_img		img;
	t_game		status;
	void		**imgs;
	int			row;
	int			col;
	int			x;
	int			y;
	char		**map;
	int			moves;
	int			x_exit;
	int			y_exit;
	int			delay;
	int			delay2;
	int			e_delay;
	int			n_anim;
	int			spl;
	bool		can_staff_move;
}			t_map;

typedef enum e_keys
{
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	K_UP = 126,
	K_DOWN = 125,
	K_LEFT = 123,
	K_RIGHT = 124,
	ENTER_1 = 36,
	ENTER_2 = 76,
}	t_keys;

typedef enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}	t_dir;

/*									checker									*/
//checker_utils.c
void	check_map(t_map *map);
void	initial_value(t_map *map);
void	init_win(t_map *map);
void	fill_checker(t_map *map, char c);
//checker.c
void	is_closed(t_map *map);
void	is_valid(int argc, char **argv, t_map *map);
/*									errors									*/
//errors.c
void	print_error(char *s, int err, t_map *map);
void	print_exit_error(char *s, int err, t_map *map);
void	print_bf_exit_error(char *s, int err);
/*									img_utils								*/
//img_utils.c
void	gate_animation(t_map *m);
void	set_imgs(t_map *m, int i, int j, int value);
void	set_imgs_2(t_map *m, int i, int j, int value);
//img_coins_loop.c
void	coins_loop(t_map *m);
void	loop_helper(t_map *m);
void	set_coin(t_map *m, int j, int i);
int		coins_animation(t_map *m);
//img_enemy_mv.c
void	enemy_animation_1(t_map *m);
void	enemy_animation_2(t_map *m);
void	enemy_animation_3(t_map *m);
void	enemy_animation_4(t_map *m);
//img_map_fill.c
void	fill_windows(t_map *map);
void	fill_windows_2(t_map *map);
void	set_image_1(t_map *m, int i, int j);
void	set_image_2(t_map *m, int i, int j);
/*									map_utils								*/
//map_end_game.c
void	final_exit(t_map *map);
int		close_windows(t_map *map);
void	end_game(t_map *map, bool win);
void	esc(t_map *m);
void	print_end(t_map *m);
//map_key_helper.c
void	move_helper(t_map *m, int x, int y, t_dir dir);
void	print_moves(t_map *map);
//map_key_manager.c
int		command(int keycode, t_map *map);
void	move_down(t_map *m);
void	move_left(t_map *m);
void	move_right(t_map *m);
void	move_up(t_map *m);
//map_loader.c
void	load_helper(t_map *map, int fd);
void	load_map(t_map *map, char *mapf);
//map_render.c
void	render_images(t_map *map);
void	render_staff(t_map *map);
void	render_staff_2(t_map *map, void **imgs, int x);
/*									utils									*/
//util_int.c
char	*ft_itoa(int nb);
int		lenght(int nb, int base);
//util_memory.c
void	free_matrix(char **matrix);
//util_str_manipulation.c
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
void	matrix_manipulation(t_map *map);
//util_string.c
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *str);
//util_time.c
int		coin_delay(t_map *map, int time);
int		staff_delay(t_map *map, int time);
//so_long.c
void	matrix_helper(t_map *m);
bool	can_move(t_map *m, int i, int j, char c);
int		animation(t_map *m);
int		main(int argc, char **argv);
#endif