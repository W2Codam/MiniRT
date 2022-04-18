/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intersect_sphere.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:56:15 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/14 11:02:29 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"
#include "stdio.h"

bool	ft_hit_sphere(t_Ray *ray, t_Sphere *sphere, t_Hit *out_hit)
{
	const t_FVec3	oc = ft_sub_fvec3(ray->origin, sphere->center);
	const float		a = ft_dot_fvec3(ray->dir, ray->dir);
	const float		b = 2.0f * ft_dot_fvec3(oc, ray->dir);
	const float		c = ft_dot_fvec3(oc, oc) - \
						(sphere->radius * sphere->radius);
	const float		disc = (b * b) - 4 * a * c;

	//printf("a: %f, b: %f, c: %f, disc: %f\n", a, b, c, disc);
	if (disc > 0)
	{
		out_hit->distance = (-b - sqrtf(disc)) / (2.0f * a);
		//printf("distance: %f\n", out_hit->distance);
		return (true);
	}
	out_hit->distance = 0.0f;
	//printf("distance: %f\n", out_hit->distance);
	return (false);
}
