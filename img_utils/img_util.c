/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:41:54 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/21 23:25:34 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	gate_animation(t_map *m)
{
	int		i;
	int		j;
	t_win	v;
	t_img	f;

	v = m->win;
	f = m->img;
	i = -1;
	while (m->map[++i])
	{
		j = -1;
		while (m->map[i][++j])
		{
			if (m->map[i][j] == 'E')
			{
				if (m->check.collectible == 0)
					mlx_put_image_to_window(v.mlx, v.win, f.exit2, \
					j * 64, i * 64);
				else
					mlx_put_image_to_window(v.mlx, v.win, f.exit, \
					j * 64, i * 64);
			}
		}
	}
}

void	set_imgs_2(t_map *m, int i, int j, int value)
{
	t_win	v;
	t_img	f;
	int		k;

	k = m->spl;
	v = m->win;
	f = m->img;
	if (value == 3)
	{
		mlx_put_image_to_window(v.mlx, v.win, f.floo, j * 64, (i - 1) * 64);
		mlx_put_image_to_window(v.mlx, v.win, m->imgs[k + 16], j * 64, i * 64);
	}
	else if (value == 4)
	{
		mlx_put_image_to_window(v.mlx, v.win, f.floo, (j + 1) * 64, i * 64);
		mlx_put_image_to_window(v.mlx, v.win, m->imgs[k + 8], j * 64, i * 64);
	}
}

void	set_imgs(t_map *m, int i, int j, int value)
{
	t_win	v;
	t_img	f;
	int		k;

	k = m->spl;
	v = m->win;
	f = m->img;
	if (value == 1)
	{
		mlx_put_image_to_window(v.mlx, v.win, f.floo, j * 64, (i + 1) * 64);
		mlx_put_image_to_window(v.mlx, v.win, m->imgs[k + 24], j * 64, i * 64);
	}
	else if (value == 2)
	{
		mlx_put_image_to_window(v.mlx, v.win, f.floo, (j - 1) * 64, i * 64);
		mlx_put_image_to_window(v.mlx, v.win, m->imgs[k], j * 64, i * 64);
	}
	else
		set_imgs_2(m, i, j, value);
}
