/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 12:47:17 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/26 11:25:09 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

void	set_correct_angle(t_angle *new_angle)
{
	if (new_angle->angle < 0)
		new_angle->angle = -M_PI - new_angle->angle;
	else
		new_angle->angle = M_PI - new_angle->angle;
	return ;
}

t_angle	ft_get_angle_to(t_FVec3 dir, t_FVec3 desired_angle)
{
	t_FVec3	rot_obj;
	t_angle	new_angle;
	float	len_rot_obj;

	if (ft_equal_fvec3(dir, ft_mul_fvec3f(desired_angle, -1)))
	{
		new_angle.angle = M_PI;
		if (desired_angle.y == 0 && desired_angle.z == 0)
			new_angle.k = ft_normalize_fvec3_2(ft_cross_fvec3(\
						dir, ft_new_fvec3(0, 1, 0)));
		else
			new_angle.k = ft_normalize_fvec3_2(ft_cross_fvec3(\
						dir, ft_new_fvec3(1, 0, 0)));
	}
	else
	{
		rot_obj = ft_cross_fvec3(dir, desired_angle);
		len_rot_obj = ft_len_fvec3(rot_obj);
		new_angle.angle = asin(len_rot_obj);
		if (ft_dot_fvec3(dir, desired_angle) < 0)
			set_correct_angle(&new_angle);
		new_angle.k = ft_normalize_fvec3_2(rot_obj);
	}
	return (new_angle);
}
