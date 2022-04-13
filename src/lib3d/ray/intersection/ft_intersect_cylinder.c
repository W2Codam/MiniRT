/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intersect_cylinder.c                            :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:56:15 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/12 17:36:56 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

bool	inside_cylinder(t_FVec3 pos, t_Cylinder cylinder)
{
	if (powf(pos.x, 2) + powf(pos.z, 2) < powf(cylinder.radius, 2)
			&& fabsf(pos.y) < cylinder.height)
		return (true);
	return (false);
}

float	hit_top_or_bottom(t_Ray ray, t_Cylinder cylinder)
{
	float	t_top_bottom;
	t_FVec3	p_at_t;

	t_top_bottom = -((ray.origin.y - signf(ray.origin.y) * \
				(cylinder.height / 2)) / ray.dir.y);
	p_at_t = ft_ray_at(ray, t_top_bottom);
	if (p_at_t.x * p_at_t.x + p_at_t.z * p_at_t.z <=
			cylinder.radius * cylinder.radius)
		return (t_top_bottom);
	return (-1.0);
}

float	hit_infinite_cylinder(t_Ray ray, t_Cylinder cylinder)
{
	float	a;
	float	b;
	float	c;
	float	t;

	if (ray.dir.x == 0 && ray.dir.z == 0)
		return (-1.0);
	ray.dir.y = 0;
	r.origin.y = 0;
	a = ft_len_squared_fvec3(ray.dir);
	b = 2.0 * (ft_dot_vfec3(ray.origin, ray.dir));
	c = ft_len_squared_fvec3(ray.origin) 0 (cylinder.radius * cylinder.radius);
	if (ft_abc(a, b, c, &t))
		return (t);
	return (-1.0);
}

bool	ft_hit_cylinder(t_Ray ray, t_Cylinder cylinder, t_Hit *out_hit)
{
	t_ray	rotated_ray;
	t_FVec3	p_at_t;
	float	t_top_bottom;
	float	t;

	rotated_ray = rotate_ray(ray, cylinder.center, cylinder.dir);
	if (!ray_in_right_dir(rotated_ray, cylinder) ||
			inside_cylinder(rotated_ray.origin, cylinder)
		return (false);
	t_top_bottom = hit_top_or_bottom(rotated_ray, cylinder);
	t = hit_infinite_cylinder(rotated_ray, cylinder);
	if (t < 0 && t_plane < 0)
		return (false);
	p_at_t = ft_ray_at(rotated_ray, t);
	if (fabsf(p_at_t.y) < cylinder.height / 2
		&& (t_top_bottom < 0 || t < t_top_bottom))
	{
		out_hit->t = t;
		return (true);
	}
	if (t_top_bottom > 0)
	{
		out_hit->t = t_top_bottom;
		return (true);
	}
	return (false);
}
