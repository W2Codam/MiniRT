/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 19:20:35 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/12 16:16:54 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Private =//

static bool	hit_sphere(t_FVec3 center, float radius, t_Ray *ray)
{
    const t_FVec3	oc = ft_sub_fvec3(ray->origin, center);
	const float		a = ft_dot_fvec3(ray->direction, ray->direction);
	const float		b = 2.0f * ft_dot_fvec3(oc, ray->direction);
	const float		c = ft_dot_fvec3(oc, oc) - radius * radius;
    const float		discriminant = b * b - 4 * a * c;

    return (discriminant > 0);
}

static t_FVec3	ft_ray_color(t_Ray ray)
{
	float	t;
	t_FVec3	a;
	t_FVec3	b;

	// Objects
    if (hit_sphere(ft_new_fvec3(0, 0, -1), 0.5f, &ray))
        return ft_new_fvec3(1, 0, 0);

	// Background
	ft_normalize_fvec3(&ray.direction);
	t = 0.5f * (ray.direction.y + 1.0f);
	a = ft_mul_fvec3f(ft_new_fvec3(1.0f, 1.0f, 1.0f), 1.0f - t);
	b = ft_mul_fvec3f(ft_new_fvec3(0.5f, 0.7f, 1.0f), t);
	return (ft_add_fvec3(a, b));
}

static t_Ray	ft_fire_ray(t_RT *rt, t_Camera *camera, uint32_t x, uint32_t y)
{
	const float		u = (float)x / (rt->canvas->width - 1);
	const float		v = (float)y / (rt->canvas->height - 1);
	const t_FVec3	a = ft_add_fvec3(camera->llc, \
						ft_mul_fvec3f(camera->horizontal, u));
	const t_FVec3	b = ft_sub_fvec3(ft_mul_fvec3f(camera->vertical, v), \
						camera->position);

	return (ft_new_ray(camera->position, ft_add_fvec3(a, b)));
}

//= Public =//

void	ft_draw_world(t_RT *rt)
{
	int32_t		x;
	int32_t		y;
	t_Ray		ray;
	uint32_t	color;

	y = ((int32_t)rt->canvas->height) - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < ((int32_t)rt->canvas->width))
		{
			ray = ft_fire_ray(rt, ft_get_active_camera(rt), x, y);
			color = ft_to_rgba(ft_ray_color(ray));
			mlx_put_pixel(rt->canvas, x, rt->canvas->height - y, color);
			x++;
		}
		y--;
	}
}
