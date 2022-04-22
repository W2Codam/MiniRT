/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rendering.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 19:20:35 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/21 17:07:27 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Private =//

static t_FVec3	ft_hit_nothing(t_Ray ray)
{
	/*
	float		t;
	t_FVec3		a;
	t_FVec3		b;

	ft_normalize_fvec3(&ray.dir);
	t = 0.5f * (ray.dir.y + 1.0f);
	a = ft_mul_fvec3f(ft_new_fvec3(1.0f, 1.0f, 1.0f), 1.0f - t);
	b = ft_mul_fvec3f(ft_new_fvec3(0.5f, 0.7f, 1.0f), t);
	return (ft_add_fvec3(a, b));
	*/
	(void)ray;
	return (ft_new_fvec3(0.1f, 0.1f, 0.1f));
}

// Kd * DOT(N, L) * Od * Ld
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

float	ft_rad(float angle)
{
	return (angle * M_PI * 0.5f);
}

static t_FVec3	ft_make_camray(t_RT *rt, t_Camera *camera, uint32_t x, uint32_t y)
{
	const float		u = x - (rt->canvas->width) * 0.5f;
	const float		v = y - (rt->canvas->height) * 0.5f;
	const float		c = rt->canvas->width / (2 * tanf((ft_rad(camera->fov)) \
					/ 180.0));

	return (ft_normalize_fvec3_2(ft_new_fvec3(u, v, c)));
}

static t_Ray	ft_fire_ray(t_RT *rt, uint32_t x, uint32_t y)
{
	t_FVec3			dir;
	t_Camera *const	camera = ft_get_active_camera(rt);

	dir = ft_make_camray(rt, camera, x, y);
	dir = ft_rotate_vec(dir, 0, X);
	dir = ft_rotate_vec(dir, 0, Y);
	dir = ft_rotate_vec(dir, 0, Z);
	return (ft_new_ray(camera->position, dir));
}

//= Public =//

void	ft_draw_world(t_RT *rt)
{
	int32_t		x;
	int32_t		y;
	t_Ray		ray;
	t_FVec3		color;

	y = ((int32_t)rt->canvas->height) - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < ((int32_t)rt->canvas->width))
		{
			ft_bzero(&color, sizeof(t_FVec3));
			ray = ft_fire_ray(rt, x, y);
			color = ft_ray_color(rt, ray);
			mlx_put_pixel(rt->canvas, x, rt->canvas->height - y, ft_to_rgba(color));
			x++;
		}
		y--;
	}
}
