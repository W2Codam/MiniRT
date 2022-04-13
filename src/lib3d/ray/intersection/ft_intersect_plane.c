/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intersect_plane.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:56:15 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/13 12:24:13 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

bool	ft_hit_plane(t_Ray *ray, t_Plane *plane, t_Hit *out_hit)
{
	const t_FVec3	oc = ft_sub_fvec3(plane->center, ray->origin);
	const float		a = ft_dot_fvec3(oc, plane->dir);
	const float		b = ft_dot_fvec3(ray->dir, plane->dir);
	float			distance;

	if (fabs(b) < FLT_MIN)
		return (false);
	distance = a / b;
	if (distance <= FLT_MIN)
		return (false);
	out_hit->distance = distance;
	return (true);
}
