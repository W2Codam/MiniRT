/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intersect_plane.c                               :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:56:15 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/13 09:14:34 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

bool	ft_hit_plane(t_Ray ray, t_Plane plane, t_Hit *out_hit)
{
	const t_FVec3	oc = sub_vec3(plane.center, ray.origin);
	const float		a = dot_fvec3(oc, plane.dir);
	const float		b = dot_fvec3(ray.dir, plane.dir);
	float			distance;

	if (fabs(b) < FLT_MIN)
		return (false);
	else
	{
		t = a / b;
		if (t <= FLT_MIN)
			return (false);
	}
	out_hit->distance = distance;
	out_hit->as_plane = plane;
	return (true);
}
