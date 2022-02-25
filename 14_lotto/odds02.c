#include <stdio.h>

int main()
{
	int items,draw,x;
	unsigned long long i,d;

	printf("Number of items: ");
	scanf("%d",&items);
	printf("Items to draw: ");
	scanf("%d",&draw);

	i = items;
	d = draw;
	for(x=1;x<draw;x++)
	{
		i *= items-x;
		d *= draw-x;
	}
	printf("Your odds of drawing %d ",draw);
	printf("items from %d are:\n",items);
	printf("\t1:%.0f\n",(float)i/(float)d);

	return(0);
}
