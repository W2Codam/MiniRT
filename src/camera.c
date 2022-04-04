/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 19:30:49 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/04 17:24:51 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	ft_set_active_camera_pos(t_rt *rt, t_FVec3 pos)
{
	assert(rt->active_camera > 0 || rt->active_camera <= MAX_CAMERAS);
	rt->cameras[rt->active_camera].transform.pos = pos;
}

t_Camera	*ft_get_active_camera(t_rt *rt)
{
	assert(rt);
	return (&rt->cameras[rt->active_camera]);
}

void	ft_new_camera(t_rt *rt, t_Camera *out)
{
	(void)rt;
	float viewport_height = 2.0f;
    float viewport_width = (16.0f / 9.0f) * viewport_height;
    float focal_length = 1.0f;

	out->transform.pos = new_fvec3(0, 0, 0);
	out->horizontal = new_fvec3(viewport_width, 0, 0);
	out->vertical = new_fvec3(0, viewport_height, 0);
    //auto lower_left_corner = (origin - (horizontal / 2) - (vertical / 2) - vec3(0, 0, focal_length);
	out->top_left = sub_vec3(add_vec3(out->transform.pos, add_vec3(div_fvec3(out->horizontal, 2.0f), div_fvec3(out->vertical, 2.0f))), new_fvec3(0, 0, focal_length));
}
