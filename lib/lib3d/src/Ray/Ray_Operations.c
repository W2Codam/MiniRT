/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ray_Operations.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 15:50:31 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/30 16:07:33 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

//Source: Real-Time Collision Detection by Christer Ericson
//Reference: Page 177
bool	intersect_sphere(t_FVec3 center, float radius, t_Ray *ray)
{
	const t_FVec3	oc = sub_fvec3(ray->origin, center);
	const float		a = dot_fvec3(ray->direction, ray->direction);
	const float		b = 2.0f * dot_fvec3(oc, ray->direction);
	const float		c = dot_fvec3(oc, oc) - radius * radius;

	return ((b * b) - (4 * a * c) > 0);
}

//Source: Real-Time Collision Detection by Christer Ericson
//Reference: Page 175
bool	intersect_plane(t_FVec3 center, float radius, t_Ray* ray)
{
	return (true);
/*
Vector3.Dot(ref plane.Normal, ref ray.Direction, out float direction);
if (Mathf.IsZero(direction))
{
    distance = 0f;
    return false;
}
Vector3.Dot(ref plane.Normal, ref ray.Position, out float position);
distance = (-plane.D - position) / direction;
if (distance < 0f)
{
    distance = 0f;
    return false;
}
return true;
*/
}

bool	intersect_cyllinder(t_FVec3 center, float radius, t_Ray* ray)
{
	return (true);
}
