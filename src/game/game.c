/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentins <valentins@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:22:02 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/21 19:22:10 by valentins        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	resize(int width, int height, void *params)
{
	t_data	*data;

	data = (t_data *)params;
	data->screen_size.x = width;
	data->screen_size.y = height;
	if (DEBUG)
		printf("Window | width: %d, height: %d\n", width, height);
}

static void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == '1')
				mlx_image_to_window(data->mlx,
					mlx_texture_to_image(data->mlx,
						mlx_load_png("./maps/textures/sky.png")),
					j * 32, i * 32);
			j++;
		}
		i++;
	}
	data->player_img = mlx_texture_to_image(data->mlx,
			mlx_load_png("./maps/textures/player.png"));
	mlx_image_to_window(data->mlx,
		data->player_img, data->player_pos.x * 2, data->player_pos.y * 2);
}

void	start_game(t_data *data)
{
	data->mlx = mlx_init(data->screen_size.x,
			data->screen_size.y, "Cub3D", true);
	if (!data->mlx)
		return ;
	texture_to_image(data);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(data->mlx, data->screen_size.x / 2,
		data->screen_size.y / 2);
	// tests :
	print_map(data);
	mlx_image_to_window(data->mlx, data->images.north_image, 0, 0);
	mlx_image_to_window(data->mlx, data->images.north_image,
		data->screen_size.x - 64, data->screen_size.y - 64);
	// ---
	mlx_resize_hook(data->mlx, resize, data);
	mlx_loop_hook(data->mlx, events, data);
	mlx_loop(data->mlx);
	delete_texture(data);
	mlx_terminate(data->mlx);
}
