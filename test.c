#include <stdio.h>
#include <string.h>
#include "CUnitTest.h"

int test1(void)
{
	printf("test1\n");
	return 0;
}

int test123(void)
{
	printf("test123\n");
	return 0;
}

int test124(void)
{
	CUnitTest tests[] =
	{
		cunit_test("test 1", test1),
		cunit_test("test 123", test123),
		cunit_test("test 124", NULL),
	};

	RunTests("test124", tests, sizeof(tests) / sizeof(CUnitTest));
	return 0;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	CUnitTest tests[] = 
	{
		cunit_test("test 1", test1),
		cunit_test("test 123", test123),
		cunit_test("test 124", NULL),
	};

	RunTests("main test", tests, sizeof(tests) / sizeof(CUnitTest));

	return ret;
}
