/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generic_2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 12:35:07 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/13 12:35:56 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_FVec3	ft_normalize_fvec3_2(t_FVec3 vec)
{
	t_FVec3		out;
	float		inv;
	const float	length = ft_len_fvec3(vec);

	out = vec;
	if (length == 0)
	{
		inv = 1.0f / length;
		out.x *= inv;
		out.y *= inv;
		out.z *= inv;
	}
	return (out);
}
