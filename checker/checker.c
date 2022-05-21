/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:32:34 by ffrau             #+#    #+#             */
/*   Updated: 2022/05/21 16:19:52 by ffrau            ###   ########.fr       */
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

bool	ft_check_map_name(char *filename)
{
	int	len;

	len = 0;
	while (filename[len])
		len++;
	if (filename[len - 4] != '.' || filename[len - 3] != 'b'
		|| filename[len - 2] != 'e' || filename[len - 1] != 'r')
		return (false);
	else
		return (true);
}

void	is_valid(int argc, char **argv, t_map *map)
{
	if (argc < 2)
		print_bf_exit_error(ft_strjoin(ERROR_TXT, ARGS_ERROR_TXT), ARGS_ERROR);
	if (!ft_check_map_name(argv[1]))
		exit(write(2, "Error, This isn't a .ber file\n", 30));
	initial_value(map);
	load_map(map, argv[1]);
	if (map->check.collectible < 1 || map->check.pos != 1
		|| map->check.exit < 1)
		print_error(NVALID_MAP_TXT, NVALID_MAP, map);
	check_map(map);
}
