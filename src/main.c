/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 11:06:10 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/28 12:51:24 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int32_t	main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;

	mlx_t* mlx = mlx_init(1080, 720, "MegaRT", true);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}
