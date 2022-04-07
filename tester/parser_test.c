#include "Ctest.h"
#include "MiniRT.h"

t_rt	rt;

static void	test_ambient(float intensity, t_FVec3 color)
{
	TEST_ASSERT(rt.ambient.intensity == intensity);
	TEST_ASSERT(rt.ambient.color.x == color.x);
	TEST_ASSERT(rt.ambient.color.y == color.y);
	TEST_ASSERT(rt.ambient.color.z == color.z);
	TEST_ASSERT(rt.ambient.active == true);
	return ;
}

static void	test_camera(int i, t_FVec3 pos, t_FVec3 rot, float fov)
{
	TEST_ASSERT(rt.cameras[i].transform.pos.x == pos.x);
	TEST_ASSERT(rt.cameras[i].transform.pos.y == pos.y);
	TEST_ASSERT(rt.cameras[i].transform.pos.z == pos.z);
	TEST_ASSERT(rt.cameras[i].transform.rot.x == rot.x);
	TEST_ASSERT(rt.cameras[i].transform.rot.y == rot.y);
	TEST_ASSERT(rt.cameras[i].transform.rot.z == rot.z);
	TEST_ASSERT(rt.cameras[i].fov == fov);
	return ;
}

static void	test_light(int i, t_FVec3 pos, t_FVec3 rot, float intensity, t_FVec3 color)
{
	TEST_ASSERT(rt.lights[i].transform.pos.x == pos.x);
	TEST_ASSERT(rt.lights[i].transform.pos.y == pos.y);
	TEST_ASSERT(rt.lights[i].transform.pos.z == pos.z);
	TEST_ASSERT(rt.lights[i].transform.rot.x == rot.x);
	TEST_ASSERT(rt.lights[i].transform.rot.y == rot.y);
	TEST_ASSERT(rt.lights[i].transform.rot.z == rot.z);
	TEST_ASSERT(rt.lights[i].intensity == intensity);
	TEST_ASSERT(rt.lights[i].color.x == color.x);
	TEST_ASSERT(rt.lights[i].color.y == color.y);
	TEST_ASSERT(rt.lights[i].color.z == color.z);
	return ;
}

static void	test_plane(int i, t_FVec3 pos, t_FVec3 rot, t_FVec3 color)
{
	TEST_ASSERT(rt.objects[i].entity_plane.base.transform.pos.x == pos.x);
	TEST_ASSERT(rt.objects[i].entity_plane.base.transform.pos.y == pos.y);
	TEST_ASSERT(rt.objects[i].entity_plane.base.transform.pos.z == pos.z);
	TEST_ASSERT(rt.objects[i].entity_plane.base.transform.rot.x == rot.x);
	TEST_ASSERT(rt.objects[i].entity_plane.base.transform.rot.y == rot.y);
	TEST_ASSERT(rt.objects[i].entity_plane.base.transform.rot.z == rot.z);
	TEST_ASSERT(rt.objects[i].entity_plane.base.color.x == color.x);
	TEST_ASSERT(rt.objects[i].entity_plane.base.color.y == color.y);
	TEST_ASSERT(rt.objects[i].entity_plane.base.color.z == color.z);
	return ;
}

static void	test_sphere(int i, t_FVec3 pos, float diameter, t_FVec3 color)
{
	TEST_ASSERT(rt.objects[i].entity_sphere.base.transform.pos.x == pos.x);
	TEST_ASSERT(rt.objects[i].entity_sphere.base.transform.pos.y == pos.y);
	TEST_ASSERT(rt.objects[i].entity_sphere.base.transform.pos.z == pos.z);
	TEST_ASSERT(rt.objects[i].entity_sphere.base.color.x == color.x);
	TEST_ASSERT(rt.objects[i].entity_sphere.base.color.y == color.y);
	TEST_ASSERT(rt.objects[i].entity_sphere.base.color.z == color.z);
	TEST_ASSERT(rt.objects[i].entity_sphere.diameter == diameter);	
	return ;
}

