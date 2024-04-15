/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:32:40 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/15 17:48:47 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	error(void)
{
	ft_printf("%s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);                                                                                                                                                                                                                                                   
}

void load_png(t_data *data)
{
	data->texture.north_texture = mlx_load_png(data->texture_path.north_texture);
	if (!data->texture.north_texture)
		error();
	data->texture.south_texture = mlx_load_png(data->texture_path.south_texture);
	if (!data->texture.south_texture)
		error();
	data->texture.west_texture = mlx_load_png(data->texture_path.west_texture);
	if (!data->texture.west_texture)
		error();
	data->texture.east_texture = mlx_load_png(data->texture_path.east_texture);
	if (!data->texture.east_texture)
		error();
}

void	texture_to_image(t_data *data)
{
	data->image.north_image = mlx_texture_to_image(data->mlx, data->texture.north_texture);
	if (!data->image.north_image)
		error();
	data->image.south_image = mlx_texture_to_image(data->mlx, data->texture.south_texture);
	if (!data->image.south_image)
		error();
	data->image.west_image = mlx_texture_to_image(data->mlx, data->texture.west_texture);
	if (!data->image.west_image)
		error();
	data->image.east_image = mlx_texture_to_image(data->mlx, data->texture.east_texture);
	if (!data->image.east_image)
		error();
}

void	delete_texture(t_data *data)
{
	mlx_delete_image(data->mlx, data->image.north_image);
	mlx_delete_texture(data->texture.north_texture);
	mlx_delete_image(data->mlx, data->image.south_image);
	mlx_delete_texture(data->texture.south_texture);
	mlx_delete_image(data->mlx, data->image.west_image);
	mlx_delete_texture(data->texture.west_texture);
	mlx_delete_image(data->mlx, data->image.east_image);
	mlx_delete_texture(data->texture.east_texture);
}