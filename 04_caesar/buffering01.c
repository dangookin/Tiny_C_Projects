#include <stdio.h>

int main()
{
	char buffer[BUFSIZ];
	int a,b;

	setbuf(stdout,buffer);

	printf("Type a letter:");
	a = getchar();
	printf("Type a letter:");
	b = getchar();
	
	printf("a='%c', b='%c'\n",a,b);

	return(0);
}
