/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 11:06:10 by lde-la-h      #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2022/04/04 11:38:07 by dvan-der         ###   ########.fr       */
=======
/*   Updated: 2022/04/04 10:42:43 by lde-la-h      ########   odam.nl         */
>>>>>>> b88448d3112d9f10a53fd381d478512c64ca7c01
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

/**
 * Entry routine for the render thread.
 * 
 * @param param The game state, rt struct.
 * @return NULL
 */
static void	*ft_render(void *param)
{
	(void) param;
	ft_putendl("Starting rendering...");
	return (NULL);
}

/**
 * Initializes the game state.
 * 
 * @param rt The game state to initialize.
 * @return True or false if Initialion succeeded.
 */
static bool	ft_init_rt(t_rt *rt, char *input)
{
	rt->mlx = mlx_init(STD_WIDTH, STD_HEIGHT, "👾 MegaRT 👾", true);
	if (mlx_errno)
	{
		ft_putendl_fd(mlx_strerror(mlx_errno), STDERR_FILENO);
		return (false);
	}
	rt->window_img = mlx_new_image(rt->mlx, STD_WIDTH, STD_HEIGHT);
	if (mlx_errno)
	{
		ft_putendl_fd(mlx_strerror(mlx_errno), STDERR_FILENO);
		return (false);
	}
	if (pthread_create(&rt->render_thread, NULL, &ft_render, &rt) != 0)
		return (false);
	pthread_detach(rt->render_thread);
	if (init_entities(rt, input))
		return (false);
	return (true);
}

/**
 * Hook function to intercept attempt to close the window.
 * 
 * @param param The game state, rt struct.
 */
static void	ft_close_hook(void *param)
{
	const t_rt	*rt = param;

	mlx_close_window(rt->mlx);
}

/**
 * Generic hook used for all sorts of stuff.
 * 
 * @param param The game state, rt struct.
 */
static void	ft_hook(void *param)
{
	const t_rt	*rt = param;

	if (mlx_is_key_down(rt->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(rt->mlx);

	if (mlx_is_key_down(rt->mlx, MLX_KEY_W))
	{

	}
	if (mlx_is_key_down(rt->mlx, MLX_KEY_A))
	{
		
	}
	if (mlx_is_key_down(rt->mlx, MLX_KEY_S))
	{
		
	}
	if (mlx_is_key_down(rt->mlx, MLX_KEY_D))
	{
		
	}
}

/**
 * Entry point of the application.
 * 
 * Initilizes the render state as well as launching
 * a render thread and MLX42.
 * 
 * @param[in] argc The argument count.
 * @param[in] argv The argument values
 * @return Either EXIT_SUCCESS or EXIT_FAILURE.
 */
int32_t	main(int32_t argc, char	*argv[])
{
	t_rt	rt;

	(void) argv;
	ft_bzero(&rt, sizeof(t_rt));
	if (argc - 1 != 1)
	{
		ft_putendl_fd("MegaRT: Invalid args: ./MegaRT <file>", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	if (!ft_init_rt(&rt, argv[1]))
		return (EXIT_FAILURE);

	mlx_loop_hook(rt.mlx, &ft_hook, &rt);
	mlx_close_hook(rt.mlx, &ft_close_hook, &rt);
	mlx_loop(rt.mlx);
	mlx_terminate(rt.mlx);
	return (EXIT_SUCCESS);
}
