#include <stdio.h>
#include <string.h>

int main()
{
	char a[5] = { '\0' };
	char b[5];

	if( strcmp(a,b)==0 )
		puts("Strings are the same");
	else
		puts("Strings are not the same");
	printf("Length: a=%lu b=%lu\n",strlen(a),strlen(b));
	printf("Storage: a=%zu b=%zu\n",sizeof(a),sizeof(b));

	return(0);
}
