/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:18:09 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/22 13:59:59 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_rays(t_data *data, int *rays)
{
	int		i;
	int		j;
	int		height;

	i = 0;
	printf("draw_rays\n");
	while (i != data->screen_size.x)
	{
		height = data->screen_size.y - rays[i] * 2;
		j = data->screen_size.y / 2 - height / 2;
		while (j != data->screen_size.y / 2 + height / 2)
		{
			
			j++;
		}
		i++;
	}
}

static int	single_raycast(t_data *data, double angle)
{
	t_2float	ray;
	int			distance;

	distance = 0;
	ray = data->player_pos;
	while (!is_wall(data, ray))
	{
		ray.x += cos(angle) * PLAYER_SPEED;
		ray.y += sin(angle) * PLAYER_SPEED;
		distance++;
	}
	return (distance);
}

static double	find_angle(t_data *data, int i)
{
	double	angle;

	angle = data->player_dir - (FOV / 2) + (i * FOV / data->screen_size.x);
	return (angle);
}

// Raycasting function called when the player or the camera moves
void	new_raycast(t_data *data)
{
	int		*rays;
	int		i;

	i = 0;
	rays = malloc(sizeof(int) * data->screen_size.x);
	while (i != data->screen_size.x)
	{
		rays[i] = single_raycast(data, find_angle(data, i));
		i++;
	}
	draw_rays(data, rays);
	free(rays);
}
