/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 08:48:14 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/22 01:10:24 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	coin_delay(t_map *map, int time)
{
	while (map->delay < time)
	{
		map->delay++;
		return (0);
	}
	map->delay = 0;
	map->n_anim++;
	return (1);
}

int	staff_delay(t_map *map, int time)
{
	while (map->delay2 < time)
	{
		map->delay2++;
		return (0);
	}
	map->e_delay++;
	map->delay2 = 0;
	return (1);
}
