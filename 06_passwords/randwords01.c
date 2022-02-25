#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define repeat(a) for(int x=0;x<a;x++)

const char *add_word(void)
{
	const char *vocabulary[] = {
		"orange", "grape", "apple", "banana",
		"coffee", "tea", "juice", "beverage",
		"happy", "grumpy", "bashful", "sleepy"
	};
	int r;

	r = rand() % (sizeof(vocabulary)/sizeof(char *));
	return( vocabulary[r] );
}

int main()
{
	srand( (unsigned)time(NULL) );

	repeat(3)
		printf("%s ", add_word() );
	putchar('\n');

	return(0);
}
