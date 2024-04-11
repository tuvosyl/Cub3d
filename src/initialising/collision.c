/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:31:09 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/11 11:42:26 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	count_walls(t_data *data)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == '1')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

// Function to create the collision map
void	create_collision_map(t_data *data)
{
	t_2int	incr;

	incr = (t_2int){0, 0};
	data->map.collision_map = malloc(sizeof(t_2int) * count_walls(data) + 1);
	while (data->map.map[incr.y])
	{
		incr.x = 0;
		while (data->map.map[incr.y][incr.x])
		{
			if (data->map.map[incr.y][incr.x] == '1')
			{
				data->map.collision_map[incr.y].x = incr.x;
				data->map.collision_map[incr.y].y = incr.y;
			}
			incr.x++;
		}
		incr.y++;
	}
	data->map.collision_map[incr.y].x = -1;
	data->map.collision_map[incr.y].y = -1;
}

// Check si un point est dans une collision, ou hors map
bool	check_collision(t_data *data, t_2int pos)
{
	int		i;

	i = 0;
	while (data->map.collision_map[i].x != -1
		|| data->map.collision_map[i].y != -1)
	{
		if ((data->map.collision_map[i].x <= pos.x
				&& data->map.collision_map[i].x >= pos.x + 1
				&& data->map.collision_map[i].y <= pos.y
				&& data->map.collision_map[i].y >= pos.y + 1)
			|| pos.x <= 1 || pos.x >= data->map.map_size.x - 1
			|| pos.y <= 1 || pos.y >= data->map.map_size.y - 1)
			return (true);
		i++;
	}
	return (false);
}
