#include <stdio.h>

int main()
{
	int items,draw,x;
	unsigned long long i,d;

	printf("Number of items: ");
	scanf("%d",&items);
	printf("Items to draw: ");
	scanf("%d",&draw);

	/* confirm that either input isn't zero or less than zero */
	if( items<0 || draw<0 )
	{
		fprintf(stderr,"Enter amounts larger than zero\n");
		return(1);
	}
	/* confirm that draw isn't > items */
	if( draw>items )
	{
		fprintf(stderr,"Items to draw cannot be greater than items\n");
		return(1);
	}

	i = items;
	d = draw;
	for(x=1;x<draw;x++)
	{
		i *= items-x;
		d *= draw-x;
	}
	printf("Your odds of drawing %d\n",draw);
	printf("items from %d are:\n",items);
	printf("\t1:%.0f\n",(float)i/(float)d);

	return(0);
}
