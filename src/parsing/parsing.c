/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:06:15 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/17 03:13:51 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <fcntl.h>
#include <stdio.h>

char *extract_texture_path(char *str)
{
	int i;
	char	*return_str;

	i = 3;
	while(str[i] && str[i] != '\n')
		i++;
	return_str = malloc(sizeof(char) * i - 3 + 1);
	i = 3;
	while (str[i] && str[i] != '\n')
	{
		return_str[i - 3] = str[i];
		i++;
	}
	return_str[i - 3] = '\0';
	return(return_str);
	
}

char *extract_RGB_2(char *str, int *i, int *which_value)
{
    int counter;
    int counter_temp;
    char *temp;

	counter = 0;
	counter_temp = 0;
    while(ft_isdigit(str[*i]) == 1 && str[*i] && str[*i] != ',')
    {
        (*i)++;
        counter++;
    }
    temp = malloc(sizeof(char) * counter + 1);
    *i -= counter;
    while(counter_temp != counter)
    {
        temp[counter_temp] = str[*i + counter_temp];
        counter_temp++;
    }
    temp[counter_temp] = '\0';
    *i += counter;
    (*which_value)++;
    return temp;
}

t_3RGB extract_RGB(char *str, t_3RGB return_value)
{
    int i = 0;
    int which_value = 0;
    char *temp;

    while(str[i] && str[i] != '\n' && which_value != 3 && str[i] != '-')
    {
		if (str[i] == '-')
			exit_msg("Error\n↪\tRGB value is negative");
        if(ft_isdigit(str[i]) == 1)
        {
            temp = extract_RGB_2(str, &i, &which_value);
            if (which_value == 1)
                return_value.r = tcheck_max_rgb_value(temp);
            else if (which_value == 2)
                return_value.g = tcheck_max_rgb_value(temp);
            else if (which_value == 3)
                return_value.b = tcheck_max_rgb_value(temp);
            free(temp);
        }
        else
            i++;
    }
    return (return_value);
}

void	extract_value_2(t_data *data, char *str)
{
	int i;

	i = 0;
	(void)i;
	if(str[0] == 'N' && str[1] == 'O')
		data->texture_path.north_texture = extract_texture_path(str);
	if(str[0] == 'S' && str[1] == 'O')
		data->texture_path.south_texture = extract_texture_path(str);
	if(str[0] == 'W' && str[1] == 'E')
		data->texture_path.west_texture = extract_texture_path(str);
	if(str[0] == 'E' && str[1] == 'A')
		data->texture_path.east_texture = extract_texture_path(str);
	if (str[0] == 'F')
		data->textures.floor_color = extract_RGB(str, data->textures.floor_color);
	if (str[0] == 'C')
		data->textures.ceiling_color = extract_RGB(str, data->textures.ceiling_color);
}
int extract_value(t_data *data)
{
	int i;
	char *str;

	i = 0;
	tcheck_file(data);
	while (1)
	{
		str = get_next_line(data->map.fd);
		if (str == NULL)
			break ;
		extract_value_2(data, str);
		free(str);
		i++;
	}
	close(data->map.fd);
	if (!data->texture_path.north_texture || !data->texture_path.south_texture || !data->texture_path.west_texture || !data->texture_path.east_texture
		|| data->textures.ceiling_color.r == -1 || data->textures.ceiling_color.g == -1 || data->textures.ceiling_color.b == -1
		|| data->textures.floor_color.r == -1 || data->textures.floor_color.g == -1 || data->textures.floor_color.b == -1)
	{
		free_data(data);
		exit_msg("Error\n↪\tTexture path or color not found\n");
	}
	return(0);
}

void	parsing(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		return (ft_printf("Error\n↪\tWrong number of arguments\n"), exit (1));
	data->map.map_path = argv[1];
	extract_value(data);
	if (data->textures.ceiling_color.r == -1 || data->textures.ceiling_color.g == -1 || data->textures.ceiling_color.b == -1)
		return (ft_printf("Error\n↪\tCeiling color not valid\n"), exit (1));
	if (data->textures.floor_color.r == -1 || data->textures.floor_color.g == -1 || data->textures.floor_color.b == -1)
		return (ft_printf("Error\n↪\tFloor color not valid\n"), exit (1));
	read_lenght(data);
	table_to_map(data);
	if (data->map.player_start == '+')
		return (ft_printf("Error\n↪\tPlayer position not found\n"), exit (1));
}
