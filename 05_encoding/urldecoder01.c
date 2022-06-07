#include <stdio.h>

int tohex(int c)
{
	if( c>='0' && c<='9' )
		return(c-'0');
	if( c>='A' && c<='F' )
		return(c-'A'+0xA);
	if( c>='a' && c<='f' )
		return(c-'a'+0xA);
	return(-1);
}

int main()
{
	int ch,a,b;

	while( (ch=getchar()) != EOF )
	{
		if( ch=='%' )
		{
			ch = getchar();
			if( ch==EOF ) break;
			a = tohex(ch);
			ch = getchar();
			if( ch==EOF ) break;
			b = tohex(ch);
			putchar( (a<<4)+b );
		}
		else
			putchar(ch);
	}

	return(0);
}
