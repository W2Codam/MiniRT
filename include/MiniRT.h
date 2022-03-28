/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MiniRT.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 11:06:20 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/28 14:38:32 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
  __  __                      ____  _____ 
 |  \/  |  ___   __ _   __ _ |  _ \|_   _|
 | |\/| | / _ \ / _` | / _` || |_) | | |  
 | |  | ||  __/| (_| || (_| ||  _ <  | |  
 |_|  |_| \___| \__, | \__,_||_| \_\ |_|  
                |___/                     

Balls to the walls cross-platform, multi-threaded stud Raytracer on the CPU!
Written by W2.Wizard (lde-la-h) & Daan Van Der Plas (dvan-der) @ 2022
*/

#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <stdio.h>
# include <memory.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <stddef.h>
# include <errno.h>
# include "libft.h"
# include "Vector.h" /* math.h, vec2, ... */
# include "MLX42/MLX42.h"
# define STD_WIDTH 1080
# define STD_HEIGHT 720

/**
 * Struct that contains the application state.
 * 
 * @param mlx MLX42 instance handle.
 * @param render_thread The thread that does the pixel updating.
 */
typedef struct s_rt
{
	mlx_t		*mlx;
	mlx_image_t	*window_img;
	pthread_t	render_thread;
}	t_rt;

#endif // MINIRT_H
