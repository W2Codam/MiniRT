/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:21:17 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/25 17:43:32 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

//= Private =//

/*
static t_FVec3	ft_mult_mat_vec(t_FVec3 mat[3], t_FVec3 vec)
{
	const float	x = mat[0].x * vec.x + mat[0].y * vec.x + mat[0].z * vec.x;
	const float	y = mat[1].x * vec.y + mat[1].y * vec.y + mat[1].z * vec.y;
	const float	z = mat[2].x * vec.z + mat[2].y * vec.z + mat[2].z * vec.z;

	return (ft_new_fvec3(x, y, z));
}
*/

//= Public =//

/*
init

make matrix:
mat3x3 = {
	right	-> cross(fw, arb)
	up	
	fw	-> normal
}
*/

t_FVec3	ft_rotate_it(t_FVec3 mat[3], t_FVec3 vect)
{
	t_FVec3	res;

	res.x = mat[0].y * vect.x + mat[0].y * vect.x + mat[0].z * vect.x;
	res.y = mat[1].y * vect.y + mat[1].y * vect.y + mat[1].z * vect.y;
	res.z = mat[2].y * vect.z + mat[2].y * vect.z + mat[2].z * vect.z;

	return (res);
}

void	mmul3(t_FVec3 a[3], const t_FVec3 b[3], t_FVec3 out[3])
{
	int			i;
	int			j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			out[i].raw[j] \
				= a[i].raw[0] * b[0].raw[j]
				+ a[i].raw[1] * b[1].raw[j]
				+ a[i].raw[2] * b[2].raw[j];
			j++;
		}
		i++;
	}
}

t_FVec3	ft_rotate_vec(t_FVec3 cam[3], t_FVec3 vec, float angle, t_Axis axis)
{
	t_FVec3			temp[3];
	const float		theta = ft_to_rad(angle);
	const t_FVec3	matx[3] = {
		ft_new_fvec3(1, 0, 0),
		ft_new_fvec3(0, cos(theta), -sin(theta)),
		ft_new_fvec3(0, sin(theta), -cos(theta)),
	};
	const t_FVec3	maty[3] = {
		ft_new_fvec3(cos(theta), 0, sin(theta)),
		ft_new_fvec3(0, 1, 0),
		ft_new_fvec3(-sin(theta), 0, cos(theta)),
	};
	const t_FVec3	matz[3] = {
		ft_new_fvec3(cos(theta), -sin(theta), 0), // TODO: Minus ?
		ft_new_fvec3(sin(theta), cos(theta), 0),
		ft_new_fvec3(0, 0, 1),
	};

	if (axis == X)
	{
		mmul3(cam, matx, temp);
		return (ft_rotate_it(temp, vec));
	}
	else if (axis == Y)
	{
		mmul3(cam, maty, temp);
		return (ft_rotate_it(temp, vec));
	}
	else if (axis == Z)
	{
		mmul3(cam, matz, temp);
		return (ft_rotate_it(temp, vec));
	}
	return (ft_new_fvec3(0.0f, 0.0f, 0.0f));
}
