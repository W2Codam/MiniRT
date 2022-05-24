/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intersect_cylinder.c                            :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:56:15 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/24 11:12:37 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"
#include <stdio.h>

static bool	inside_cylinder(t_FVec3 pos, t_Cylinder *cylinder)
{
	if (powf(pos.x, 2) + powf(pos.z, 2) < powf(cylinder->radius, 2) \
	&& fabsf(pos.y) < cylinder->height)
		return (true);
	return (false);
}

static float	hit_top_or_bottom(t_Ray *ray, t_Cylinder *cylinder)
{
	const float		t_top_bottom = -((ray->origin.y - ft_signf(ray->origin.y) \
	* (cylinder->height / 2)) / ray->dir.y);
	const t_FVec3	p_at_t = ft_ray_at(ray, t_top_bottom);

	if (p_at_t.x * p_at_t.x + p_at_t.z * p_at_t.z <= \
	cylinder->radius * cylinder->radius)
		return (t_top_bottom);
	return (-1.0);
}

static float	hit_infinite_cylinder(t_Ray ray, t_Cylinder *cylinder)
{
	float	a;
	float	b;
	float	c;
	float	t;
	float	disc;

	if (ray.dir.x == 0 && ray.dir.z == 0)
	{
		return (-1.0);
	}
	ray.dir.y = 0;
	ray.origin.y = 0;
	a = ft_len_squared_fvec3(ray.dir);
	b = 2.0 * (ft_dot_fvec3(ray.origin, ray.dir));
	c = ft_len_squared_fvec3(ray.origin) - \
	(cylinder->radius * cylinder->radius);
	disc = (b * b) - 4 * a * c;
	if (disc > 0)
	{
		t = (-b - sqrtf(disc)) / (2.0f * a);
		return (t);
	}
	return (-1.0f);
}

static bool	hit_cylinder_help(t_Ray ray, t_Cylinder *cylinder, t_Hit *out_hit)
{
	float	t_top_bottom;
	float	t;
	t_FVec3	p_at_t;

	t_top_bottom = hit_top_or_bottom(&ray, cylinder);
	t = hit_infinite_cylinder(ray, cylinder);
	if (t < 0 && t_top_bottom < 0)
		return (false);
	p_at_t = ft_ray_at(&ray, t);
	if (fabsf(p_at_t.y) < cylinder->height / 2
		&& (t_top_bottom < 0 || t < t_top_bottom))
	{
		out_hit->cy_side = true;
		out_hit->distance = t;
		return (true);
	}
	if (t_top_bottom > 0)
	{
		out_hit->distance = t_top_bottom;
		return (true);
	}
	return (false);
}

bool	ft_hit_cylinder(t_Ray *ray, t_Cylinder *cylinder, t_Hit *out_hit)
{
	t_Ray	rotated_ray;

	out_hit->distance = -1;
	out_hit->cy_side = false;
	rotated_ray = ft_rotate_ray(ray, cylinder->center, cylinder->dir);
	if (!ft_ray_in_right_dir(&rotated_ray, cylinder) || \
			inside_cylinder(rotated_ray.origin, cylinder))
		return (false);
	return (hit_cylinder_help(rotated_ray, cylinder, out_hit));
}
