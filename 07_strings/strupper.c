#include <stdio.h>

void strupper(char *s)
{
	while(*s)
	{
		if( *s>='a' && *s<='z' )
		{
			*s &= 0xdf;
		}
		s++;
	}
}

int main()
{
	char string[] = "Random STRING sample 123@#$";

	printf("Original string: %s\n",string);
	strupper(string);
	printf("Uppercase string: %s\n",string);

	return(0);
}
