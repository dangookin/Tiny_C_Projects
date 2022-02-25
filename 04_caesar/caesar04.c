#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int shift,ch;
	char a,b;

	if( argc < 3 )
	{
		shift = 13;
	}
	else
	{
		a = argv[2][0];
		b = argv[1][0];
		if( isalpha(a) && isalpha(b))
		{
			a = toupper(a);
			b = toupper(b);
			shift = a - b;
			if( shift<-25 || shift>25 )
				shift = 13;
		}
		else
			shift = 13;
	}

	while( (ch = getchar()) != EOF)
	{
		if( isupper(ch) )
		{
			ch+= shift;
			if( ch>'Z' ) ch-=26;
			if( ch<'A' ) ch+=26;
			putchar(ch);
		}
		else if( islower(ch) )
		{
			ch+= shift;
			if( ch>'z' ) ch-=26;
			if( ch<'a' ) ch+=26;
			putchar(ch);
		}
		else
		{
			putchar(ch);
		}
	}

	return(0);
}