static void	test_cylinder(int i, t_FVec3 pos, t_FVec3 rot, float diameter, float height, t_FVec3 color)
{
	TEST_ASSERT(rt.objects[i].entity_cylinder.base.transform.pos.x == pos.x);
	TEST_ASSERT(rt.objects[i].entity_cylinder.base.transform.pos.y == pos.y);
	TEST_ASSERT(rt.objects[i].entity_cylinder.base.transform.pos.z == pos.z);
	TEST_ASSERT(rt.objects[i].entity_cylinder.base.transform.rot.x == rot.x);
	TEST_ASSERT(rt.objects[i].entity_cylinder.base.transform.rot.y == rot.y);
	TEST_ASSERT(rt.objects[i].entity_cylinder.base.transform.rot.z == rot.z);
	TEST_ASSERT(rt.objects[i].entity_cylinder.base.color.x == color.x);
	TEST_ASSERT(rt.objects[i].entity_cylinder.base.color.y == color.y);
	TEST_ASSERT(rt.objects[i].entity_cylinder.base.color.z == color.z);
	TEST_ASSERT(rt.objects[i].entity_cylinder.diameter == diameter);	
	TEST_ASSERT(rt.objects[i].entity_cylinder.height == height);	
	return ;
}

static void	test_triangle(int i, t_FVec3 vert1, t_FVec3 vert2, t_FVec3 vert3, t_FVec3 color)
{
	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[0].x == vert1.x);
	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[0].y == vert1.y);
	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[0].z == vert1.z);
	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[1].x == vert2.x);
	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[1].y == vert2.y);
	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[1].z == vert2.z);
	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[2].x == vert3.x);
	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[2].y == vert3.y);
	TEST_ASSERT(rt.objects[i].entity_triangle.vertices[2].z == vert3.z);
	TEST_ASSERT(rt.objects[i].entity_triangle.color.x == color.x);
	TEST_ASSERT(rt.objects[i].entity_triangle.color.y == color.y);
	TEST_ASSERT(rt.objects[i].entity_triangle.color.z == color.z);
	return ;
}

TEST_DECLARE(test)
{
	// Test ambient; Only one per map, otherwise init_entities will fail
	// 1st param: intensity
	// 2nd param: color
	test_ambient(0.2, new_fvec3(255, 255, 255));

	// Test camera(s)
	// 1st param: ith camera, starting at 0
	// 2nd param: position
	// 3rd param: rotation
	// 4th param: field of view
	test_camera(0, new_fvec3(-50, 0, 20), new_fvec3(0, 0, 0), 70); 

	// Test light(s)
	// 1st param: ith light, starting at 0
	// 2nd param: position
	// 3rd param: rotation
	// 4th param: intensity
	// 5th param: color
	test_light(0, new_fvec3(-40, 0, 30), new_fvec3(0, 0, 0), 0.7, new_fvec3(255, 255, 255));

	// Test object(s); Plane, Sphere, Cylinder
	// 1st param: ith object, starting at 0
	// 2nd param: position
	// 3rd param: rotation
	// 4th param: color
	// 5th param: diameter (only for sphere & cylinder)
	// 6th param: height (only for cylinder)
	test_plane(0, new_fvec3(0, 0, 0), new_fvec3(0, 1, 0), new_fvec3(255, 0, 225));
	test_sphere(1, new_fvec3(0, 0, 20), 20, new_fvec3(255, 0, 0));
	test_cylinder(2, new_fvec3(50, 0, 20.6), new_fvec3(0, 0, 1), 14.2, 21.42, new_fvec3(10, 0, 255)); 
	test_plane(3, new_fvec3(0, 0, 0), new_fvec3(0, 0, 1), new_fvec3(255, 0, 225));
	test_sphere(4, new_fvec3(0, 0, 20), 20, new_fvec3(255, 0, 0));
	test_cylinder(6, new_fvec3(50, 0, 20.6), new_fvec3(0, 0, 1), 14.2, 21.42, new_fvec3(10, 0, 255));

	// Test object(s); Triangle
	// 1st param: ith object, starting at 0
	// 2nd param: vertice 1
	// 3rd param: vertice 2
	// 4th param: vertice 3
	// 5th param: color
	test_triangle(0, new_fvec3(0.3, 2, 4), new_fvec3(3, 2, -2), new_fvec3(-4, 4, 0), new_fvec3(255, 244, 233));
	return (1);
}

int	main(int argc, char **argv)
{
	(void)argc;
	if (!argv[1])
	{
		printf("Missing input map");
		return (EXIT_FAILURE);
	}
	init_entities(&rt, argv[1]);
	TEST_RUN(UNIT_test, true);

}
