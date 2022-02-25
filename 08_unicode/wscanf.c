#include <wchar.h>
#include <locale.h>

int main()
{
	const wchar_t pound = 0xa3;
	int quantity;
	float total;

	setlocale(LC_CTYPE,"en_US.UTF-8");

	wprintf(L"How many crisps do you want? ");
	wscanf(L"%d",&quantity);
	total = quantity * 1.4;
	wprintf(L"That'll be %lc%.2f\n",
			pound,
			total
		  );

	return(0);
}
