/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:44:13 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/14 12:36:33 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

static void	*ft_render(void *param)
{
	t_RT *const	rt = param;

	while (true)
	{
		if (!rt->update)
		{
			usleep(4000);
			continue ;
		}
		if (rt->mlx == NULL)
			break ;
		ft_draw_world(rt);
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
static bool	ft_init_rt(t_RT *rt, char *input)
{
	const float		aspect_ratio = 16.0 / 9.0;
	const int32_t	image_width = WIN_WIDTH;
	const int32_t	image_height = (int32_t)(image_width / aspect_ratio);

	(void)input;
	if (!ft_read_map(rt, input))
		return (false);
	rt->mlx = mlx_init(image_width, image_height, "👾 MegaRT 👾", false);
	if (mlx_errno)
		return (ft_putendl_fd(mlx_strerror(mlx_errno), STDERR_FILENO), false);
	rt->canvas = mlx_new_image(rt->mlx, image_width, image_height);
	if (mlx_errno)
		return (ft_putendl_fd(mlx_strerror(mlx_errno), STDERR_FILENO), false);
	if (mlx_image_to_window(rt->mlx, rt->canvas, 0, 0) == -1)
		return (ft_putendl_fd(mlx_strerror(mlx_errno), STDERR_FILENO), false);
	ft_new_camera(ft_get_active_camera(rt), ft_new_fvec3(0, 0, 0), 10);
	if (pthread_create(&rt->render_thread, NULL, &ft_render, rt) != 0)
		return (false);
	pthread_detach(rt->render_thread);
	return (true);
}

static void	ft_hook(void *param)
{
	t_RT *const	rt = param;

	if (mlx_is_key_down(rt->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(rt->mlx);
	if (mlx_is_key_down(rt->mlx, MLX_KEY_W))
	{
		ft_get_active_camera(rt)->position.z -= 0.05f;
		rt->update = true;
	}
	if (mlx_is_key_down(rt->mlx, MLX_KEY_S))
	{
		ft_get_active_camera(rt)->position.z += 0.05f;
		rt->update = true;
	}
	if (mlx_is_key_down(rt->mlx, MLX_KEY_D))
	{
		ft_get_active_camera(rt)->position.x += 0.05f;
		rt->update = true;
	}
	if (mlx_is_key_down(rt->mlx, MLX_KEY_A))
	{
		ft_get_active_camera(rt)->position.x -= 0.05;
		rt->update = true;
	}
	if (mlx_is_key_down(rt->mlx, MLX_KEY_E))
	{
		ft_get_active_camera(rt)->position.y += 0.05f;
		rt->update = true;
	}
	if (mlx_is_key_down(rt->mlx, MLX_KEY_Q))
	{
		ft_get_active_camera(rt)->position.y -= 0.05f;
		rt->update = true;
	}
	if (mlx_is_key_down(rt->mlx, MLX_KEY_PAGE_UP))
	{
		ft_get_active_camera(rt)->fov += 0.5f;
		rt->update = true;
	}
	if (mlx_is_key_down(rt->mlx, MLX_KEY_PAGE_DOWN))
	{
		ft_get_active_camera(rt)->fov -= 0.5f;
		rt->update = true;
	}
	ft_update_camera(rt);
}

/**
 * Application entry point.
 * 
 * @param argc Argument count.
 * @param argv Argument values.
 * @return Exit status.
 */
int32_t	main(int32_t argc, char *argv[])
{
	t_RT	rt;

	ft_bzero(&rt, sizeof(t_RT));
	if (argc - 1 != 1)
	{
		ft_putendl_fd("MegaRT: Invalid args: ./MegaRT <file>", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	rt.update = true;
	if (!ft_init_rt(&rt, argv[1]))
		return (EXIT_FAILURE);
	mlx_loop_hook(rt.mlx, &ft_hook, &rt);
	mlx_loop(rt.mlx);
	mlx_terminate(rt.mlx);
	rt.mlx = NULL;
	return (EXIT_SUCCESS);
}
