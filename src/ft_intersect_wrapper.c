/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intersect_wrapper.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: W2Wizard <w2.wizzard@gmail.com>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 01:37:20 by W2Wizard      #+#    #+#                 */
/*   Updated: 2022/05/24 16:21:26 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

bool	ft_intersect_sp(t_Object *obj, t_Ray *ray, t_Hit *out_hit, bool check)
{
	(void)check;
	if (ft_hit_sphere(ray, &obj->as_sphere, out_hit))
	{
		out_hit->object = obj;
		return (true);
	}
	out_hit->object = NULL;
	return (false);
}

bool	ft_intersect_cl(t_Object *obj, t_Ray *ray, t_Hit *out_hit, bool check)
{
	if (ft_hit_cylinder(ray, &obj->as_cylinder, out_hit, check))
	{
		out_hit->object = obj;
		return (true);
	}
	out_hit->object = NULL;
	return (false);
}

bool	ft_intersect_pl(t_Object *obj, t_Ray *ray, t_Hit *out_hit, bool check)
{
	(void)check;
	if (ft_hit_plane(ray, &obj->as_plane, out_hit))
	{
		out_hit->object = obj;
		return (true);
	}
	out_hit->object = NULL;
	return (false);
}
