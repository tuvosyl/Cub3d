/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:12:54 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/09 17:05:54 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


void	read_lenght_2(t_data *data, char *str, int i)
{
	i = 0;
	while (1)
	{
		str = get_next_line(data->map.fd);
		if (str == NULL)
			break ;
		data->map.map[i] = str;
		i++;
	}
	close(data->map.fd);
}

void	read_lenght(t_data *data)
{
	char	*str;
	int		i;

	i = 0;
	data->map.map = NULL;
	data->map.fd = open(data->map.map_path, O_RDONLY);
	str = get_next_line(data->map.fd);
	if (!str)
		return ;
	while (1)
	{
		free(str);
		str = get_next_line(data->map.fd);
		if (str == NULL)
			break ;
		i++;
	}
	close(data->map.fd);
	data->map.map = (char **)malloc(sizeof(char *) * (i + 1));
	data->map.fd = open(data->map.map_path, O_RDONLY);
	read_lenght_2(data, str, i);
}

int checking_init(t_data *data, int argc, char **argv)
{
	data->map.map_path = argv[1];
	(void)argc;
	read_lenght(data);
	extract_value(data);
	return (0);
}