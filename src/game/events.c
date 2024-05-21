/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentins <valentins@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:45:29 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/21 19:19:34 by valentins        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// return true if the player has moved
static bool	player_controls(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) && move_forward(data) != 2)
		return (true);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S) && move_backward(data) != 2)
		return (true);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A) && move_left(data) != 2)
		return (true);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D) && move_right(data) != 2)
		return (true);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	return (false);
}

// return true if the player moved camera
static bool	mouse_controls(t_data *data)
{
	t_2int	mouse_pos;

	mouse_pos.x = 0;
	mouse_pos.y = 0;
	mlx_get_mouse_pos(data->mlx, &mouse_pos.x, &mouse_pos.y);
	if (mouse_pos.x > data->screen_size.x / 2 + 10)
		data->player_dir += PLAYER_ROTATION_SPEED;
	else if (mouse_pos.x < data->screen_size.x / 2 - 10)
		data->player_dir -= PLAYER_ROTATION_SPEED;
	else
		return (false);
	mlx_set_mouse_pos(data->mlx, data->screen_size.x / 2,
		data->screen_size.y / 2);
	return (true);
}

// game loop
void	events(void *params)
{
	t_data			*data;
	static t_2int	previous_screen_size = {1920, 1080}; // test
	data = (t_data *)params;
	player_controls(data);
	mouse_controls(data);
	// if (player_controls(data))
	// 	new_raycast(data);
	// if (mouse_controls(data))
	// 	new_raycast(data);
	// tests :
	data->player_img->instances[0].x = data->player_pos.x * 32;
	data->player_img->instances[0].y = data->player_pos.y * 32;
	if (data->screen_size.x != previous_screen_size.x
		|| data->screen_size.y != previous_screen_size.y)
	{
		data->images.north_image->instances[1].x = data->screen_size.x - 64;
		data->images.north_image->instances[1].y = data->screen_size.y - 64;
		previous_screen_size.x = data->screen_size.x;
		previous_screen_size.y = data->screen_size.y;
	}
	// ---
}
