/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:05:09 by vsoltys           #+#    #+#             */
/*   Updated: 2024/06/13 19:12:13 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	convert_to_hex(uint32_t *texture_map, uint8_t *pixels)
{
	int		i;
	t_4int	color;

	i = 0;
	while (i < TEXTURE_SIZE * TEXTURE_SIZE)
	{
		color.r = pixels[i * 4];
		color.g = pixels[i * 4 + 1];
		color.b = pixels[i * 4 + 2];
		color.l = pixels[i * 4 + 3];
		texture_map[i] = ft_pixel(color.r, color.g, color.b, color.l);
		i++;
	}
}
