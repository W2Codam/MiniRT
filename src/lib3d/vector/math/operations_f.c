/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_f.c                                     :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 18:02:29 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/11 18:42:23 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_FVec3	ft_add_fvec3f(t_FVec3 left, float right)
{
	return \
	(ft_new_fvec3(left.x + right, left.y + right, left.z + right));
}

t_FVec3	ft_sub_fvec3f(t_FVec3 left, float right)
{
	return \
	(ft_new_fvec3(left.x - right, left.y - right, left.z - right));
}

t_FVec3	ft_mul_fvec3f(t_FVec3 left, float right)
{
	return \
	(ft_new_fvec3(left.x * right, left.y * right, left.z * right));
}

t_FVec3	ft_div_fvec3f(t_FVec3 left, float right)
{
	return \
	(ft_new_fvec3(left.x / right, left.y / right, left.z / right));
}
