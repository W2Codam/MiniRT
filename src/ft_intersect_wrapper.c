/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intersect_wrapper.c                             :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: W2Wizard <w2.wizzard@gmail.com>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 01:37:20 by W2Wizard      #+#    #+#                 */
/*   Updated: 2022/04/13 11:18:46 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

bool	ft_intersect_sp(t_Object obj, t_Ray ray, t_Hit *out_hit)
{
	return (ft_hit_sphere(ray, obj.as_sphere, obj, out_hit));
}

bool	ft_intersect_cl(t_Object obj, t_Ray ray, t_Hit *out_hit)
{
	return (ft_hit_cylinder(ray, obj.as_cylinder, obj, out_hit));
}

bool	ft_intersect_pl(t_Object obj, t_Ray ray, t_Hit *out_hit)
{
	return (ft_hit_plane(ray, obj.as_plane, obj, out_hit));
}

bool	ft_intersect_tr(t_Object obj, t_Ray ray, t_Hit *out_hit)
{
	return (ft_hit_triangle(ray, obj.as_triangle, obj, out_hit));
}
