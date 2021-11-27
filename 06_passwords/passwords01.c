#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *add_word(void)
{
	char *vocabulary[] = {
		"Orange", "Grape", "Apple", "Banana",
		"coffee", "tea", "juice", "beverage",
		"happY", "grumpY", "bashfuL", "sleepY"
	};
	int r;

	r = rand() % 12;
	return( vocabulary[r] );
}

char *number(void)
{
	static char n[2];

	n[0] = rand() % 10 + '0';
	n[1] = '\0';

	return(n);
}

char *symbol(void)
{
	char sym[8] = "!@#$%*_-";
	static char s[2];

	s[0] = sym[rand() % 8];
	s[1] = '\0';

	return( s );
}

int main()
{
	char password[32];

	srand( (unsigned)time(NULL) );

	password[0] = '\0';

	strcpy(password,add_word());
	strcat(password,number());
	strcat(password,add_word());
	strcat(password,symbol());
	strcat(password,add_word());

	printf("%s\n",password);

	return(0);
}
