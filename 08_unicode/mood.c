#include <locale.h>
#include <wchar.h>

int main()
{
	wchar_t mood;

	setlocale(LC_CTYPE,"en_US.UTF-8");

	wprintf(L"What is your mood? ");
	mood = getwchar();
	wprintf(L"I feel %lc, too!\n",mood);

	return(0);
}
