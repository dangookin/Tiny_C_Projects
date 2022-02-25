#include <stdio.h>
#include "mystring.h"

int main()
{
	char string[] = "the great american novel";

	strcaps(string);
	printf("%s\n",string);

	return(0);
}
