#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	char *filename;
	struct stat fs;
	int r;

	if( argc<2 )
	{
		fprintf(stderr,"Specify a filename\n");
		exit(1);
	}

	filename = argv[1];
	printf("Info for file '%s'\n",filename);
	r = stat(filename,&fs);
	if( r==-1 )
	{
		fprintf(stderr,"Error reading '%s'\n",filename);
		exit(1);
	}

	printf("Type and mode: %X\n",fs.st_mode);
	if( S_ISREG(fs.st_mode) )
		printf("%s is a regular file\n",filename);
	else
		printf("%s is not a regular file\n",filename);

	return(0);
}
