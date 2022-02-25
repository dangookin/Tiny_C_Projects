#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main()
{
	const wchar_t ah = 0x410;		/* first letter */
	const wchar_t ya = 0x42f;		/* last letter */
	const char *file = "cyrillic.wtxt";
	FILE *fp;
	wchar_t a;

	fp = fopen(file,"w");
	if( file==NULL )
	{
		fprintf(stderr,"Unable to create %s\n",file);
		exit(1);
	}
	
	setlocale(LC_CTYPE,"en_US.UTF-8");

	wprintf(L"Writing the Cyrillic alphabet...\n");
	for( a=ah; a<=ya; a++ )
	{
		fputwc(a,fp);
		fputwc(a,stdout);
	}
	fputwc('\0',fp);

	fclose(fp);
	wprintf(L"\nDone\n");

	return(0);
}
