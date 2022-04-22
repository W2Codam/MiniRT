/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:21:17 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/21 17:16:42 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

//= Private =//

t_FVec3	ft_mult_mat_vec(const float mat[3][3], t_FVec3 vec)
{
	const float	x = mat[0][0] * vec.x + mat[0][1] * vec.x + mat[0][2] * vec.x;
	const float	y = mat[1][0] * vec.y + mat[1][1] * vec.y + mat[1][2] * vec.y;
	const float	z = mat[2][0] * vec.z + mat[2][1] * vec.z + mat[2][2] * vec.z;

	return (ft_new_fvec3(x, y, z));
}

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

void	ft_mat3_mult(t_FVec3 src, t_mat4 mult, )
{
	t_mat4		out;
	int			i;
	int			j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			out.data[i][j] \
				= src.data[i][0] * mult.data[0][j]
				+ src.data[i][1] * mult.data[1][j]
				+ src.data[i][2] * mult.data[2][j];
			j++;
		}
		i++;
	}
	return (out);
}

void	ft_mul_mat_mat(t_FVec3 mat_a[3], t_FVec3 mat_b[3], t_FVec3 *mat_out[3])
{
	
}

t_FVec3	ft_rotate_vec(t_FVec3 cam_mat[3], t_FVec3 vec, float angle, t_Axis axis)
{
	t_FVec3			rslt_mat[3];
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
		ft_new_fvec3(cos(theta), -sin(theta), 0),
		ft_new_fvec3(sin(theta), cos(theta), 0),
		ft_new_fvec3(0, 0, 1),
	};

	if (axis == X)
		return (ft_mult_mat_vec(matx * worldmatrix, vec));
		return (ft_mult_mat_vec(ft_mul_mat_mat(cam_mat, matx), vec));
	else if (axis == Y)
		return (ft_mult_mat_vec(maty * worldmatrix, vec));
	else if (axis == Z)
		return (ft_mult_mat_vec(matz * worldmatrix, vec));
	return (ft_new_fvec3(0.0f, 0.0f, 0.0f));
}
