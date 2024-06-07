/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:03:59 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/07 09:55:13 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// Check collision with a wall
bool	is_wall(t_data *data, t_2float pos)
{
	int		x;
	int		y;

	x = (int)pos.x;
	y = (int)pos.y;
	if (x <= 0 || y <= 0 || x >= data->map.map_size.x
		|| y >= data->map.map_size.y || data->map.map[y][x] == '1')
	{
		return (true);
	}
	return (false);
}

// Check wall type
short	check_wall_type(t_data *data, t_2float ray_pos)
{
	ray_pos.x += cos(deg_to_rad(data->player_dir)) * RAY_SPEED / 5;
	ray_pos.y += sin(deg_to_rad(data->player_dir)) * RAY_SPEED / 5;
	if (ray_pos.x - (int)ray_pos.x > ray_pos.y - (int)ray_pos.y)
	{
		if (data->player_dir > 180 && data->player_dir < 360)
			return (WEST);
		else
			return (EAST);
	}
	else
	{
		if (data->player_dir > 90 && data->player_dir < 270)
			return (NORTH);
		else
			return (SOUTH);
	}
}

// Check texture position
short	check_texture_pos(t_2float ray, t_raywall raywall)
{
	if (raywall.wall_type == NORTH)
		return ((int)(ray.x * 100) % TEXTURE_SIZE);
	else if (raywall.wall_type == EAST)
		return ((int)(ray.y * 100) % TEXTURE_SIZE);
	else if (raywall.wall_type == SOUTH)
		return (TEXTURE_SIZE - ((int)(ray.x * 100) % TEXTURE_SIZE) - 1);
	else
		return (TEXTURE_SIZE - ((int)(ray.y * 100) % TEXTURE_SIZE) - 1);
}
