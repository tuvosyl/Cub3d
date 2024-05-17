/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:03:59 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/17 09:20:21 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


int is_wall(t_data *data, t_2float pos)
{
	int x;
	int y;

	x = (int)pos.x;
	y = (int)pos.y;
	if (x < 0 || y < 0 || x >= data->map.map_size.x || y >= data->map.map_size.y)
		return 1;
	return (data->map.map[y][x] == '1');
}

// bonus
int	is_sprite(t_data *data, t_2float pos)
{
	int	x;
	int	y;

	x = (int)pos.x;
	y = (int)pos.y;
	if (x < 0 || y < 0 || x >= data->map.map_size.x || y >= data->map.map_size.y)
		return (0);
	return (data->map.map[y][x] == '2');
}