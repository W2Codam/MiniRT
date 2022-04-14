/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_normal.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 11:09:22 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/14 11:10:41 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Public =//

t_FVec3	ft_normal_sphere(t_Ray ray, t_Hit hit)
{
	const t_Sphere	sphere = hit.object->as_sphere;
	const t_FVec3	point_at_t = ft_ray_at(&ray, hit.distance);

	return (ft_normalize_fvec3_2(ft_sub_fvec3(point_at_t, sphere.center)));
}

t_FVec3 ft_normal_plane(t_Ray ray, t_Hit hit)
{
	const t_Plane	plane = hit.object->as_plane;
	const float		side = ft_dot_fvec3(plane.dir, ray.dir);

	if (side > 0.0f)
		return (ft_sub_fvec3(ft_new_fvec3(0, 0, 0), ft_normalize_fvec3_2(plane.dir)));
	return(ft_normalize_fvec3_2(plane.dir)); 
}

