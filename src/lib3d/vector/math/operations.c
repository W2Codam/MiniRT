/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 18:02:22 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/13 12:30:27 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_FVec3	ft_add_fvec3(t_FVec3 left, t_FVec3 right)
{
	return \
	(ft_new_fvec3(left.x + right.x, left.y + right.y, left.z + right.z));
}

t_FVec3	ft_sub_fvec3(t_FVec3 left, t_FVec3 right)
{
	return \
	(ft_new_fvec3(left.x - right.x, left.y - right.y, left.z - right.z));
}

t_FVec3	ft_mul_fvec3(t_FVec3 left, t_FVec3 right)
{
	return \
	(ft_new_fvec3(left.x * right.x, left.y * right.y, left.z * right.z));
}

t_FVec3	ft_div_fvec3(t_FVec3 left, t_FVec3 right)
{
	return \
	(ft_new_fvec3(left.x / right.x, left.y / right.y, left.z / right.z));
}

t_FVec3	ft_cross_fvec3(t_FVec3 left, t_FVec3 right)
{
	const float	x = left.y * right.z - left.z * right.y;
	const float	y = left.z * right.x - left.x * right.z;
	const float	z = left.x * right.y - left.y * right.x;

	return (ft_new_fvec3(x, y, z));
}
