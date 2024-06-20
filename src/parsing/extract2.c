/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:01:23 by vsoltys           #+#    #+#             */
/*   Updated: 2024/06/20 10:48:30 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void	extract_value_2_2(t_data *data, char *str)
{
	if (str[0] == 'E' && str[1] == 'A')
	{
		if (data->texture_path.east_texture == NULL)
			data->texture_path.east_texture = extract_texture_path(str);
		else
			exit_msg(data, "double east texture", 1);
	}
	if (str[0] == 'F')
	{
		if (data->textures.floor_color.r == -1)
			data->textures.floor_color
				= extract_rgb(data, str, data->textures.floor_color);
		else
			exit_msg(data, "double definition of floor color", 1);
	}
	if (str[0] == 'C')
	{
		if (data->textures.ceiling_color.r == -1)
			data->textures.ceiling_color = extract_rgb(data, str,
					data->textures.ceiling_color);
		else
			exit_msg(data, "double definition of ceiling color", 1);
	}
}

void	exit_extract_rgb(t_data *data, char *str)
{
	free(str);
	while (1)
	{
		str = get_next_line(data->map.fd);
		if (str == NULL)
			break ;
		free(str);
	}
	exit_msg(data, "Error\n↪\tWrong character in RGB values", 1);
}
