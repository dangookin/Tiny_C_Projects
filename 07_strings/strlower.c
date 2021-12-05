#include <stdio.h>

void strlower(char *s)
{
	while(*s)
	{
		if( *s>='A' && *s<='Z' )
		{
			*s += 32;
		}
		s++;
	}
}

int main()
{
	char string[] = "Random STRING sample 123@#$";

	printf("Original string: %s\n",string);
	strlower(string);
	printf("Uppercase string: %s\n",string);

	return(0);
}
