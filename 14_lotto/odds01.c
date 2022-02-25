#include <stdio.h>

int main()
{
	int ow,ol;

	printf("Chances of happening: ");
	scanf("%d",&ow);
	printf("Chances of not happening: ");
	scanf("%d",&ol);

	printf("Your odds of winning are %2.1f%%, or %d:%d\n",
			(float)ow/(float)(ow+ol)*100,
			ow,
			ol
		  );

	return(0);
}
