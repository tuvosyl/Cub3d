/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:32:40 by vsoltys           #+#    #+#             */
/*   Updated: 2024/05/17 09:56:00 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	error(t_data *data)
{
	if (data->textures.north_texture)
		mlx_delete_texture(data->textures.north_texture);
	if (data->textures.east_texture)
		mlx_delete_texture(data->textures.east_texture);
	if (data->textures.south_texture)
		mlx_delete_texture(data->textures.south_texture);
	if (data->textures.west_texture)
		mlx_delete_texture(data->textures.west_texture);
	free_data(data);
	ft_printf("Error\n↪\t%s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);                                                                                                                                                                                                                                                   
}

void load_png(t_data *data)
{
	data->textures.north_texture = mlx_load_png(data->texture_path.north_texture);
	if (!data->textures.north_texture)
		error(data);
	data->textures.south_texture = mlx_load_png(data->texture_path.south_texture);
	if (!data->textures.south_texture)
		error(data);
	data->textures.west_texture = mlx_load_png(data->texture_path.west_texture);
	if (!data->textures.west_texture)
		error(data);
	data->textures.east_texture = mlx_load_png(data->texture_path.east_texture);
	if (!data->textures.east_texture)
		error(data);
}

void	texture_to_image(t_data *data)
{
	data->images.north_image = mlx_texture_to_image(data->mlx, data->textures.north_texture);
	if (!data->images.north_image)
		error(data);
	data->images.south_image = mlx_texture_to_image(data->mlx, data->textures.south_texture);
	if (!data->images.south_image)
		error(data);
	data->images.west_image = mlx_texture_to_image(data->mlx, data->textures.west_texture);
	if (!data->images.west_image)
		error(data);
	data->images.east_image = mlx_texture_to_image(data->mlx, data->textures.east_texture);
	if (!data->images.east_image)
		error(data);
}

void	delete_texture(t_data *data)
{
	if (data->textures.north_texture)
		mlx_delete_texture(data->textures.north_texture);
	if (data->textures.east_texture)
		mlx_delete_texture(data->textures.east_texture);
	if (data->textures.south_texture)
		mlx_delete_texture(data->textures.south_texture);
	if (data->textures.west_texture)
		mlx_delete_texture(data->textures.west_texture);
	if (data->images.north_image)
		mlx_delete_image(data->mlx, data->images.north_image);
	if (data->images.east_image)
		mlx_delete_image(data->mlx, data->images.east_image);
	if (data->images.south_image)
		mlx_delete_image(data->mlx, data->images.south_image);
	if (data->images.west_image)
		mlx_delete_image(data->mlx, data->images.west_image);
}