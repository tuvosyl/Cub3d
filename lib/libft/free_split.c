/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:21:42 by val               #+#    #+#             */
/*   Updated: 2024/04/10 18:22:57 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Libere un tableau de chaîne de caractères
void	free_split(char **table)
{
	int	j;

	j = 0;
	while (table[j])
	{
		free(table[j]);
		j++;
	}
	free(table);
}