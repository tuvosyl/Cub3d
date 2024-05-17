/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:22:02 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/17 09:56:43 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	start_game(t_data *data)
{
	data->mlx = mlx_init(1920, 1080, "Cub3D", true);
	if (!data->mlx)
		return ;
	texture_to_image(data);
	mlx_loop(data->mlx);
	delete_texture(data);
	mlx_terminate(data->mlx);
}