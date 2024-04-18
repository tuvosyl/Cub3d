/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:04:06 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/18 09:59:48 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_data data;

	checking_init(&data, argc, argv);
	if (parsing(&data))
		return (1);	
	if (DEBUG)
		printf_debug(&data);
	create_collision_map(&data);
	return (0);
}