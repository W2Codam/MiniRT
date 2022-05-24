/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generic_2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 12:35:07 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/21 14:08:44 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_FVec3	ft_normalize_fvec3_2(t_FVec3 vec)
{
	t_FVec3		out;
	float		inv;
	const float	length = ft_len_fvec3(vec);

	out = vec;
	inv = 1.0f / length;
	out.x *= inv;
	out.y *= inv;
	out.z *= inv;
	return (out);
}

float	ft_distance(t_FVec3 p1, t_FVec3 p2)
{
	return \
	(sqrtf(powf(p2.x - p1.x, 2) + powf(p2.y - p1.y, 2) + powf(p2.z - p1.z, 2)));
}
