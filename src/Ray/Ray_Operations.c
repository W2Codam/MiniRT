/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ray_Operations.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 15:50:31 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/11 13:50:57 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// NOTE: PROTO -> bool (name)(Object Self, Ray* Ray, struct HIT* out)

//t_FVec3	ray_at(t_Ray *ray, float t)
//{
//	t_SphereObject* this = (CAST)Self;
//	const t_FVec3	mul = mul_fvec3(ray->direction, t);
//
//	return (add_vec3(ray->origin, mul));
//}

//Source: Real-Time Collision Detection by Christer Ericson
//Reference: Page 177
bool	intersect_sphere(t_EntityObject *object, t_Ray *ray, t_Hit *hit)
{
	t_FVec3	oc;
	float		a;
	float		b;
	float		radius;
	float		c;
	float		discriminant;
	float		result_1;
	float		result_2;

	oc = sub_vec3(ray->origin, object->entity_sphere.base.transform.pos);
	a = dot_fvec3(ray->direction, ray->direction);
	b = 2.0f * dot_fvec3(oc, ray->direction);
	radius = object->entity_sphere.diameter / 2;
	c = dot_fvec3(oc, oc) - (radius * radius);
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0.0f)
		return (false);
	else
	{
		result_1 = (-b - sqrt(discriminant)) / (2.0 * a);
		result_2 = (-b + sqrt(discriminant)) / (2.0 * a);
		if (result_2 < result_1)
			return (false);
	}
	hit->t = result_1;
	return (true);
}

//Source: Real-Time Collision Detection by Christer Ericson
//Reference: Page 175
bool	intersect_plane(t_EntityObject *object, t_Ray *ray, t_Hit *hit)
{
	t_FVec3	oc;
	float		a;
	float		b;
	float		t;

	oc = sub_vec3(object->entity_plane.base.transform.pos, ray->origin);
	a = dot_fvec3(oc, object->entity_plane.base.transform.rot);
	b = dot_fvec3(ray->direction, object->entity_plane.base.transform.rot);
	if (fabs(b) < FLT_MIN)
		return (false);
	else
	{
		t = a / b;
		if (t <= FLT_MIN)
			return (false);
	}
	hit->t = t;
	return (true);
}

bool	intersect_cylinder(t_EntityObject *object, t_Ray *ray, t_Hit *hit)
{
	(void)object;
	(void)ray;
	(void)hit;
	return (true);
}

bool	intersect_triangle(t_EntityObject *object, t_Ray *ray, t_Hit *hit)
{
	(void)object;
	(void)ray;
	(void)hit;
	return (true);
}
