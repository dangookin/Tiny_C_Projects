#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER 1
#define LOWER 6
#define NUM 1
#define SYM 2

void scramble(char p[])
{
	const int size = UPPER+LOWER+NUM+SYM+1;
	char key[size];
	int x,r;

	for( x=0; x<size; x++ )
		key[x] = '\0';

	x = 0;
	while(x<size-1)
	{
		r = rand() % (size-1);
		if( !key[r] )
		{
			key[r] = p[x];
			x++;
		}
	}

	for( x=0; x<size; x++ )
		p[x] = key[x];
}

char uppercase(void)
{
	return( rand() % 26 + 'A' );
}

char lowercase(void)
{
	char ch;

	ch = uppercase();
	return( ch |= 0x20 );
}

char number(void)
{
	return( rand() % 10 + '0' );
}

char symbol(void)
{
	char s[8] = "!@#$%*_-";
	int r;

	r = rand() % 8;
	return( s[r] );
}

int main()
{
	char password[ UPPER+LOWER+NUM+SYM+1 ];
	int x;

	srand( (unsigned)time(NULL) );

	x = 0;
	while( x<UPPER )
		password[x++] = uppercase();
	while( x<UPPER+LOWER )
		password[x++] = lowercase();
	while( x<UPPER+LOWER+NUM )
		password[x++] = number();
	while( x<UPPER+LOWER+NUM+SYM )
		password[x++] = symbol();
	password[x] = '\0';

	scramble(password);

	printf("%s\n",password);

	return(0);
}
