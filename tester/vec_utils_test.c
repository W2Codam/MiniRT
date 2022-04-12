#include "Ctest.h"
#include "MiniRT.h"
#include <stdio.h>

t_VFec3	expected;
t_VFec3	result;
t_VFec3	origin;
t_RT	rt;

static int32_t	test_vec(float intensity, t_FVec3 color)
{
	return (true);
}

static int32_t	test_camera(int i, t_FVec3 pos, t_FVec3 rot, float fov)
{
	TEST_ASSERT(rt.cameras[i].transform.pos.x != pos.x);
	TEST_ASSERT(rt.cameras[i].transform.pos.y != pos.y);
	TEST_ASSERT(rt.cameras[i].transform.pos.z != pos.z);
	TEST_ASSERT(rt.cameras[i].transform.rot.x != rot.x);
	TEST_ASSERT(rt.cameras[i].transform.rot.y != rot.y);
	TEST_ASSERT(rt.cameras[i].transform.rot.z != rot.z);
	TEST_ASSERT(rt.cameras[i].fov == fov);
	return (true);
}

TEST_DECLARE(llc)
{
	result = ft_make_llc(rt->world->cameras[0]);
	expected = ft_new_fvec3();
	TEST_ASSERT(
	return (test_ambient(0.2, new_fvec3(255, 255, 255)));
}

TEST_DECLARE(llc)
{

}

int	main(void)
{
	ft_new_camera(ft_get_active_camera(rt), ft_new_fvec3(0, 0, 0), 1);
	TEST_RUN(UNIT_llc, false);
	TEST_RUN(UNIT_dot, false);
	return (EXIT_SUCCESS);
}
