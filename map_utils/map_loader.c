/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:29:01 by ffrau             #+#    #+#             */
/*   Updated: 2022/05/13 14:01:37 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_helper(t_map *map, int fd)
{
	char	*s;
	int		i;
	int		line;

	line = 0;
	s = get_next_line(fd);
	while (s)
	{
		i = 0;
		while (s[i])
		{
			fill_checker(map, s[i]);
			i++;
		}
		if (s[0] != '\0')
			line++;
		free(s);
		s = get_next_line(fd);
	}
	map->row = line;
	map->map = malloc(sizeof(char *) * line + 1);
	if (!map->map)
		print_exit_error(MALLOC_ERR_TXT, MALLOC_ERR, map);
}

void	load_map(t_map *map, char *mapf)
{
	int		fd;
	char	*s;
	int		i;

	fd = open(mapf, O_RDONLY);
	if (fd == -1)
		print_bf_exit_error(OPEN_ERROR_TXT, OPEN_ERROR);
	load_helper(map, fd);
	close(fd);
	fd = open(mapf, O_RDONLY);
	if (fd == -1)
		print_exit_error(OPEN_ERROR_TXT, OPEN_ERROR, map);
	i = -1;
	s = get_next_line(fd);
	while (s)
	{
		if (s[0] != '\0')
			map->map[++i] = s;
		s = get_next_line(fd);
	}
	map->map[++i] = 0;
	if (!map->map[0])
		print_error(NVALID_MAP_TXT, NVALID_MAP, map);
}
