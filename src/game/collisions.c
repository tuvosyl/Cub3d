/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:03:59 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/31 11:31:06 by mgallais         ###   ########.fr       */
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
short	check_wall(t_data *data, t_2float ray, t_raywall raywall)
{
	t_2int		old_wall;

	old_wall.x = (int)ray.x;
	old_wall.y = (int)ray.y;
    while (is_wall(data, ray))
    {
        ray.x -= cos(deg_to_rad(data->player_dir)) * RAY_SPEED / 5;
        ray.y -= sin(deg_to_rad(data->player_dir)) * RAY_SPEED / 5;
        raywall.distance -= RAY_SPEED / 5;
    }
	if (old_wall.x != (int)ray.x)
	{
		if (cos(deg_to_rad(data->player_dir)) > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (sin(deg_to_rad(data->player_dir)) > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}
