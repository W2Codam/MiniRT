/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 18:30:39 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/11 18:34:15 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_FVec3	ft_ray_at(t_Ray *ray, float distance)
{
	return (ft_add_fvec3(ray->origin, ft_mul_fvec3f(ray->direction, distance)));
}
