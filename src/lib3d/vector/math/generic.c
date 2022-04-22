/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generic.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 18:04:10 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/21 14:00:57 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

float	ft_len_fvec3(t_FVec3 vec)
{
	return (sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

float	ft_len_squared_fvec3(t_FVec3 vec)
{
	return ((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

void	ft_normalize_fvec3(t_FVec3 *vec)
{
	float		inv;
	const float	length = ft_len_fvec3(*vec);

	inv = 1.0f / length;
	vec->x *= inv;
	vec->y *= inv;
	vec->z *= inv;
}

float	ft_dot_fvec3(t_FVec3 left, t_FVec3 right)
{
	return (left.x * right.x + left.y * right.y + left.z * right.z);
}

bool	ft_equal_fvec3(t_FVec3 left, t_FVec3 right)
{
	return (left.x == right.x && left.y == right.y && left.z == right.z);
}
