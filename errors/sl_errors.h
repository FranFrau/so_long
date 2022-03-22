/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:06:36 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/15 14:37:32 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_ERRORS_H
# define SL_ERRORS_H

# define ERROR_TXT "Error \n"
# define ARGS_ERROR_TXT "Too few arguments. Use /so_long <map_name>"
# define OPEN_ERROR_TXT "Error \nFile error, i can't open the file"
# define NVALID_MAP_TXT "Error \nInvalid map\n"
# define INV_LENGHT_TXT "Error \nInvalid lenght\n"
# define NO_BORDERS_TXT "Error \nThe map isn't closed\n"
# define MALLOC_ERR_TXT "Error \nI can't create the map\n"

typedef enum e_errors
{
	ARGS_ERROR = 0,
	OPEN_ERROR = 1,
	NVALID_MAP = -1,
	MALLOC_ERR = -1,
}	t_errors;

#endif