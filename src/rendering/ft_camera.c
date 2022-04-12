/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 19:12:52 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/12 00:47:53 by W2Wizard      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Private =//

// https://bit.ly/3JsgvP3
// Generate the lower left corner of the viewport.
static t_FVec3	ft_make_llc(t_Camera *camera)
{
	t_FVec3	a;
	t_FVec3	b;
	t_FVec3	c;

	c = ft_new_fvec3(0, 0, camera->fov);
	a = ft_sub_fvec3(camera->position, ft_div_fvec3f(camera->horizontal, 2.0f));
	b = ft_sub_fvec3(a, ft_div_fvec3f(camera->vertical, 2.0f));
	return (ft_sub_fvec3(b, c));
}

//= Public =//

t_Camera	*ft_get_active_camera(t_RT *rt)
{
	return (&rt->world.cameras[rt->camera_index]);
}

void	ft_new_camera(t_Camera *camera, t_FVec3 pos, float fov)
{
	const float		aspect_ratio = (16.0f / 9.0f);
	const float		viewport_h = 2.0f;
	const float		viewport_w = aspect_ratio * viewport_h;

	camera->fov = fov;
	camera->position = pos;
	camera->horizontal = ft_new_fvec3(viewport_w, 0, 0);
	camera->vertical = ft_new_fvec3(0, viewport_h, 0);
	camera->llc = ft_make_llc(camera);
}
