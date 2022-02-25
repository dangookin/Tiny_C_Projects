#include <stdio.h>
#include <ctype.h>

int main()
{
	char *nato[] = {
		"Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
		"Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
		"Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
		"Sierra", "Tango", "Uniform", "Victor", "Whiskey",
		"Xray", "Yankee", "Zulu"
	};
	char ch;

	while( (ch=getchar()) != EOF)
	{
		if(isalpha(ch))
			printf("%s ",nato[toupper(ch)-'A']);
		if( ch=='\n' )
			putchar(ch);
	}
	putchar('\n');

	return(0);
}
