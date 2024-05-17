/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:59:51 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/17 13:04:26 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void printf_debug(t_data *data)
{
	int i;

	i = 0;
	ft_printf("\033[0;35mmap :\033[0m\n");
	while(data->map.map[i])
	{
		ft_printf("\t\t%s", data->map.map[i]);
		i++;
	}
	ft_printf("\n\033[0;35mmap.player_start : \033[0m%c\n\n", data->map.player_start);
	ft_printf("\033[0;35mmap.celling : \033[0m%d,%d,%d\n", data->textures.ceiling_color.r, data->textures.ceiling_color.g, data->textures.ceiling_color.b);
	ft_printf("\033[0;35mmap.celling : \033[0m%d,%d,%d\n", data->textures.floor_color.r, data->textures.floor_color.g, data->textures.floor_color.b);
	ft_printf("\033[0;35mnorth_path : \033[0m%s\n", data->texture_path.north_texture);
	ft_printf("\033[0;35msouth_path : \033[0m%s\n", data->texture_path.south_texture);
	ft_printf("\033[0;35mwest_path  : \033[0m%s\n", data->texture_path.west_texture);
	ft_printf("\033[0;35meast_path  : \033[0m%s\n", data->texture_path.east_texture);
}
