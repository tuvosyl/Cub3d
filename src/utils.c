/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:39:04 by vsoltys           #+#    #+#             */
/*   Updated: 2024/05/23 15:59:31 by mgallais         ###   ########.fr       */
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

double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180.0);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
