/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_world.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 11:17:21 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/14 11:52:19 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Private =//

static t_Hit	ft_hittables(t_RT *rt, t_Ray ray)
{
	uint16_t	i;
	t_Hit		new_hit;
	t_Hit		closest_hit;
	bool		first_hit;

	i = 0;
	first_hit = true;
	closest_hit.distance = -1.0f;
	while (i < rt->world.object_count)
	{
		if (rt->world.objects[i].intersects(&rt->world.objects[i], &ray, &new_hit))
		{
			//printf("hit_distance: %f\n", new_hit.distance);
			if (new_hit.distance > 0.0f)
			{
				if (first_hit)
				{
					closest_hit = new_hit;
					first_hit = false;
				}
				else if (new_hit.distance < closest_hit.distance)
					closest_hit = new_hit;
			}
		}
		i++;
	}
	return (closest_hit);
}

/**
 * Returns the normal of the hit object.
 * 
 * TODO: Make func ptrs.
 * 
 * @param ray The ray.
 * @param hit The hit result.
 * @return The normal. 
 */
static t_FVec3	ft_hit_object(t_Ray ray, t_Hit hit)
{
	if (hit.object->type == SPHERE)
		return (ft_normal_sphere(ray, hit));
	else if (hit.object->type == PLANE)
		return (ft_normal_plane(ray, hit));
	return (ft_new_fvec3(0, 0, 0));
}

//= Public =//

bool	ft_ray_to_world(t_RT *rt, t_Ray ray, t_FVec3 *normal, t_Hit *hit_out)
{
	const t_Hit		hit = ft_hittables(rt, ray);

	if (hit.distance > 0.0f)
	{
		*hit_out = hit;
		*normal = ft_hit_object(ray, hit);
		return (true);
	}
	ft_bzero(hit_out, sizeof(t_Hit));
	*normal = ft_new_fvec3(0.0f, 0.0f, 0.0f);
	return (false);
}

