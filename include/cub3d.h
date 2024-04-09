/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:44:25 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/09 17:27:33 by vsoltys          ###   ########.fr       */
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
typedef struct s_4int
{
	int		r;
	int		g;
	int		b;
	int		l;
}	t_4int;

typedef struct s_map
{
	char 		**map;
	char		*map_path;
	int			fd;
}	t_map;

typedef struct s_texture
{
	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*east_texture;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*north_image;
	mlx_image_t	*south_image;
	mlx_image_t	*west_image;
	mlx_image_t	*east_image;
}	t_image;

typedef struct s_texture_path
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
} t_texture_path;

typedef struct s_data
{
	mlx_t		*mlx;
	t_map		map;
	t_texture 	texture;
	t_image 	image;
	t_texture_path	texture_path;
	t_4int 		ground_color;
	t_4int		ceilling_color;
}	t_data;

/*###########################################################################*/
/*                                 Fonctions                                 */
/*###########################################################################*/

int	checking_init(t_data *data, int argc, char **argv);
int extract_value(t_data *data);

#endif
