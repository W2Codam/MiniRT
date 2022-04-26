/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 19:20:35 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/26 13:28:21 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Private =//

static t_FVec3	ft_hit_nothing(t_Ray ray)
{
	(void)ray;
	return (ft_new_fvec3(0.1f, 0.1f, 0.1f));
}

static t_FVec3	ft_ray_color(t_RT *rt, t_Ray ray)
{
	t_Hit		hit;
	t_FVec3		normal;
	t_FVec3		out_color;
	const bool	is_hit = ft_ray_to_world(rt, ray, &normal, &hit);

	if (is_hit)
		out_color = ft_apply_lights(rt, ray, &hit, &normal);
	else
		out_color = ft_hit_nothing(ray);
	return (out_color);
}

t_FVec3	ft_mat3_mult_dir(t_FVec3 matrix[3], t_FVec3 dir)
{
	t_FVec3	new;

	new.x = dir.x * matrix[0].raw[0] + dir.y * matrix[1].raw[0] + \
	dir.z * matrix[2].raw[0];
	new.y = dir.x * matrix[0].raw[1] + dir.y * matrix[1].raw[1] + \
	dir.z * matrix[2].raw[1];
	new.z = dir.x * matrix[0].raw[2] + dir.y * matrix[1].raw[2] + \
	dir.z * matrix[2].raw[2];
	return (new);
}

static t_Ray	ft_fire_ray(t_RT *rt, uint32_t x, uint32_t y)
{
	t_FVec3			ws;
	const float		ratio = \
	(float)rt->canvas->width / (float)rt->canvas->height;
	t_Camera *const	camera = ft_get_active_camera(rt);

	ws.x = (2 * ((x + 0.5) / rt->canvas->width) - 1) * camera->fov * ratio;
	ws.y = (1 - 2 * ((y + 0.5) / rt->canvas->height)) * camera->fov;
	ws.z = 1;
	return (ft_new_ray(camera->position, \
	ft_normalize_fvec3_2(ft_mat3_mult_dir(camera->rotation_matrix, ws))));
}

//= Public =//

void	ft_draw_world(t_RT *rt)
{
	int32_t		x;
	int32_t		y;
	t_Ray		ray;
	t_FVec3		color;

	y = 0;
	while (y < ((int32_t)rt->canvas->height))
	{
		x = 0;
		while (x < ((int32_t)rt->canvas->width))
		{
			ft_bzero(&color, sizeof(t_FVec3));
			ray = ft_fire_ray(rt, x, y);
			color = ft_ray_color(rt, ray);
			mlx_put_pixel(rt->canvas, x, y, ft_to_rgba(color));
			x++;
		}
		y++;
	}
}
