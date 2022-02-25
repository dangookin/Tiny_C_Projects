#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_LINE 18
/* LENGTH must be udpated to account for the 3 new characters
   at the end of each line */
#define LENGTH (BYTES_PER_LINE*3+3+1)

int main()
{
	char line[LENGTH];
	int x,ch,hex;
	int checksum,row,b;		/* new */
	float version;			/* new */
	char *r;

	/* check for proper file format - first line */
	r = fgets(line,LENGTH,stdin);
	if( r==NULL || strncmp(line,"HEX ENCODE",10)!=0 )
	{
		fprintf(stderr,"Invalid HEX ENCODE data\n");
		exit(1);
	}
	/* first line is valid, now read in the version number */
		/* this trick works only because the first line is
		   specifically formatted */
	sscanf(line,"HEX ENCODE v%f",&version);
	/* oddly enough, my code digests both versions of hex
	   encoding properly, with or without checksums. If not,
	   the value of `version' is used to process the
	   checksum byte. (This is the "lucky turn of events") */

	/* main loop */
	x = 0;
	row = 0;				/* track the number of rows */
	while( (ch=getchar()) != EOF )
	{
		line[x] = ch;
		x++;
		if( ch=='\n' || x==LENGTH)
		{
			/* properly terminate line */
			if( line[x-1]=='\n')
				line[x-1] = '\0';
			else
				line[x] = '\0';

			/* stop processing on the last line */
			if( strncmp(line,"HEX ENCODE END",13)==0 )
				break;

			/* extract values */
			checksum = 0;			/* reset the checksum */
			b = 0;					/* monitor the byte count */
			r = strtok(line," ");
			while(r)
			{
				sscanf(r,"%02X",&hex);
				if( b<BYTES_PER_LINE)		/* still processing */
				{
					checksum += hex;		/* calculate checksum */
					printf("%c",hex);
					r = strtok(NULL," ");
					b++;					/* increase byte count */
				}
				else			/* checksum byte encountered */
				{
					if( hex != (checksum%0x100) )	/* validate */
					{
						/* Bad checksum */
						fprintf(stderr,"\nChecksum error at Line %d\n",row);
						fprintf(stderr,"Unable to decode data\n");
						exit(1);
						/* be aware that the stdout buffer does flush
						   at this point. You could eliminate the
						   output, but it's kinda too late. */
					}
					break;		/* must break loop up success
								   to read next line */
				}
			}
			x = 0;
			row++;				/* next row */
		}
	}

	return(0);
}

/* This code has a flaw in that it doesn't perform the
   checksum on the final line, specifically when the 
   last line is shorter than BYTES_PER_LINE. In this
   situation, the final checksum byte isn't checked
   and is added to the output.
   A solution is offered in the code hexout2.c, available
   in the GitHub repository */
