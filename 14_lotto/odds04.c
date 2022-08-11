#include <stdio.h>
#include <string.h>		/* for strlen() function */

/* accept a floating point value as input;
   return a string with commas every three places.
   input is assumed to be a positive value with
   no decimal portion */
char *commify(float bignum)
{
	const int size = 128;			/* large enough */
	char string[size];				/* original string */
	static char commas[size];		/* commified string */
	int len,s,c;

	/* store the value as a string */
	snprintf(string,size,"%.0f",bignum);
	len = strlen(string);
	s = c = 0;

	/* some initial tests */
	if( bignum<1 )		/* if the number is zero or negative */
	{
		strcpy(commas,"0");	/* return zero */
		return(commas);
	}
	if( bignum<1000 )	/* no need to add any commas */
	{
		strcpy(commas,string);	/* just copy the string */
		return(commas);
	}

	
	/* loop forward through the number stored in string */
	while(string[s])
	{
		if( len%3==0 && c>0 )	/* add a comma every third character */
		{						/* after the initial character */
			commas[c] = ',';
			c++;
		}
		commas[c++] = string[s++];	/* otherwise, copy the character */
		len--;
	}

	return(commas);
}

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
	printf("\t1:%s\n",commify((float)i/(float)d) );

	return(0);
}
