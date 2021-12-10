#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main()
{
	const int size = 32;
	wchar_t input[size];

	setlocale(LC_CTYPE,"UTF-8");
	
	wprintf(L"Type some fancy text: ");
	fgetws(input,size,stdin);
	wprintf(L"You typed: '%ls'\n",input);

	return(0);
}
