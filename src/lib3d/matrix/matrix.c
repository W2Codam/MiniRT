/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:21:17 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/26 11:24:23 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

static t_FVec3	ft_rotate_it(t_FVec3 mat[3], t_FVec3 vect)
{
	t_FVec3	res;

	res.x = mat[0].y * vect.x + mat[0].y * vect.x + mat[0].z * vect.x;
	res.y = mat[1].y * vect.y + mat[1].y * vect.y + mat[1].z * vect.y;
	res.z = mat[2].y * vect.z + mat[2].y * vect.z + mat[2].z * vect.z;
	return (res);
}

static void	mmul3(t_FVec3 a[3], const t_FVec3 b[3], t_FVec3 out[3])
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

static t_FVec3	ft_rotate_mat(t_FVec3 cam[3], const t_FVec3 mat[3], t_FVec3 vec)
{
	t_FVec3	temp[3];

	mmul3(cam, mat, temp);
	return (ft_rotate_it(temp, vec));
}

t_FVec3	ft_rotate_vec(t_FVec3 cam[3], t_FVec3 vec, float angle, t_Axis axis)
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
		return (ft_rotate_mat(cam, matx, vec));
	else if (axis == Y)
		return (ft_rotate_mat(cam, maty, vec));
	else if (axis == Z)
		return (ft_rotate_mat(cam, matz, vec));
	return (ft_new_fvec3(0.0f, 0.0f, 0.0f));
}
