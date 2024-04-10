/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:04:06 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/10 18:33:35 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void printf_debug(t_data *data)
{
	int i;

	i = 0;
	ft_printf("map = \n");
	while(data->map.map[i])
	{
		ft_printf("\t\t%s\n", data->map.map[i]);
		i++;
	}
	ft_printf("map.player_start = %c\n", data->map.player_start);
	ft_printf("map_path : \t\t\t%s\n", data->map.map_path);
	ft_printf("texture_path_north :\t%s\n", data->texture_path.north_texture);
	ft_printf("texture_path_south :\t%s\n", data->texture_path.south_texture);
	ft_printf("texture_path_west :\t%s\n", data->texture_path.west_texture);
	ft_printf("texture_path_east :\t%s\n", data->texture_path.east_texture);
	ft_printf("floor_color :\t%d,%d,%d,%d\n", data->ground_color.r, data->ground_color.g, data->ground_color.b, data->ground_color.l);
	ft_printf("ceiling_color :\t%d,%d,%d,%d\n", data->ceilling_color.r, data->ceilling_color.g, data->ceilling_color.b, data->ceilling_color.l);
}
int main(int argc, char **argv)
{
	printf("BONUS = %d\n", BONUS);
	printf("DEBUG = %d\n", DEBUG);
	t_data data;

	checking_init(&data, argc, argv);
	if(DEBUG)
		printf_debug(&data);
	return (0);
}