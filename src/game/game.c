/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:22:02 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/07 11:32:04 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	resize(int width, int height, void *params)
{
	t_data	*data;

	data = (t_data *)params;
	data->screen_size.x = width;
	data->screen_size.y = height;
	if (DEBUG)
		printf("Window | width: %d, height: %d\n", width, height);
}

// minimap (bonus)
void	print_map(t_data *data)
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
						mlx_load_png("./maps/textures/minimap_wall.png")),
					j * 16, i * 16);
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
	data->camera_view = mlx_new_image(data->mlx,
			data->screen_size.x, data->screen_size.y);
	data->last_frame = mlx_get_time();
	// tests ;
	print_map(data);
	// ---
	mlx_resize_hook(data->mlx, resize, data);
	mlx_loop_hook(data->mlx, events, data);
	mlx_loop(data->mlx);
	delete_texture(data);
	mlx_terminate(data->mlx);
}
