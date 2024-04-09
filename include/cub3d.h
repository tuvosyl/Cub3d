/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:44:25 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/10 01:50:03 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*###########################################################################*/
/*                                  Defines                                  */
/*###########################################################################*/
// Program settings define
# ifdef DEBUG
#  define DEBUG 1
# else
#  define DEBUG 0
# endif

# ifdef BONUS
#  define BONUS 1
# else
#  define BONUS 0
# endif

// Custom defines
# define WHITESPACES "\t\n\v\f\r "

/*###########################################################################*/
/*                                 Includes                                  */
/*###########################################################################*/
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <stdbool.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <math.h>

/*###########################################################################*/
/*                                Structures                                 */
/*###########################################################################*/
typedef struct s_4int
{
	int		r;
	int		g;
	int		b;
	int		l;
}	t_4int;

typedef struct s_map // non
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

typedef struct s_texture_path // ratio
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
} t_texture_path;

// Main Structure
typedef struct s_data
{
	//char 		**map;
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

int				checking_init(t_data *data, int argc, char **argv);
int 			extract_value(t_data *data);

#endif
