/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 18:30:39 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/13 12:50:59 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

bool	ft_ray_in_right_dir(t_Ray *ray, t_Cylinder *cylinder)
{
	if (ray->origin.y > cylinder->height / 2 || \
	ray->origin.y < -(cylinder->height / 2))
	{
		if (ray->origin.y * ray->dir.y >= 0)
			return (false);
	}
	return (true);
}

t_FVec3	ft_ray_at(t_Ray *ray, float distance)
{
	return (ft_add_fvec3(ray->origin, ft_mul_fvec3f(ray->dir, distance)));
}

t_Ray	ft_rotate_ray(t_Ray *ray, t_FVec3 center, t_FVec3 dir)
{
	t_angle	angle;
	t_FVec3	rotated_dir;
	t_FVec3	rotated_origin;
	t_FVec3	rotated_center;
	t_Ray	rotated_ray;

	angle = ft_get_angle_to(dir, ft_new_fvec3(0, 1, 0));
	rotated_dir = ft_rotate(ray->dir, angle.k, angle.angle);
	rotated_origin = ft_rotate(ray->origin, angle.k, angle.angle);
	rotated_center = ft_rotate(center, angle.k, angle.angle);
	rotated_origin = ft_sub_fvec3(rotated_origin, rotated_center);
	rotated_ray.dir = rotated_dir;
	rotated_ray.origin = rotated_origin;
	return (rotated_ray);
}
