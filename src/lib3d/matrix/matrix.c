/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:21:17 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/25 11:33:11 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

//= Private =//

static t_FVec3	ft_mult_mat_vec(t_FVec3 mat[3], t_FVec3 vec)
{
	const float	x = mat[0].x * vec.x + mat[0].y * vec.x + mat[0].z * vec.x;
	const float	y = mat[1].x * vec.y + mat[1].y * vec.y + mat[1].z * vec.y;
	const float	z = mat[2].x * vec.z + mat[2].y * vec.z + mat[2].z * vec.z;

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

static t_FVec3	ft_mult_row_mat(t_FVec3 row, const t_FVec3 mat[3])
{
	t_FVec3		result;

	result.x = row.x * mat[0].x + \
		row.y * mat[1].x + \
		row.z * mat[2].x;
	result.y = row.x * mat[0].y + \
		row.y * mat[1].y + \
		row.z * mat[2].y;
	result.z = row.x * mat[0].z + \
		row.y * mat[1].z + \
		row.z * mat[2].z;
	return (result);
}

static t_FVec3	ft_mult_mat_mat(t_FVec3 mat_a[3], const t_FVec3 mat_b[3], t_FVec3 vec)
{
	t_FVec3	result[3];

	result[0] = ft_mult_row_mat(mat_a[0], mat_b);
	result[1] = ft_mult_row_mat(mat_a[1], mat_b);
	result[2] = ft_mult_row_mat(mat_a[2], mat_b);
	return (ft_mult_mat_vec(result, vec));
}

t_FVec3	ft_rotate_vec(t_FVec3 cam_mat[3], t_FVec3 vec, float angle, t_Axis axis)
{
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
		return (ft_mult_mat_mat(cam_mat, matx, vec));
	else if (axis == Y)
		return (ft_mult_mat_mat(cam_mat, maty, vec));
	else if (axis == Z)
		return (ft_mult_mat_mat(cam_mat, matz, vec));
	return (ft_new_fvec3(0.0f, 0.0f, 0.0f));
}
