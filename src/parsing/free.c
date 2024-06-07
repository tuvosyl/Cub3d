/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:15:56 by vsoltys           #+#    #+#             */
/*   Updated: 2024/06/07 16:55:41 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_data(t_data *data)
{
	if (data->map.map)
		free_split(data->map.map);
	free(data->texture_path.north_texture);
	free(data->texture_path.south_texture);
	free(data->texture_path.west_texture);
	free(data->texture_path.east_texture);
	free(data->textures.north_pixel);
	free(data->textures.south_pixel);
	free(data->textures.west_pixel);
	free(data->textures.east_pixel);
}
