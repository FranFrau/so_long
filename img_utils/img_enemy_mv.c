/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_enemy_mv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 07:17:45 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/22 00:23:52 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enemy_animation_1(t_map *m)
{
	int		j;
	int		i;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->spl == 8)
				m->spl = 0;
			if (can_move(m, (i - 1), j, m->map[i][j]))
			{
				set_imgs(m, (i - 1), j, 1);
				m->map[i][j] = '0';
				m->map[i - 1][j] = 'S';
			}
			if ((i != 0 && m->map[i - 1]) && \
				(m->map[i - 1][j] == 'S' || m->map[i][j] == 'F'))
				m->spl++;
			j++;
		}
		i++;
	}
	matrix_helper(m);
}

void	enemy_animation_2(t_map *m)
{
	int		j;
	int		i;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->spl == 8)
				m->spl = 0;
			if (can_move(m, i, (j + 1), m->map[i][j]))
			{
				set_imgs(m, i, (j + 1), 2);
				m->map[i][j] = '0';
				m->map[i][j + 1] = 'S';
			}
			if (m->map[i][j + 1] && \
				(m->map[i][j + 1] == 'S' || m->map[i][j] == 'F'))
				m->spl++;
			j++;
		}
		i++;
	}
	matrix_helper(m);
}

void	enemy_animation_3(t_map *m)
{
	int		j;
	int		i;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->spl == 8)
				m->spl = 0;
			if (can_move(m, (i + 1), j, m->map[i][j]))
			{
				set_imgs(m, (i + 1), j, 3);
				m->map[i][j] = '0';
				m->map[i + 1][j] = 'S';
			}
			if (m->map[i + 1] && \
				(m->map[i + 1][j] == 'S' || m->map[i][j] == 'F'))
				m->spl++;
			j++;
		}
		i++;
	}
	matrix_helper(m);
}

void	enemy_animation_4(t_map *m)
{
	int		j;
	int		i;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->spl == 8)
				m->spl = 0;
			if (can_move(m, i, (j - 1), m->map[i][j]))
			{
				set_imgs(m, i, (j - 1), 4);
				m->map[i][j] = '0';
				m->map[i][j - 1] = 'S';
			}
			if (m->map[i][j - 1] && \
				(m->map[i][j - 1] == 'S' || m->map[i][j] == 'F'))
				m->spl++;
			j++;
		}
		i++;
	}
	matrix_helper(m);
}
