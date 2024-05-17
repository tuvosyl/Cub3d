/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:55:39 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/17 03:24:24 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void init_all(t_data *data)
{
	data->texture_path.north_texture = NULL;
	data->texture_path.south_texture = NULL;
	data->texture_path.west_texture = NULL;
	data->texture_path.east_texture = NULL;
	data->map.map = NULL;
	data->textures.ceiling_color.r = -1;
	data->textures.floor_color.r = -1;
	data->textures.floor_color.g = -1;
	data->textures.ceiling_color.g = -1;
	data->textures.floor_color.b = -1;
	data->textures.ceiling_color.b = -1;
}
int main(int argc, char **argv)
{
	t_data data;

	init_all(&data);
	parsing(&data, argc, argv);
	load_png(&data);
	data.mlx = mlx_init(1800, 900, "oui", true);
	texture_to_image(&data);
	//create_collision_map(&data);
	if (DEBUG)
		printf_debug(&data);
	//start_game(&data);
	mlx_set_cursor_mode(data.mlx, MLX_MOUSE_HIDDEN);
	mlx_resize_image(data.images.north_image, 1800, 900);
	mlx_image_to_window(data.mlx, data.images.north_image, 0, 0);
	mlx_loop(data.mlx);
	delete_texture(&data);
	free_data(&data);
	return (0);
}
