/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rendering.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 19:20:35 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/18 17:35:31 by W2Wizard      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Private =//

static t_FVec3	ft_hit_nothing(t_Ray ray)
{
	float		t;
	t_FVec3		a;
	t_FVec3		b;

	ft_normalize_fvec3(&ray.dir);
	t = 0.5f * (ray.dir.y + 1.0f);
	a = ft_mul_fvec3f(ft_new_fvec3(1.0f, 1.0f, 1.0f), 1.0f - t);
	b = ft_mul_fvec3f(ft_new_fvec3(0.5f, 0.7f, 1.0f), t);
	return (ft_add_fvec3(a, b));
}

// Kd * DOT(N, L) * Od * Ld
static t_FVec3	ft_ray_color(t_RT *rt, t_Ray ray)
{
	t_Hit		hit;
	t_FVec3		normal;
	t_FVec3		out_color;
	const bool	is_hit = ft_ray_to_world(rt, ray, &normal, &hit);

	// Work with 0-255
	if (is_hit)
	{
		// Regular light TODO: Move to apply light func instead
		for (uint16_t i = 0; i < rt->world.light_count; i++)
		{
			t_Light *light = &rt->world.lights[i];
			t_Hit	obstacle = ft_ray_intersect_any(rt, ft_new_ray(ft_ray_at(ray, hit.distance), ft_sub_fvec3(light->position, ft_ray_at(ray, hit.distance))));
			if (obstacle.distance != -1)
			{
				/* code */
			}
			out_color = ft_muls_color(hit.object->color, , rt->world.ambient.intensity);
		}

		// Ambient (Correct?)
		//out_color = ft_muls_color(hit.object->color, rt->world.ambient.color, rt->world.ambient.intensity);
		//printf("%f %f %f\n", out_color.x, out_color.y, out_color.z);
	}
	else
		out_color = ft_to_color(ft_hit_nothing(ray));

	return (out_color);
	//return (ft_mul_fvec3f(out_color, 1.0 / SAMPLE_COUNT));
}

static t_Ray	ft_fire_ray(t_RT *rt, t_Camera *camera, uint32_t x, uint32_t y)
{
	const float		u = (x + ft_randf()) / (rt->canvas->width - 1);
	const float		v = (y + ft_randf()) / (rt->canvas->height - 1);
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
	t_FVec3		color; // 255

	y = ((int32_t)rt->canvas->height) - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < ((int32_t)rt->canvas->width))
		{
			ft_bzero(&color, sizeof(t_FVec3));
			ray = ft_fire_ray(rt, ft_get_active_camera(rt), x, y);
			color = ft_ray_color(rt, ray);
			mlx_put_pixel(rt->canvas, x, rt->canvas->height - y, ft_from_color(color));
			x++;
		}
		y--;
	}
}
