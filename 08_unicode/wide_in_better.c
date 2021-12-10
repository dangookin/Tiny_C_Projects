#include <stdio.h>
#include <wchar.h>
#include <locale.h>

/* remove the \n from wide string s */
void newline_strip(wchar_t *s)
{
	while( *s )				/* loop until the null char is found */
	{
		if( *s=='\n' )		/* upon finding the newline... */
		{
			*s = '\0';		/* ...replace it with the null char */
			return;			/* and return */
		}
		s++;				/* keep looping */
	}
}

int main()
{
	const int size = 32;
	wchar_t input[size];

	setlocale(LC_CTYPE,"UTF-8");
	
	wprintf(L"Type some fancy text: ");
	fgetws(input,size,stdin);
	newline_strip(input);
	wprintf(L"You typed: '%ls'\n",input);

	return(0);
}
