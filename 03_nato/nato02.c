#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	const char *nato[] = {
		"Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
		"Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
		"Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
		"Sierra", "Tango", "Uniform", "Victor", "Whiskey",
		"Xray", "Yankee", "Zulu"
	};
	FILE *n;
	int ch;

	if( argc<2 )
	{
		fprintf(stderr,"Please supply a text file argument\n");
		exit(1);
	}

	n = fopen(argv[1],"r");
	if( n==NULL )
	{
		fprintf(stderr,"Unable to open '%s'\n",argv[1]);
		exit(1);
	}

	while( (ch=fgetc(n))!=EOF )
	{
		if(isalpha(ch))
			printf("%s ",nato[toupper(ch)-'A']);
	}
	putchar('\n');

	fclose(n);

	return(0);
}
