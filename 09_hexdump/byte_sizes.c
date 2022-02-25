#include <stdio.h>
#include <math.h>

int main()
{
	unsigned long byte = sizeof(char)*8;
	unsigned long word = sizeof(short)*8;
	unsigned long doubleword = sizeof(int)*8;
	unsigned long quadword = sizeof(long)*8;

	printf("%11s %2lu bits %21.f\n",
			"Byte",
			byte,
			pow(2,byte)
		  );
	printf("%11s %2lu bits %21.f\n",
			"Word",
			word,
			pow(2,word)
		  );
	printf("%11s %2lu bits %21.f\n",
			"Doubleword",
			doubleword,
			pow(2,doubleword)
		  );
	printf("%11s %2lu bits %21.f\n",
			"Quadword",
			quadword,
			pow(2,quadword)
		  );

	return(0);
}
