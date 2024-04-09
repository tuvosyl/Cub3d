/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:04:06 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/09 17:45:03 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_data data;

	
	checking_init(&data, argc, argv);
	ft_printf("%s\n", data.texture_path.east_texture);
	ft_printf("%s\n", data.texture_path.north_texture);
	ft_printf("%s\n", data.texture_path.south_texture);
	ft_printf("%s\n", data.texture_path.west_texture);
	ft_printf("%d,%d,%d\n", data.ground_color.r, data.ground_color.g, data.ground_color.b);
	ft_printf("%d,%d,%d\n", data.ceilling_color.r, data.ceilling_color.g, data.ceilling_color.b);
	return (0);
}