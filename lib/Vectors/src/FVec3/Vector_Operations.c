/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector_Operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 11:31:18 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/28 11:49:53 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.h"

float	get_length_fvec3(t_FVec3 vec)
{
	return (sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

float	get_length_squared_fvec3(t_FVec3 vec)
{
	return ((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

void	normalize_fvec3(t_FVec3 *vec)
{
	float		inv;
	const float	length = get_length_fvec3(*vec);

	if (length == 0)
	{
		inv = 1.0f / length;
		vec->x *= inv;
		vec->y *= inv;
		vec->z *= inv;
	}
}

float	dot_fvec3(t_FVec3 a, t_FVec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_FVec3	cross_fvec3(t_FVec3 a, t_FVec3 b)
{
	return (new_fvec3(a.y * b.z - a.z * b.y, \
						a.z * b.x - a.x * b.z, \
						a.x * b.y - a.y * b.x));
}
