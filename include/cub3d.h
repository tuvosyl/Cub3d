/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:44:25 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/09 15:12:09 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*###########################################################################*/
/*                                  Defines                                  */
/*###########################################################################*/

// Custom defines
# define WHITESPACES "\t\n\v\f\r "
/*###########################################################################*/
/*                                 Includes                                  */
/*###########################################################################*/
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <dirent.h>
# include <unistd.h>
# include "../minilibx/mlx42.h"

/*###########################################################################*/
/*                                Structures                                 */
/*###########################################################################*/
// Stock 3 integers, can be used for anything
typedef struct s_3int
{
	int		i;
	int		j;
	int		k;
}	t_3int;

#endif
