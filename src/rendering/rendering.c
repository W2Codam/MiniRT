/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 19:30:49 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/11 14:34:57 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// Check if ray interesected any of the objects.
// TODO: Let Union objects have function pointer that checks if ray hit them instead.
/*
static bool	ft_intersect(t_rt *rt, t_Ray ray, t_FVec3 *out)
{

	// 1. For each object, check its collision.
	// 2. recursively bounce around.

	t_FVec3		normal;
	const float	hit = intersect_sphere(new_fvec3(0, 0, -1), 0.5f, &ray);

	(void) rt; // Unused for now, use later for oop designed hit detection.
	if (hit > 0.0f)
	{
		normal = sub_vec3(ray_at(&ray, hit), new_fvec3(0, 0, -1));
		normalize_fvec3(&normal);
		*out = new_fvec3((normal.x + 1) * 0.5, (normal.y + 1) * 0.5, (normal.z + 1) * 0.5);
		return (true);
	}
	return (false);
}
*/

/*
static t_Ray	ft_new_ray(t_FVec3 pos, t_FVec3 dir)
{
	return ((t_Ray){pos, dir});
}
*/

// Test every fucking object
static bool ft_intersect(t_rt *rt, t_Ray ray, t_Hit* outhit)
{
	size_t	i;

	i = 0;
	while (++i < rt->objects_size)
	{
		if (rt->objects[i].intersect(&rt->objects[i], &ray, outhit))
			return (true);
		i++;
	}
	return (false);
}

/*
		//target = add_vec3(outhit.point_at_t, outhit.normal);
		//return (mul_fvec3(ft_ray_color(rt, \
		//ft_new_ray(outhit.point_at_t, sub_vec3(target, outhit.point_at_t)), \
		//--depth), 0.5f));
*/

static t_FVec3	ft_ray_color(t_rt *rt, t_Ray ray, int32_t depth)
{
	float	t;
	t_FVec3	a;
	t_FVec3	b;
	//t_FVec3	target;
	t_Hit	outhit;

	(void) rt;
	(void) depth;

	// Draw object
	if (ft_intersect(rt, ray, &outhit))
	{
		printf("X: %f | Y: %f | Z: %f\n", outhit.normal.x, outhit.normal.y, outhit.normal.z);
		return (outhit.normal);
	}

	// Draw background
	normalize_fvec3(&ray.direction);
	t = 0.5f * (ray.direction.y + 1.0f);
	a = mul_fvec3(new_fvec3(1.0f, 1.0f, 1.0f), 1.0f - t);
	b = mul_fvec3(new_fvec3(0.5f, 0.7f, 1.0f), t);
	return (add_vec3(a, b));
}

static uint32_t	ft_linear_to_rgb(t_FVec3 linear)
{
	const int32_t	red = (int32_t)(linear.x * 255.0f);
	const int32_t	green = (int32_t)(linear.y * 255.0f);
	const int32_t	blue = (int32_t)(linear.z * 255.0f);

	return (red << 24 | green << 16 | blue << 8 | 255);
}

static t_Ray	ft_fire_ray(t_rt *rt, uint32_t x, uint32_t y)
{
	t_Camera *const	camera = ft_get_active_camera(rt);
	const float		u = (double)x / (rt->window_img->width - 1);
	const float		v = (double)y / (rt->window_img->height - 1);
	const t_FVec3	a = add_vec3(camera->top_left, \
						mul_fvec3(camera->horizontal, u));
	const t_FVec3	b = sub_vec3(mul_fvec3(camera->vertical, v), \
						camera->transform.pos);

	return ((t_Ray){camera->transform.pos, add_vec3(a, b)});
}

/**
 * Draws the frame by raytracing each pixel.
 * 
 * @param rt 
 */
void	ft_draw(t_rt *rt)
{
	uint32_t	x;
	uint32_t	y;
	t_Ray		ray;

	y = 0;
	while (y < rt->window_img->height)
	{
		x = 0;
		while (x < rt->window_img->width)
		{
			ray = ft_fire_ray(rt, x, y);
			mlx_put_pixel(rt->window_img, x, y, \
			ft_linear_to_rgb(ft_ray_color(rt, ray, MAX_DEPTH)));
			x++;
		}
		y++;
	}
}
