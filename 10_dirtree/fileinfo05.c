#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/* mode_t is the file type for structure member st_mode */
void permissions_out(mode_t m)
{
	/* I use the ternary operator to output either the
	   appropriate letter or the dash */
	putchar( m & S_IRUSR ? 'r' : '-' );
	/* each of the 9 settings are output in turn */
	putchar( m & S_IWUSR ? 'w' : '-' );
	putchar( m & S_IXUSR ? 'x' : '-' );
	putchar( m & S_IRGRP ? 'r' : '-' );
	putchar( m & S_IWGRP ? 'w' : '-' );
	putchar( m & S_IXGRP ? 'x' : '-' );
	putchar( m & S_IROTH ? 'r' : '-' );
	putchar( m & S_IWOTH ? 'w' : '-' );
	putchar( m & S_IXOTH ? 'x' : '-' );
	/* a final putchar() to end the string */
	putchar('\n');
}

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
	r = stat(filename,&fs);
	if( r==-1 )
	{
		fprintf(stderr,"Error reading '%s'\n",filename);
		exit(1);
	}

	printf("Permissions for file %s: ",filename);
	/* the function call, with the st_mode member as
	   the argument */
	permissions_out(fs.st_mode);

	return(0);
}
