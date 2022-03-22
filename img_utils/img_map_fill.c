/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_map_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:36:49 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/21 13:59:59 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_windows(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			if (map->map[i][j] == '1')
				set_image_1(map, i, j);
		}
	}
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			if (map->map[i][j] != '1')
				set_image_1(map, i, j);
		}
	}
}
/*
void	fill_windows_2(t_map *map)
{
	int		i;
	int		j;
	t_win	v;
	t_img	f;

	i = 0;
	v = ma
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(v.mlx, v.win, f.wall, j * 64, i * 64);
			j++;
		}
		i++;
	}
}*/

void	set_image_1(t_map *m, int i, int j)
{
	t_img	f;
	t_win	v;

	v = m->win;
	f = m->img;
	if (m->spl == 8)
		m->spl = 0;
	if (m->map[i][j] == 'F' || m->map[i][j] == 'S')
	{
		mlx_put_image_to_window(v.mlx, v.win, f.floo, j * 64, i * 64);
		mlx_put_image_to_window(v.mlx, v.win, m->imgs[m->spl], j * 64, i * 64);
	}
	if (m->map[i][j] == 'P')
	{
		mlx_put_image_to_window(v.mlx, v.win, f.floo, j * 64, i * 64);
		mlx_put_image_to_window(v.mlx, v.win, f.play1, j * 64, i * 64);
		m->x = j;
		m->y = i;
	}
	else
		set_image_2(m, i, j);
}

void	set_image_2(t_map *m, int i, int j)
{
	t_img	f;
	t_win	v;

	v = m->win;
	f = m->img;
	if (m->map[i][j] == '0')
		mlx_put_image_to_window(v.mlx, v.win, f.floo, j * 64, i * 64);
	else if (m->map[i][j] == 'C')
		mlx_put_image_to_window(v.mlx, v.win, f.floo, j * 64, i * 64);
	else if (m->map[i][j] == 'E')
	{
		mlx_put_image_to_window(v.mlx, v.win, f.exit, j * 64, i * 64);
		m->x_exit = j;
		m->y_exit = i;
	}
	else if (m->map[i][j] == '1')
		mlx_put_image_to_window(v.mlx, v.win, f.wall, j * 64, i * 64);
}
