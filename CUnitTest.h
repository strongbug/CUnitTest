/*
 * Copyright 2017 strongbug <strongbug@163.com>
 *
 * CUnitTest is a Test framwork for c, easy to view and select which UnitTest to run.
 * The project source code hosted in [GitHub](https://github.com/strongbug/CUnitTest). 
 */
#ifndef _CUNIT_TEST_
#define _CUNIT_TEST_	1

//test function
typedef int(*CUnitTestFunc)(void);


typedef struct CUnitTest {
	const char *name;
	CUnitTestFunc function;
}CUnitTest;

#define cunit_test(name, f)	{name, f}


int RunTests(const char* title, CUnitTest *pCUnitTest, int count);

#endif	//#ifndef _CUNIT_TEST_

