/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_key_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:07:41 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/21 04:52:25 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_animation(t_map *m, int x, int y, t_dir dir)
{
	t_img	f;
	t_win	v;

	v = m->win;
	f = m->img;
	if (dir == UP)
		mlx_put_image_to_window(v.mlx, v.win, f.play4, x, y);
	else if (dir == DOWN)
		mlx_put_image_to_window(v.mlx, v.win, f.play2, x, y);
	else if (dir == LEFT)
		mlx_put_image_to_window(v.mlx, v.win, f.play3, x, y);
	else if (dir == RIGHT)
		mlx_put_image_to_window(v.mlx, v.win, f.play1, x, y);
}

void	move_helper(t_map *m, int x, int y, t_dir dir)
{
	t_img	f;
	int		tx;
	int		ty;

	tx = m->x * 64;
	ty = m->y * 64;
	f = m->img;
	mlx_put_image_to_window(m->win.mlx, m->win.win, f.floo, tx, ty);
	m->map[m->y][m->x] = '0';
	m->y = y;
	m->x = x;
	tx = m->x * 64;
	ty = m->y * 64;
	player_animation(m, tx, ty, dir);
	m->moves++;
	print_moves(m);
}

void	print_moves(t_map *map)
{
	char	*s;

	s = ft_itoa(map->moves);
	set_image_1(map, 0, 1);
	set_image_1(map, 0, 0);
	mlx_string_put(map->win.mlx, map->win.win, 10, 15, 0x0, "MOVES: ");
	mlx_string_put(map->win.mlx, map->win.win, 8, 14, 0x0, "MOVES: ");
	mlx_string_put(map->win.mlx, map->win.win, 12, 16, 0x0, "MOVES: ");
	mlx_string_put(map->win.mlx, map->win.win, 10, 15, 16777215, "MOVES: ");
	ft_putstr("Moves: ");
	mlx_string_put(map->win.mlx, map->win.win, 80, 15, 0x0, s);
	mlx_string_put(map->win.mlx, map->win.win, 78, 14, 0x0, s);
	mlx_string_put(map->win.mlx, map->win.win, 82, 16, 0x0, s);
	mlx_string_put(map->win.mlx, map->win.win, 80, 15, 16777215, s);
	ft_putstr(s);
	ft_putchar('\n');
	free(s);
}
