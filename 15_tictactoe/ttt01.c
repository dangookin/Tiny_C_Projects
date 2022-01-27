#include <stdio.h>

void showgrid(int *g)
{
	const char bfwb[] = "\x1b[32;47m";
	const char bf[] = "\x1b[32m";
	const char xfwb[] = "\x1b[31;47m";
	const char xf[] = "\x1b[31m";
	const char ofwb[] = "\x1b[34;47m";
	const char of[] = "\x1b[34m";
	const char reset[] = "\x1b[0m";
	int x;

	for( x=0; x<9; x++ )
	{
		switch( *(g+x) )
		{
			case -1:
				if( x%2 )
					printf("%s O %s",ofwb,reset);
				else
					printf("%s O %s",of,reset);
				break;
			case 1:
				if( x%2 )
					printf("%s X %s",xfwb,reset);
				else
					printf("%s X %s",xf,reset);
				break;
			default:
				if( x%2 )
					printf("%s %d %s",bfwb,x+1,reset);
				else
					printf("%s %d %s",bf,x+1,reset);
		}
		if( (x+1)%3==0 )
			putchar('\n');
	}
	putchar('\n');
}

int main()
{
	int grid[] = {
		0, 0, 0,
		0, 0, 0,
		0, 0, 0
	};

	puts("Tic-Tac-Toe");

	showgrid(grid);

	return(0);
}
