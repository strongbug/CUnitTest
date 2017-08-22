#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CUnitTest.h"

#define SELECT_RETURN	0
#define SELECT_INVALID	-1

int getSelect(char *input, int iDefault, int iMax)
{
	int i = 0;
	int bIsNum = 0;
	int length = 0;
	int iSel = 0;

	if (input == NULL)
	{
		return SELECT_INVALID;
	}

	//
	while (input[i] != '\n')
		i++;
	input[i] = '\0';

	//check num?
	length = strlen(input);
	if (length <= 0)
		return iDefault;

	for (i = 0; i < length; i++)
	{
		if (input[i] < '0' || input[i] > '9')
			break;
		iSel *= 10;
		iSel += input[i] - '0';
	}
	if (i == length) //number
	{
		if (iSel > iMax)
			return SELECT_INVALID;
		else
			return iSel;
	}

	if (input[0] == '0' || input[0] == 'r')
		return SELECT_RETURN;

	return iSel;
}

int RunTests(const char* title, CUnitTest *pCUnitTest, int count)
{
	int ret = 0;
	int i = 0;
	int iSel = 1;
	char input[260] = { 0 };
	char *in = NULL;

	if (pCUnitTest == NULL || count <= 0)
	{
		printf("CUnitTest null!\n");
		return ret;
	}

	while (1)
	{
		//print title
		if (title != NULL)
		{
			printf("\n");
			printf("%s:\n", title);
			printf("----\n");
		}

		for (i = 1; i <= count; i++)
		{
			if (i == iSel)
				printf("->%d | %s\n", i, pCUnitTest[i-1].name);
			else
				printf("  %d | %s\n", i, pCUnitTest[i-1].name);
			//printf("\n");
		}
		printf("Please select or [Return(0|r)] >");
		in = fgets(input, sizeof(input), stdin);
		if (in == NULL)
		{
			printf("Get select err!, try again!\n");
			continue;
		}
		iSel = getSelect(input, iSel, count);
		switch (iSel)
		{
		case SELECT_RETURN:
			return ret;
		case SELECT_INVALID:
			printf("Input err!, try again!\n\n");
			continue;
		default:
			if (pCUnitTest[iSel-1].function != NULL)
				ret = pCUnitTest[iSel-1].function();
			else
				printf("[%s]'s function is NULL!\n", pCUnitTest[iSel-1].name);
			break;
		}

	}

	return ret;
}
