/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 19:30:49 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/04 14:26:53 by lde-la-h      ########   odam.nl         */
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

void	ft_new_camera(t_rt *rt, t_Transform trans, float FOV, t_Camera *out)
{
	assert(out);

	(void)rt;
	out->fov = FOV;
	out->transform = trans;

	// TODO: Apply rotation matrix to lens
}