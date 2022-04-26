/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_camera.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 19:12:52 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/26 10:46:45 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Public =//

t_Camera    *ft_get_active_camera(t_RT *rt)
{
    return (&rt->world.cameras[rt->camera_index]);
}

void   		ft_update_camera(t_Camera *camera, t_FVec3 pos, t_FVec3 dir[3], float fov)
{
	camera->position = pos;
	camera->fov = fov;
}
