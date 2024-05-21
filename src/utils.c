/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentins <valentins@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:39:04 by vsoltys           #+#    #+#             */
/*   Updated: 2024/05/21 19:16:30 by valentins        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	exit_msg(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	extract_value_condition(t_data *data)
{
	if (!data->texture_path.north_texture
		|| !data->texture_path.south_texture
		|| !data->texture_path.west_texture
		|| !data->texture_path.east_texture
		|| data->textures.ceiling_color.r == -1
		|| data->textures.ceiling_color.g == -1
		|| data->textures.ceiling_color.b == -1
		|| data->textures.floor_color.r == -1
		|| data->textures.floor_color.g == -1
		|| data->textures.floor_color.b == -1)
	{
		free_data(data);
		exit_msg("Error\n↪\tTexture path or color not found\n");
	}
}
