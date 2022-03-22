/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:32:34 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/21 03:36:16 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_closed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if ((i == 0 || i == map->row - 1)
				&& map->map[i][j] != '1')
				print_error(NO_BORDERS_TXT, NVALID_MAP, map);
			if ((j == 0 || j == map->col - 1) && map->map[i][j] != '1')
				print_error(NO_BORDERS_TXT, NVALID_MAP, map);
			j++;
		}
		i++;
	}
}

void	is_valid(int argc, char **argv, t_map *map)
{
	if (argc < 2)
		print_error(ft_strjoin(ERROR_TXT, ARGS_ERROR_TXT), ARGS_ERROR, map);
	initial_value(map);
	load_map(map, argv[1]);
	if (map->check.collectible < 1 || map->check.pos != 1
		|| map->check.exit < 1)
		print_error(NVALID_MAP_TXT, NVALID_MAP, map);
	check_map(map);
}
