#include <wchar.h>
#include <locale.h>

int main()
{
	wchar_t s[] = L"That will be $500\n";

	setlocale(LC_CTYPE,"en_US.UTF-8");

	s[13] = 0xa5;
	wprintf(L"%ls",s);

	return(0);
}
