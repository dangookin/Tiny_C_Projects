#include <stdio.h>
#include <string.h>

int main()
{
	struct str {
		char *string;
		unsigned long (*length)(const char *);
	};
	struct str str1;
	char s[] = "Heresy";

	str1.string = s;
	str1.length = &strlen;

	printf("The string '%s' is %lu characters long\n",
			str1.string,
			str1.length(str1.string)
		  );

	return(0);
}
