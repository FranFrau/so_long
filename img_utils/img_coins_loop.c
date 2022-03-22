/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_coins_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 07:21:44 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/22 01:08:51 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	coins_loop(t_map *m)
{
	if (!(coin_delay(m, 700)))
		return ;
	coins_animation(m);
}

void	loop_helper(t_map *m)
{
	char	*s;
	char	*a;
	int		k;

	a = ft_itoa(m->n_anim);
	s = ft_strjoin("img/animation/coins", a);
	free(a);
	m->win.coin = s;
	free(s);
	s = ft_strjoin(m->win.coin, ".xpm");
	m->win.coin = s;
	m->img.coin = mlx_xpm_file_to_image(m->win.mlx, m->win.coin, &k, &k);
	free(s);
}

void	set_coin(t_map *m, int j, int i)
{
	t_img	f;
	int		h;

	f = m->img;
	h = 0;
	mlx_put_image_to_window(m->win.mlx, m->win.win, f.floo, j * 64, i * 64);
	while (h < 100)
		h++;
	mlx_put_image_to_window(m->win.mlx, m->win.win, f.coin, j * 64, i * 64);
}

int	coins_animation(t_map *m)
{
	int		j;
	int		i;

	loop_helper(m);
	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'C')
				set_coin(m, j, i);
			j++;
		}
		i++;
	}
	if (m->n_anim == 4)
		m->n_anim = 0;
	return (0);
}
