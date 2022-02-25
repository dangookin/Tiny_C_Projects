#include <wchar.h>
#include <locale.h>

int main()
{
	const int count = 4;
	wchar_t suits[count] = {
		0x2660, 0x2665, 0x2663, 0x2666
	};
	int x;

	setlocale(LC_CTYPE,"en_US.UTF-8");

	for( x=0; x<count; x++ )
		putwchar(suits[x]);
	putwchar('\n');

	return(0);
}
