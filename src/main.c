/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 11:06:10 by lde-la-h      #+#    #+#                 */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2022/04/04 11:38:07 by dvan-der         ###   ########.fr       */
=======
/*   Updated: 2022/04/04 10:42:43 by lde-la-h      ########   odam.nl         */
>>>>>>> b88448d3112d9f10a53fd381d478512c64ca7c01
=======
/*   Updated: 2022/04/04 13:13:57 by lde-la-h      ########   odam.nl         */
>>>>>>> 1614de3a0c828e4425e2df090fc03a18763ee065
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
	t_rt *const	rt = param;

	while (true)
	{
		if (!rt->update)
		{
			// Saves on peformance, as we avoid calling the loop constantly times.
			usleep(4000);
			continue ;
		}
		ft_draw(rt);
		rt->update = false;
	}
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
	const float		aspect_ratio = 16.0 / 9.0;
	const int32_t	image_width = WIN_WIDTH;
	const int32_t	image_height = (int32_t)(image_width / aspect_ratio);

	rt->mlx = mlx_init(image_width, image_height, "👾 MegaRT 👾", false);
	if (mlx_errno)
		return (ft_putendl_fd(mlx_strerror(mlx_errno), STDERR_FILENO), false);
	rt->window_img = mlx_new_image(rt->mlx, image_width, image_height);
	if (mlx_errno)
		return (ft_putendl_fd(mlx_strerror(mlx_errno), STDERR_FILENO), false);
	if (mlx_image_to_window(rt->mlx, rt->window_img, 0, 0) == -1)
		return (ft_putendl_fd(mlx_strerror(mlx_errno), STDERR_FILENO), false);
	// if (pthread_mutex_init(&rt->lock, NULL) != 0)
	// 	return (ft_putendl_fd("RT: Mutex Failure!", STDERR_FILENO), false);
	if (pthread_create(&rt->render_thread, NULL, &ft_render, rt) != 0)
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
	t_rt *const	rt = param;

	if (mlx_is_key_down(rt->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(rt->mlx);
	if (mlx_is_key_down(rt->mlx, MLX_KEY_U))
		rt->update = true;
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
<<<<<<< HEAD

	if (!ft_init_rt(&rt, argv[1]))
=======
	if (!ft_init_rt(&rt))
>>>>>>> 1614de3a0c828e4425e2df090fc03a18763ee065
		return (EXIT_FAILURE);
	mlx_loop_hook(rt.mlx, &ft_hook, &rt);
	mlx_close_hook(rt.mlx, &ft_close_hook, &rt);
	mlx_loop(rt.mlx);
	mlx_terminate(rt.mlx);
	return (EXIT_SUCCESS);
}
