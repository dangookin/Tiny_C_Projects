#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TL *(g+0)
#define TC *(g+1)
#define TR *(g+2)
#define ML *(g+3)
#define MC *(g+4)
#define MR *(g+5)
#define BL *(g+6)
#define BC *(g+7)
#define BR *(g+8)

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

int winner(int *g)
{
	int slice[8];
	int x;

	slice[0] = TL + ML + BL;
	slice[1] = TC + MC + BC;
	slice[2] = TR + MR + BR;
	slice[3] = TL + TC + TR;
	slice[4] = ML + MC + MR;
	slice[5] = BL + BC + BR;
	slice[6] = TL + MC + BR;
	slice[7] = TR + MC + BL;

	for( x=0; x<8; x++ )
	{
		if( slice[x]==-3 )
		{
			showgrid(g);
			puts(">>> O wins!");
			return(1);
		}
		if( slice[x]==3 )
		{
			showgrid(g);
			puts(">>> X wins!");
			return(1);
		}
	}

	return(0);
}

int prompt(int p, int *g)
{
	int square;

	printf("%c's turn: Pick a square, 0 to quit: ",
			p%2 ? 'O' : 'X'
		  );
	scanf("%d",&square);
	
	if( square<0 || square>9 )
	{
		puts("Value out of range");
		return(-1);
	}
	
	if( square==0 )
		return(square);

	if( *(g+square-1) != 0 )
	{
		printf("Square %d is occupied, try again\n",
					square
				  );
		return(-1);
	}
	
	return(square);
}

int three(int *g, int p)
{
	if( TL + ML + BL == p*2 )
	{
		if( TL==0 ) return 0;
		if( ML==0 ) return 3;
		if( BL==0 ) return 6;
	}
	if( TC + MC + BC == p*2 )
	{
		if( TC==0 ) return 1;
		if( MC==0 ) return 4;
		if( BC==0 ) return 7;
	}
	if( TR + MR + BR == p*2 )
	{
		if( TR==0 ) return 2;
		if( MR==0 ) return 5;
		if( BR==0 ) return 8;
	}

	if( TL + TC + TR == p*2 )
	{
		if( TL==0 ) return 0;
		if( TC==0 ) return 1;
		if( TR==0 ) return 2;
	}
	if( ML + MC + MR == p*2 )
	{
		if( ML==0 ) return 3;
		if( MC==0 ) return 4;
		if( MR==0 ) return 5;
	}
	if( BL + BC + BR == p*2 )
	{
		if( BL==0 ) return 6;
		if( BC==0 ) return 7;
		if( BR==0 ) return 8;
	}

	if( TL + MC + BR == p*2 )
	{
		if( TL==0 ) return 0;
		if( MC==0 ) return 4;
		if( BR==0 ) return 8;
	}
	if( TR + MC + BL == p*2 )
	{
		if( TR==0 ) return 2;
		if( MC==0 ) return 4;
		if( BL==0 ) return 6;
	}

	return(-1);
}

int computer(int p,int *g)
{
	int r;

	if( p==0 || (p==1 && MC==0) )
	{
		puts("The computer snags the center");
		return(5);
	}

	if( p==1 && TL==0 )
	{
		puts("The computer moves to square 1");
		return(1);
	}

	if( p%2 )
		r = three(g,-1);
	else
		r = three(g,1);	

	if( r==-1 )
	{
		if( p%2 )
			r = three(g,1);
		else
			r = three(g,-1);
	}

	if( r==-1 )
	{
		do
		{
			r = rand() % 9;
		} while( *(g+r) != 0 );
	}

	r++;
	printf("The computer moves to square %d\n",r);

	return(r);
}

int main()
{
	int grid[] = {
		0, 0, 0,
		0, 0, 0,
		0, 0, 0
	};
	int ply,p,players,first;

	srand( (unsigned)time(NULL) );

	puts("Tic-Tac-Toe");
	printf("Number of players (0, 1, 2): ");
	scanf("%d",&players);
	if( players<0 || players>2 )
		return(1);

	if( players==1 )
	{
		printf("A flip of the bitcoin says that ");
		first = rand()%2;
		if( first )
			puts("you go first\n");
		else
			puts("the computer goes first\n");
	}

	ply = 0;
	while(ply<9)
	{
		showgrid(grid);
		if( players==0 )
		{
			p = computer(ply,grid);
		}
		else if( players==1 )
		{
			if( ply%2==first )
			{
				p = computer(ply,grid);
			}
			else
			{
				while( (p = prompt(ply,grid)) == -1 )
					;
			}
		}
		else
		{
			while( (p = prompt(ply,grid)) == -1 )
				;
		}
		if( p==0 )
			break;
		grid[p-1] = ply%2 ? -1 : 1;
		if( winner(grid) )
			break;
		ply++;
	}
	if( ply==9 )
	{
		showgrid(grid);
		puts("Cat's game!");
	}

	return(0);
}
