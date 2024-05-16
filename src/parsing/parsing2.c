/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:24:38 by vsoltys           #+#    #+#             */
/*   Updated: 2024/05/16 17:45:13 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int tcheck_max_rgb_value(char *temp)
{
	int return_value;
	
	return_value = ft_atoi(temp);
	if (return_value > 255 || return_value < 0)
		return (-1);
	return (return_value);	
}

void tcheck_file(t_data *data)
{
	int i;

	i = 0;
	while (data->map.map_path[i])
		i++;
	if (data->map.map_path[i - 1] != 'b' || data->map.map_path[i - 2] != 'u' || data->map.map_path[i - 3] != 'c' || data->map.map_path[i - 4] != '.')
		exit_msg("Error\n↪\tMap file is not a .cub file");
	data->map.fd = open(data->map.map_path, O_RDONLY | __O_DIRECTORY);
	if (data->map.fd != -1)
	{
		close(data->map.fd);
		exit_msg("Error\n↪\tMap file is a directory");
	
	}
	data->map.fd = open(data->map.map_path, O_RDONLY);
	if (data->map.fd == -1)
		exit_msg("Error\n↪\tMap file not found");
}