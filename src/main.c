/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 11:06:10 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/28 14:55:37 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

/**
 * Entry point of the application.
 * 
 * @param[in] argc The argument count.
 * @param[in] argv The argument values
 * @return Either EXIT_SUCCESS or EXIT_FAILURE.
 */
int32_t	main(int32_t argc, char	*argv[])
{
	t_rt	rt;

	if (argc - 1 != 1)
	{
		ft_putendl_fd("MegaRT: Invalid args: ./MegaRT <file>", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	// TODO: Parse file...

	rt.mlx = mlx_init(STD_WIDTH, STD_HEIGHT, "👾 MegaRT 👾", true);
	if (mlx_errno)
	{
		ft_putendl_fd(mlx_strerror(mlx_errno), STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	mlx_loop(rt.mlx);
	mlx_terminate(rt.mlx);
	return (EXIT_SUCCESS);
}
