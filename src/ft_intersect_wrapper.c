/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intersect_wrapper.c                             :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: W2Wizard <w2.wizzard@gmail.com>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 01:37:20 by W2Wizard      #+#    #+#                 */
/*   Updated: 2022/04/25 10:58:26 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

bool	ft_intersect_sp(t_Object *obj, t_Ray *ray, t_Hit *out_hit)
{
	if (ft_hit_sphere(ray, &obj->as_sphere, out_hit))
	{
		out_hit->object = obj;
		return (true);
	}
	out_hit->object = NULL;
	return (false);
}

bool	ft_intersect_cl(t_Object *obj, t_Ray *ray, t_Hit *out_hit)
{
	if (ft_hit_cylinder(ray, &obj->as_cylinder, out_hit))
	{
		out_hit->object = obj;
		return (true);
	}
	out_hit->object = NULL;
	return (false);
}

bool	ft_intersect_pl(t_Object *obj, t_Ray *ray, t_Hit *out_hit)
{
	if (ft_hit_plane(ray, &obj->as_plane, out_hit))
	{
		out_hit->object = obj;
		return (true);
	}
	out_hit->object = NULL;
	return (false);
}
