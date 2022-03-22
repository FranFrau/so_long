/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:08:00 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/19 15:11:09 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_error(char *s, int err, t_map *map)
{
	free_matrix(map->map);
	ft_putstr_fd(s, 2);
	exit(err);
}

void	print_exit_error(char *s, int err, t_map *map)
{
	free_matrix(map->map);
	perror(s);
	exit(err);
}

void	print_bf_exit_error(char *s, int err)
{
	perror(s);
	exit(err);
}
