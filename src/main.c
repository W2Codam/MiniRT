/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 11:06:10 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/28 15:02:04 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

/**
 * Hook function to intercept attempt to close the window.
 * 
 * @param param The game state, rt struct.
 */
void	ft_close_hook(void *param)
{
	const t_rt	*rt = param;

	mlx_close_window(rt->mlx);
}

/**
 * Generic hook used for all sorts of stuff.
 * 
 * @param param The game state, rt struct.
 */
void	ft_hook(void *param)
{
	const t_rt	*rt = param;

	if (mlx_is_key_down(rt->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(rt->mlx);
}

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
	rt.mlx = mlx_init(STD_WIDTH, STD_HEIGHT, "👾 MegaRT 👾", true);
	if (mlx_errno)
	{
		ft_putendl_fd(mlx_strerror(mlx_errno), STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	rt.window_img = mlx_new_image(rt.mlx, STD_WIDTH, STD_HEIGHT);
	if (mlx_errno)
	{
		ft_putendl_fd(mlx_strerror(mlx_errno), STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(rt.mlx, &ft_hook, &rt);
	mlx_close_hook(rt.mlx, &ft_close_hook, &rt);
	mlx_loop(rt.mlx);
	mlx_terminate(rt.mlx);
	return (EXIT_SUCCESS);
}
