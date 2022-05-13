/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_end_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 07:34:44 by ffrau             #+#    #+#             */
/*   Updated: 2022/05/13 16:11:01 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	final_exit(t_map *map)
{
	free_matrix(map->map);
	exit(0);
}

int	close_windows(t_map *map)
{
	mlx_destroy_window(map->win.mlx, map->win.win);
	final_exit(map);
	return (0);
}

void	end_game(t_map *map, bool win)
{
	matrix_manipulation(map);
	if (win)
		map->status = W_GAME;
	else
		map->status = L_GAME;
	map->can_staff_move = false;
	print_end(map);
}

void	esc(t_map *m)
{
	void	*end;
	int		x;
	t_win	v;

	v = m->win;
	end = mlx_xpm_file_to_image(m->win.mlx, "img/end.xpm", &x, &x);
	mlx_put_image_to_window(v.mlx, v.win, end, 1 * 64, 1 * 64);
	if (m->status == W_GAME)
		print_error("You won! Ora torna a lavorare.\n", 0, m);
	else if (m->status == L_GAME)
		print_error("Game over. Prendi un community service!\n", 0, m);
	else
		return ;
}

void	print_end(t_map *m)
{
	void	*img;
	int		x;
	t_win	v;

	v = m->win;
	img = mlx_xpm_file_to_image(v.mlx, "img/win.xpm", &x, &x);
	if (m->status == L_GAME)
		img = mlx_xpm_file_to_image(v.mlx, "img/end.xpm", &x, &x);
	mlx_put_image_to_window(v.mlx, v.win, img, ((m->col * 64) / 2) - 256, \
		((m->row * 64) / 2) - 256);
	m->moves++;
	print_moves(m);
	mlx_put_image_to_window(v.mlx, v.win, img, ((m->col * 64) / 2) - 256, \
		((m->row * 64) / 2) - 256);
}
