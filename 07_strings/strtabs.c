#include <stdio.h>

void strtabs(const char *s, int tab)
{
	int column,x,spaces;

	column = 0;
	while(*s)
	{
		if( *s == '\t')
		{
			spaces = tab - (column % tab);
			for( x=0; x<spaces; x++ )
				putchar(' ');
			column += spaces;
		}
		else
		{
			putchar(*s);
			if( *s=='\n' )
				column = 0;
			else
				column++;
		}
		s++;
	}
}

/* calculate and display a tab */
int main()
{
	const char *text[3] = {
	  "Hello\tHi\tHowdy\n",
	  "\tLa\tLa\n",
	  "Constantinople\tConstantinople\n"
	};
	int x,y;

	for(y=4;y<32;y*=2)
	{
		printf("Tab width: %d\n",y);
		for(x=0;x<3;x++)
		{
			strtabs(text[x],y);
		}
	}

	return(0);
}
