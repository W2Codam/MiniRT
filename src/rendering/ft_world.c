/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_world.c                                         :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 11:17:21 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/26 13:27:58 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

static void	ft_hit(t_Object *obj, t_Ray ray, t_Hit *cl_hit, bool *first_hit)
{
	t_Hit		new_hit;

	if (obj->intersects(obj, &ray, &new_hit))
	{
		if (new_hit.distance > 0.0f)
		{
			if (*first_hit)
			{
				*cl_hit = new_hit;
				*first_hit = false;
			}
			else if (new_hit.distance < cl_hit->distance)
				*cl_hit = new_hit;
		}
	}
	return ;
}

static t_Hit	ft_hittables(t_RT *rt, t_Ray ray)
{
	uint16_t	i;
	t_Hit		closest_hit;
	bool		first_hit;

	i = 0;
	first_hit = true;
	closest_hit.distance = -1.0f;
	while (i < rt->world.object_count)
	{
		ft_hit(&rt->world.objects[i], ray, &closest_hit, &first_hit);
		i++;
	}
	return (closest_hit);
}

static t_FVec3	ft_hit_object(t_Ray ray, t_Hit hit)
{
	if (hit.object->type == SPHERE)
		return (ft_normal_sphere(ray, hit));
	else if (hit.object->type == PLANE)
		return (ft_normal_plane(ray, hit));
	else if (hit.object->type == CYLINDER)
		return (ft_normal_cylinder(ray, hit));
	return (ft_new_fvec3(0, 0, 0));
}

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

t_Hit	ft_ray_intersect_any(t_RT *rt, t_Ray ray, float len)
{
	uint16_t	i;
	t_Hit		hit;

	i = 0;
	hit.distance = -1.0f;
	while (i < rt->world.object_count)
	{
		if (rt->world.objects[i].intersects(&rt->world.objects[i], &ray, &hit))
		{
			if (hit.distance < len)
				break ;
		}
		i++;
	}
	return (hit);
}
