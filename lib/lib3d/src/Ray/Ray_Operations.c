/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ray_Operations.c                                   :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 15:50:31 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/11 11:20:52 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"
#include <float.h>
#include <math.h>

// NOTE: PROTO -> bool (name)(Object Self, Ray* Ray, struct HIT* out)

t_FVec3	ray_at(t_Ray *ray, float t)
{
	t_SphereObject* this = (CAST)Self;
	const t_FVec3	mul = mul_fvec3(ray->direction, t);

	return (add_vec3(ray->origin, mul));
}

//Source: Real-Time Collision Detection by Christer Ericson
//Reference: Page 177
bool	intersect_sphere(t_EntityObject object, t_Ray *ray, t_Hit *hit);
{
	const t_FVec3	oc;
	const float		a;
	const float		b;
	const float		radius;
	const float		c;
	const float		discriminant;

	oc = sub_vec3(ray->origin, object->base->transform->pos);
	a = dot_fvec3(ray->direction, ray->direction);
	b = 2.0f * dot_fvec3(oc, ray->direction);
	radius = object->diameter / 2;
	c = dot_fvec3(oc, oc) - (radius * radius);
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0.0f)
		return (-1.0f);
	else
	{
		result_1 = (-b - sqrt(discriminant)) / (2.0 * a);
		result_2 = (-b + sqrt(discriminant)) / (2.0 * a);
		if (result_2 < result_1)
			return (-1.0f);
	}
	return (result_1);
}

//Source: Real-Time Collision Detection by Christer Ericson
//Reference: Page 175
bool	intersect_plane(t_EntityObject object, t_Ray *ray, t_Hit *hit)
{
	const t_FVec3	oc;
	const float		a;
	const float		b;
	const float		t;

	oc = sub_vec3(object->base->transform->pos, ray->origin);
	a = dot_fvec3(oc, object->base->transform->rot);
	b = dot_fvec3(ray->direction, object->base->transform->rot);
	if (fabs(b) < FLT_MIN)
		return (-1.0f);
	else
	{
		t = a / b;
		if (t <= FLT_MIN)
			return (t);
		else
			return (-1.0f);
	}
}

bool	intersect_cylinder(t_FVec3 center, float radius, t_Ray *ray)
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
