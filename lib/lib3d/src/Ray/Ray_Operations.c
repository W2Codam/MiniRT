/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ray_Operations.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 15:50:31 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/06 11:18:27 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_FVec3	ray_at(t_Ray *ray, float t)
{
	const t_FVec3	mul = mul_fvec3(ray->direction, t);

	return (add_vec3(ray->origin, mul));
}

//Source: Real-Time Collision Detection by Christer Ericson
//Reference: Page 177
float	intersect_sphere(t_FVec3 center, float radius, t_Ray *ray)
{
	const t_FVec3	oc = sub_vec3(ray->origin, center);
	const float		a = dot_fvec3(ray->direction, ray->direction);
	const float		b = 2.0f * dot_fvec3(oc, ray->direction);
	const float		c = dot_fvec3(oc, oc) - radius * radius;
	const float		discriminant = b * b - 4 * a * c;

	if (discriminant < 0.0f)
		return (-1.0f);
	return ((-b - sqrtf(discriminant)) / (2.0f * a));
}

//Source: Real-Time Collision Detection by Christer Ericson
//Reference: Page 175
bool	intersect_plane(t_FVec3 center, float radius, t_Ray *ray)
{
	(void) center;
	(void) radius;
	(void) ray;
	return (true);
}

bool	intersect_cyllinder(t_FVec3 center, float radius, t_Ray *ray)
{
	(void) center;
	(void) radius;
	(void) ray;
	return (true);
}

bool	intersect_triangle(t_FVec3 vertices[3], t_Ray *ray)
{
	(void) vertices;
	(void) ray;
	return (true);
}
