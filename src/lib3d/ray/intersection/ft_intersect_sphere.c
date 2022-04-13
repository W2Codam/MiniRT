/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intersect_sphere.c                              :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:56:15 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/13 11:19:30 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

bool	ft_hit_sphere(t_Ray ray, t_Sphere sphere, t_Object obj, t_Hit *out_hit)
{
	const t_FVec3	oc = sphere.center;
	const float		a = dot_fvec3(ray.dir, ray.dir);
	const float		b = 2.0f * dot_fvec3(oc, ray.dir);
	const float		c = dot_fvec3(oc, oc) - (sphere.radius * sphere.radius);
	float			distance;

	if (ft_abc(a, b, c, &distance))
	{
		out_hit->distance = distance;
		out_hit->object = obj;
		return (true);
	}
	else
		return (false);
}
