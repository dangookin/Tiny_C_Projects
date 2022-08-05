#include <stdio.h>
#include <limits.h>

int main()
{
	printf("Char:\n");
	printf("\tNumber of bits: %d\n",CHAR_BIT);
	printf("\tSigned minimum: %d\n",SCHAR_MIN);
	printf("\tSigned maximum: %d\n",SCHAR_MAX);
	printf("\tUnsigned max: %d\n",UCHAR_MAX);

	printf("Short:\n");
	printf("\tSigned minimum: %d\n",SHRT_MIN);
	printf("\tSigned maximum: %d\n",SHRT_MAX);
	printf("\tUnsigned max: %d\n",USHRT_MAX);

	printf("Int:\n");
	printf("\tSigned minimum: %d\n",INT_MIN);
	printf("\tSigned maximum: %d\n",INT_MAX);
	printf("\tUnsigned max: %u\n",UINT_MAX);

	printf("Long:\n");
	printf("\tSigned minimum: %ld\n",LONG_MIN);
	printf("\tSigned maximum: %ld\n",LONG_MAX);
	printf("\tUnsigned max: %lu\n",ULONG_MAX);

	printf("Long long:\n");
	printf("\tSigned minimum: %lld\n",LLONG_MIN);
	printf("\tSigned maximum: %lld\n",LLONG_MAX);
	printf("\tUnsigned max: %llu\n",ULLONG_MAX);

	return(0);
}
