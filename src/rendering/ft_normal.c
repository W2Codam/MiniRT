/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_normal.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 11:09:22 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/24 11:16:31 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_FVec3	ft_cy_side_normal(t_FVec3 hit_pos, t_Cylinder cylinder)
{
	t_Ray	hitpoint_to_center;
	float	dist_to_cy_pl;
	t_FVec3	hitpoint_cy_pl;

	hitpoint_to_center = ft_new_ray(hit_pos, cylinder.dir);
	dist_to_cy_pl = ft_hit_plane_2(&hitpoint_to_center,
			cylinder.dir, cylinder.center);
	hitpoint_cy_pl = ft_ray_at(&hitpoint_to_center, dist_to_cy_pl);
	return (ft_normalize_fvec3_2(ft_sub_fvec3(\
					hitpoint_cy_pl, cylinder.center)));
}

t_FVec3	ft_plane_normal(t_FVec3 plane_dir, t_FVec3 ray_dir)
{
	float	side;

	side = ft_dot_fvec3(plane_dir, ray_dir);
	if (side > 0.)
		return ((ft_sub_fvec3(ft_new_fvec3(0, 0, 0),
					ft_normalize_fvec3_2(plane_dir))));
	return (ft_normalize_fvec3_2(plane_dir));
}

t_FVec3	ft_normal_cylinder(t_Ray ray, t_Hit hit)
{
	t_Cylinder	cylinder;

	cylinder = hit.object->as_cylinder;
	if (hit.cy_side)
		return (ft_cy_side_normal(ft_ray_at(&ray, hit.distance), cylinder));
	else
		return (ft_plane_normal(cylinder.dir, ray.dir));
}

t_FVec3	ft_normal_sphere(t_Ray ray, t_Hit hit)
{
	t_FVec3		normal;
	t_FVec3		point_at_t;
	t_Sphere	sphere;

	sphere = hit.object->as_sphere;
	point_at_t = ft_ray_at(&ray, hit.distance);
	normal = ft_normalize_fvec3_2(ft_sub_fvec3(point_at_t, sphere.center));
	if (hit.is_inside)
		return (ft_mul_fvec3f(normal, -1));
	return (normal);
}

t_FVec3	ft_normal_plane(t_Ray ray, t_Hit hit)
{
	return (ft_plane_normal(hit.object->as_plane.dir, ray.dir));
}
