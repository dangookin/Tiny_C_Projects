#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main()
{
	const wchar_t alpha = 0x391;
	const wchar_t omega = 0x3a9;
	const wchar_t no_sigma = 0x3a2;
	const char *file = "alphabeta.wtxt";
	FILE *fp;
	wchar_t a;

	fp = fopen(file,"w");
	if( file==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",file);
		exit(1);
	}
	
	setlocale(LC_CTYPE,"en_US.UTF-8");

	wprintf(L"Writing the Greek alphabet...\n");
	for( a=alpha; a<=omega; a++ )
	{
		if( a==no_sigma )
			continue;
		fputwc(a,fp);
		fputwc(a,stdout);
	}
	fputwc('\0',fp);

	fclose(fp);
	wprintf(L"\nDone\n");

	return(0);
}
