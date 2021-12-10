#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main()
{
	wchar_t russian[] = {
		0x41f, 0x440, 0x438, 0x432, 0x435, 0x442, '!' , '\n', '\0'
	};
	wchar_t chinese[] = {
		0x4f31, 0x597d, '\n', '\0'
	};
	wchar_t emoji[] = {
		0x1f44b, '\n', '\0'
	};

	setlocale(LC_ALL,"en_US.UTF-8");
	fputws(russian,stdout);
	fputws(chinese,stdout);
	fputws(emoji,stdout);

	return(0);
}
