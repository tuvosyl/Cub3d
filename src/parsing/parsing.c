/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentins <valentins@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:06:15 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/21 19:03:12 by valentins        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void	parsing(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		return (ft_printf("Error\n↪\tWrong number of arguments\n"), exit (1));
	data->map.map_path = argv[1];
	extract_value(data);
	if (data->textures.ceiling_color.r == -1
		|| data->textures.ceiling_color.g == -1
		|| data->textures.ceiling_color.b == -1)
		return (ft_printf("Error\n↪\tCeiling color not valid\n"), exit (1));
	if (data->textures.floor_color.r == -1 || data->textures.floor_color.g == -1
		|| data->textures.floor_color.b == -1)
		return (ft_printf("Error\n↪\tFloor color not valid\n"), exit (1));
	read_lenght(data);
	table_to_map(data);
	find_map_size_and_player_pos(data);
	if (data->map.player_start == '+')
		return (ft_printf("Error\n↪\tPlayer position not found\n"), exit (1));
}
