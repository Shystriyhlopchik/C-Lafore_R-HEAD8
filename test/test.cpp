// crt_strcpy_s.c
// Compile by using: cl /W4 crt_strcpy_s.c
// This program uses strcpy_s and strcat_s
// to build a phrase.

#include "stdafx.h"
#include <string.h>     // for strcpy_s, strcat_s
#include <stdlib.h>     // for _countof
#include <stdio.h>      // for printf
#include <errno.h>      // for return values
//#include <iostream>


using namespace std;

int main()
{
	char string[80];

	strcpy_s(string, _countof(string), "Hello world from ");
	strcat_s(string, _countof(string), "strcpy_s ");
	strcat_s(string, _countof(string), "and ");
	strcat_s(string, _countof(string), "strcat_s!");

	printf("String = %s\n", string);
	system("pause");
    return 0;
}
