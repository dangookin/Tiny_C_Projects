#include <stdio.h>
#include <ctype.h>

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
			if( a<0 ) break;		/* check for invalid hex digit */
			ch = getchar();
			if( ch==EOF ) break;
			b = tohex(ch);
			if( b<0 ) break;		/* check for invalid hex digit */
			putchar( (a<<4)+b );
		}
		else		/* do a little more filtering here */
		{
			/* this statement is pulled from url_encoder.c */
			if( ch=='-' || ch=='.' || ch=='_' || ch=='*' )
				putchar(ch);
			else if(isalnum(ch))	/* include the ctype.h header file */
				putchar(ch);
			else
			{
				/* bail on illegal character */
				fprintf(stderr,"Invalid character\n");
				break;
			}
		}
	}

	return(0);
}
