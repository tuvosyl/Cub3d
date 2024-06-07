/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:32:40 by vsoltys           #+#    #+#             */
/*   Updated: 2024/06/07 17:30:57 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	error(t_data *data)
{
	free_data(data);
	ft_printf("Error\n↪\tcant open a\n");
	exit(EXIT_FAILURE);
}

void	load_png_2(t_data *data)
{
	int	fd;

	fd = open(data->texture_path.east_texture, O_RDONLY);
	if (fd < 0)
	{
		free_data(data);
		exit_msg("cant open east texture");
	}
	close (fd);
	data->textures.north_texture
		= mlx_load_png(data->texture_path.north_texture);
	if (!data->textures.north_texture)
		error(data);
	data->textures.south_texture
		= mlx_load_png(data->texture_path.south_texture);
	if (!data->textures.south_texture)
		error(data);
	data->textures.west_texture = mlx_load_png(data->texture_path.west_texture);
	if (!data->textures.west_texture)
		error(data);
	data->textures.east_texture = mlx_load_png(data->texture_path.east_texture);
	if (!data->textures.east_texture)
		error(data);
}

void	load_png(t_data *data)
{
	int	fd;

	fd = open(data->texture_path.north_texture, O_RDONLY);
	if (fd < 0)
	{
		free_data(data);
		exit_msg("cant open north texture");
	}
	close (fd);
	fd = open(data->texture_path.south_texture, O_RDONLY);
	if (fd < 0)
	{
		free_data(data);
		exit_msg("cant open south texture");
	}
	close (fd);
	fd = open(data->texture_path.west_texture, O_RDONLY);
	if (fd < 0)
	{
		free_data(data);
		exit_msg("cant open west texture");
	}
	close (fd);
	load_png_2(data);
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
}
