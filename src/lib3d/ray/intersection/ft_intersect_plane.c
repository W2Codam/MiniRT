/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intersect_plane.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:56:15 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/17 13:17:31 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

float	ft_hit_plane_2(t_Ray *ray, t_FVec3 dir, t_FVec3 pos)
{
	const t_FVec3	oc = ft_sub_fvec3(pos, ray->origin);
	const float		a = ft_dot_fvec3(oc, dir);
	const float		b = ft_dot_fvec3(ray->dir, dir);

	return (a / b);
}

bool	ft_hit_plane(t_Ray *ray, t_Plane *plane, t_Hit *out_hit)
{
	const t_FVec3	oc = ft_sub_fvec3(plane->center, ray->origin);
	const float		a = ft_dot_fvec3(oc, plane->dir);
	const float		b = ft_dot_fvec3(ray->dir, plane->dir);
	float			distance;

	if (fabs(b) < 0.0001)
		return (false);
	distance = a / b;
	if (distance <= 0.0001)
		return (false);
	out_hit->distance = distance;
	return (true);
}
