/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:03:27 by ffrau             #+#    #+#             */
/*   Updated: 2022/05/21 16:17:16 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	matrix_helper(t_map *m)
{
	int		j;
	int		i;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'S')
				m->map[i][j] = 'F';
			j++;
		}
		i++;
	}
}

bool	can_move(t_map *m, int i, int j, char c)
{
	if (c == 'F' && (i == m->y && j == m->x))
		end_game(m, false);
	return (c == 'F' && m->map[i][j] != '1'
				&& m->map[i][j] != 'C' && m->map[i][j] != 'P'
				&& m->map[i][j] != 'F' && m->map[i][j] != 'E');
}

void	staff_loop(t_map *m)
{
	if (!(staff_delay(m, 3500)))
		return ;
	if (!m->can_staff_move)
		return ;
	if (m->e_delay == 1)
		enemy_animation_1(m);
	else if (m->e_delay == 2)
		enemy_animation_2(m);
	else if (m->e_delay == 3)
		enemy_animation_3(m);
	else if (m->e_delay == 4)
	{
		enemy_animation_4(m);
		m->e_delay = 0;
	}
	m->spl = 0;
}

int	animation(t_map *m)
{
	coins_loop(m);
	staff_loop(m);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	m;

	is_valid(argc, argv, &m);
	m.win.mlx = mlx_init();
	if (!m.win.mlx)
		print_exit_error(MALLOC_ERR_TXT, MALLOC_ERR, &m);
	m.win.win = mlx_new_window(m.win.mlx, m.col * 64, m.row * 64, "So long");
	init_win(&m);
	fill_windows(&m);
	mlx_hook(m.win.win, 2, 1L << 0, command, &m);
	mlx_loop_hook(m.win.mlx, animation, &m);
	mlx_hook(m.win.win, 17, 0, close_windows, &m);
	mlx_loop(m.win.mlx);
	free_matrix(m.map);
}
