/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 19:20:35 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/13 14:54:36 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Private =//

static t_FVec3	hit_object(t_Ray ray, t_Hit hit)
{
	t_FVec3	normal;

	if (hit.object->type == SPHERE)
		normal = ft_normal_sphere(ray, hit);
	else if (hit.object->type == PLANE)
		normal = ft_normal_plane(ray, hit);
	else
		normal = ft_new_fvec3(0, 0, 0);
	//else if (hit.object.type == CYLINDER)
	//	normal = ft_normal_cylinder(ray, hit);
	return (ft_mul_fvec3f(ft_add_fvec3(normal, ft_new_fvec3(1, 1, 1)), 0.5f));
}

static t_FVec3	hit_nothing(t_Ray ray)
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

static t_Hit	ft_hittables(t_RT *rt, t_Ray ray)
{
	uint16_t	i;
	t_Hit		new_hit;
	t_Hit		closest_hit;
	bool		first_hit;

	i = 0;
	first_hit = true;
	while (i < rt->world.object_count)
	{
		rt->world.objects[i].intersects(&rt->world.objects[i], &ray, &new_hit);
		if (new_hit.distance > 0.0f)
		{
			if (first_hit)
			{
				closest_hit = new_hit;
				first_hit = false;
			}
			else if (new_hit.distance < closest_hit.distance)
				closest_hit = new_hit;
		i++;
		}
	}
	return (closest_hit);
}

static t_FVec3	ft_ray_color(t_RT *rt, t_Ray ray)
{
	t_Hit		hit;

	hit = ft_hittables(rt, ray);
	if (hit.distance > 0.0f)
		return (hit_object(ray, hit));
	else
		return (hit_nothing(ray));
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
			color = ft_to_rgba(ft_ray_color(rt, ray));
			mlx_put_pixel(rt->canvas, x, rt->canvas->height - y, color);
			x++;
		}
		y--;
	}
}
