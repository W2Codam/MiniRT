/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intersect_sphere.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:56:15 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/12 17:11:51 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

bool	ft_hit_sphere(t_Ray *ray, t_Sphere *sphere, t_Hit *out_hit)
{
	const t_FVec3	m = ft_sub_fvec3(ray->origin, sphere->center);
	const float		b = ft_dot_fvec3(m, ray->direction);
	const float		c = ft_dot_fvec3(m, m) - (sphere->radius * sphere->radius);
	const float		discriminant = b * b - c;
	float			distance;

	distance = 0;

	if ((c > 0.0f) && (b > 0.0f))
		return (out_hit->distance = distance, false);
	if (discriminant < 0.0f)
		return (out_hit->distance = distance, false);

	distance = -b - sqrtf(discriminant);

	if (distance < 0.0f)
		distance = 0.0f;

	out_hit->distance = distance;
	out_hit->location = ft_ray_at(ray, distance);
	return (true);
}
