/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_to_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:29:14 by val               #+#    #+#             */
/*   Updated: 2024/06/13 16:22:36 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	player_dir(t_data *data)
{
	if (data->map.player_start == 'N')
		data->player_dir = 270;
	else if (data->map.player_start == 'E')
		data->player_dir = 0;
	else if (data->map.player_start == 'S')
		data->player_dir = 90;
	else if (data->map.player_start == 'W')
		data->player_dir = 180;
}
void alloc_map(t_data *data, int i)
{
	int j;
	int k;
	char **map_temp;
	
	j = 0;
	k = 0;
	while(data->map.map[j])
		j++;
	j--;
	printf("\nj = %d i = %d\n", j, i);
	if (j == i - 1)
		exit_msg("Error\n↪\twrong character in last line\n");
	map_temp = (char **)malloc(sizeof(char *) * (i + 1));
	while (i <= j)
	{
		map_temp[k] = ft_strdup(data->map.map[i]);
		i++;
		k++;
	}
	map_temp[k] = NULL;
	//ft_printf("oui k = %d\n", k);
	//free_split(data->map.map);
	data->map.map = NULL;
	data->map.map = map_temp;
}

void	table_to_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	data->map.player_start = '+';
	while(data->map.map[i])
		i++;
	i--;
	while(i >= 0)
	{
		j = 0;
		while(data->map.map[i][j] || data->map.map[i][j] == '\n')
		{
			if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S' || data->map.map[i][j] == 'E' || data->map.map[i][j] == 'W')
			{
				if (data->map.player_start == '+')
					data->map.player_start = data->map.map[i][j];
				else
					exit_msg("Error\n↪\ttoo many player\n");
				player_dir(data);
				data->map.map[i][j] = '0';
			}
			else if(data->map.map[i][j] != ' ' && data->map.map[i][j] != '1' && data->map.map[i][j] != '0' && data->map.map[i][j] != '\n' && data->map.map[i][j] != '\0')
				return (alloc_map(data, i - 1));
			j++;
		}
		i--;
	}
	exit_msg("Error\n↪\twtf are you doing here ? there is a problem\n");
}
