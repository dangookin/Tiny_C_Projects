#include <wchar.h>

int main()
{
	wchar_t hello[] = L"Hello, wide world!\n";

	wprintf(L"%ls",hello);

	return(0);
}
