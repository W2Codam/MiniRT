/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 12:32:56 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/26 11:14:40 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_FVec3	ft_rotate(t_FVec3 vec, t_FVec3 k, float angle)
{
	t_FVec3	temp1;
	t_FVec3	temp2;
	t_FVec3	temp3;
	t_FVec3	result;

	if (angle == 0)
		return (vec);
	temp1 = ft_mul_fvec3f(vec, cosf(angle));
	temp2 = ft_mul_fvec3f(ft_cross_fvec3(k, vec), sinf(angle));
	temp3 = ft_mul_fvec3f(k, (ft_dot_fvec3(k, vec) * (1 - cosf(angle))));
	result = ft_add_fvec3(temp1, temp2);
	result = ft_add_fvec3(result, temp3);
	return (result);
}

bool	ft_abc(float a, float b, float c, float *distance)
{
	const float	d = b * b - 4 * a * c;

	if (d < 0)
	{
		*distance = -1;
		return (false);
	}
	*distance = ((-b - sqrt(d)) / (2.0 * a));
	return (true);
}

float	ft_signf(float a)
{
	if (a < 0)
		return (-1.0);
	return (1.0);
}

float	ft_clamp(float x, float min, float max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}
