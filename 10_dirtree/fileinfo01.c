#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

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

	printf("Media ID: %lu\n",fs.st_dev);
	printf("Inode #%lu\n",fs.st_ino);
	printf("Type and mode: %u\n",fs.st_mode);
	printf("Hard links = %lu\n",fs.st_nlink);
	printf("Owner ID: %u\n",fs.st_uid);
	printf("Group ID: %u\n",fs.st_gid);
	printf("Device ID: %lu\n",fs.st_rdev);
	printf("File size %lu bytes\n",fs.st_size);
	printf("Block size = %lu\n",fs.st_blksize);
	printf("Allocated blocks = %lu\n",fs.st_blocks);
	printf("Access: %s",ctime(&fs.st_atime));
	printf("Modification: %s",ctime(&fs.st_mtime));
	printf("Changed: %s",ctime(&fs.st_ctime));

	return(0);
}
