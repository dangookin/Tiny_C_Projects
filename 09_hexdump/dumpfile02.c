#include <stdio.h>
#include <stdlib.h>

#define SIZE 16

void line_out(int offset, int length, unsigned char *data)
{
	int a;

	printf("%05X ",offset);

	for( a=0; a<length; a++ )
	{
		printf(" %02X",*(data+a));
		if( (a+1)%8==0 )
			putchar(' ');
	}

	if( length<SIZE )
	{
		for( ; a<SIZE; a++ )
		{
			printf("   ");
			if( (a+1)%8==0 )
				putchar(' ');
		}
	}

	putchar(' ');
	for( a=0; a<length; a++ )
	{
		if( *(data+a)>=' ' && *(data+a)<='~' )
			putchar( *(data+a) );
		else
			putchar(' ');
	}

	putchar('\n');
}

int main(int argc, char *argv[])
{
	unsigned char buffer[SIZE];
	char *filename;
	FILE *fp;
	int ch,offset,index;

	if( argc<2 )
	{
		fprintf(stderr,"Format: dumpfile filename\n");
		exit(1);
	}

	filename = argv[1];
	fp = fopen(filename,"r");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to open file '%s'\n",filename);
		exit(1);
	}

	offset = 0;
	index = 0;
	while( !feof(fp) )
	{
		ch = fgetc(fp);
		if( ch==EOF )
		{
			if( index != 0 )
				line_out(offset,index,buffer);
			break;
		}
		buffer[index] = ch;
		index++;
		if( index==SIZE )
		{
			line_out(offset,SIZE,buffer);
			offset+=SIZE;
			index = 0;
		}
	}

	fclose(fp);

	return(0);
}
