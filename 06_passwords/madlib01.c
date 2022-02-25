#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *add_noun(void)
{
	const char *vocabulary[] = {
		"couch", "dog", "tree", "eyeball",
		"banana", "necklace", "house", "car",
		"computer", "mountain", "cup", "hair"
	};
	int r;

	r = rand() % (sizeof(vocabulary)/sizeof(char *));
	return( vocabulary[r] );
}

const char *add_verb(void)
{
	const char *vocabulary[] = {
		"run", "eat", "burp", "sneeze",
		"cut", "yodel", "cook", "slice"
	};
	int r;

	r = rand() % (sizeof(vocabulary)/sizeof(char *));
	return( vocabulary[r] );
}

const char *add_adjective(void)
{
	const char *vocabulary[] = {
		"loud", "big", "soft", "crunchy",
		"smelly", "great", "blue", "tiny",
		"ripe", "hairy"
	};
	int r;

	r = rand() % (sizeof(vocabulary)/sizeof(char *));
	return( vocabulary[r] );
}

int main()
{
	srand( (unsigned)time(NULL) );

	printf("Will you please take the %s %s ",
			add_adjective(),
			add_noun()
		  );
	printf("and %s the %s?\n",
			add_verb(),
			add_noun()
		  );

	return(0);
}
