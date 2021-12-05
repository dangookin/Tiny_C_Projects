#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { FALSE, TRUE };

struct string {
	char *value;
	int length;
};

int string_create(struct string *s, char *v)
{
	if( s==NULL )
		return(FALSE);

	s->length = strlen(v);

	s->value = malloc( sizeof(char) * s->length +1 );
	if( s->value==NULL )
		return(FALSE);

	strcpy(s->value,v);

	return(TRUE);
}

void string_destroy(struct string *s)
{
	free(s->value);
	s->value = NULL;
	s->length = 0;
}

int main()
{
	struct string str1;

	string_create(&str1,"I am not a string object");

	printf("The string '%s' is %d charcters long\n",
			str1.value,
			str1.length
		  );

	string_destroy(&str1);

	return(0);
}
