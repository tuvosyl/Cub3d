/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:32:21 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/17 16:12:12 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// ne marche pas pour l'instant

int	move_forward(t_data *data)
{
	t_2float	new_pos;

	new_pos.x = data->player_pos.x + cos(deg_to_rad(data->player_dir)) * PLAYER_SPEED;
	new_pos.y = data->player_pos.y + sin(deg_to_rad(data->player_dir)) * PLAYER_SPEED;
	if (!is_wall(data, new_pos))
		data->player_pos = new_pos;
	else
		return (1);
	return (0);
}

int	move_backward(t_data *data)
{
	t_2float	new_pos;

	new_pos.x = data->player_pos.x - cos(deg_to_rad(data->player_dir)) * PLAYER_SPEED;
	new_pos.y = data->player_pos.y - sin(deg_to_rad(data->player_dir)) * PLAYER_SPEED;
	if (!is_wall(data, new_pos))
		data->player_pos = new_pos;
	else
		return (1);
	return (0);
}

int	move_left(t_data *data)
{
	t_2float	new_pos;

	new_pos.x = data->player_pos.x + cos(deg_to_rad(data->player_dir - 90)) * PLAYER_SPEED;
	new_pos.y = data->player_pos.y + sin(deg_to_rad(data->player_dir - 90)) * PLAYER_SPEED;
	if (!is_wall(data, new_pos))
		data->player_pos = new_pos;
	else
		return (1);
	return (0);
}

int	move_right(t_data *data)
{
	t_2float	new_pos;

	new_pos.x = data->player_pos.x - cos(deg_to_rad(data->player_dir + 90)) * PLAYER_SPEED;
	new_pos.y = data->player_pos.y - sin(deg_to_rad(data->player_dir + 90)) * PLAYER_SPEED;
	if (!is_wall(data, new_pos))
		data->player_pos = new_pos;
	else
		return (1);
	return (0);
}
