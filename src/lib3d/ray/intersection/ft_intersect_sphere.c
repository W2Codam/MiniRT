/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intersect_sphere.c                              :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:56:15 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/26 11:31:08 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"
#include "stdio.h"

bool	ft_hit_sphere(t_Ray *ray, t_Sphere *sphere, t_Hit *out_hit)
{
	const t_FVec3	oc = ft_sub_fvec3(ray->origin, sphere->center);
	const float		a = ft_dot_fvec3(ray->dir, ray->dir);
	const float		b = 2.0f * ft_dot_fvec3(oc, ray->dir);
	const float		c = ft_dot_fvec3(oc, oc) - \
						(sphere->radius * sphere->radius);
	const float		disc = (b * b) - 4 * a * c;

	if (disc > 0)
	{
		out_hit->distance = (-b - sqrtf(disc)) / (2.0f * a);
		return (true);
	}
	out_hit->distance = 0.0f;
	return (false);
}
