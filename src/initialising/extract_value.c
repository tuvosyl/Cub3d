/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:05:37 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/11 13:18:11 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	return_str[i] = '\0';
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

t_4int extract_RGB(char *str, t_4int return_value)
{
    int i = 0;
    int which_value = 0;
    char *temp;

    while(str[i] && str[i] != '\n' && which_value != 3)
    {
        if(ft_isdigit(str[i]) == 1)
        {
            temp = extract_RGB_2(str, &i, &which_value);
            if (which_value == 1)
                return_value.r = ft_atoi(temp);
            else if (which_value == 2)
                return_value.g = ft_atoi(temp);
            else if (which_value == 3)
                return_value.b = ft_atoi(temp);
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
		data->ground_color = extract_RGB(str, data->ground_color);
	if (str[0] == 'C')
		data->ceilling_color = extract_RGB(str, data->ceilling_color);
}
int extract_value(t_data *data)
{
	int i;
	char *str;

	i = 0;
	data->map.fd = open(data->map.map_path, O_RDONLY);
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
	return(0);
}