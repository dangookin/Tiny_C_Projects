#include <stdio.h>

#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define FAINT "\x1b[2m"
#define UNDERLINE "\x1b[4m"
#define BLINK "\x1b[5m"
#define INVERSE "\x1b[7m"

int main()
{
	printf("%sBold text%s\n",BOLD,RESET);
	printf("%sFaint text%s\n",FAINT,RESET);
	printf("%sUnderline text%s\n",UNDERLINE,RESET);
	printf("%sBlinking text%s\n",BLINK,RESET);
	printf("%sInverse text%s\n",INVERSE,RESET);

	return(0);
}
