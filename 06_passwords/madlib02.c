#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 32

struct term {
	char filename[16];
	FILE *fp;
	int items;
	char **list_base;
};

void build_vocabulary(struct term *t)
{
	char buffer[BSIZE];
	char *r,*entry;

	t->fp = fopen(t->filename,"r");
	if( t->fp==NULL )
	{
		fprintf(stderr,"Unable to open file %s\n",t->filename);
		exit(1);
	}

	t->list_base = malloc(sizeof(char *) * 100);
	if( t->list_base==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	t->items = 0;
	while( !feof(t->fp) )
	{
		r = fgets(buffer,BSIZE,t->fp);
		if( r==NULL )
			break;
		entry = malloc(sizeof(char) * strlen(buffer)+1);
		if( entry==NULL )
		{
			fprintf(stderr,"Unable to allocate memory\n");
			exit(1);
		}

		strcpy(entry,buffer);
		r = entry;
		while(*r)
		{
			if( *r=='\n' )
			{
				*r = '\0';
				break;
			}
			r++;
		}

		*(t->list_base+t->items) = entry;
		t->items++;
		if( t->items%100==0 )
		{
			t->list_base = realloc(t->list_base,sizeof(char *)*(t->items+100));
			if( t->list_base==NULL )
			{
				fprintf(stderr,"Unable to reallocate memory\n");
				exit(1);
			}
		}
	}
	fclose(t->fp);
}

char *add_word(struct term t)
{
	int word;

	word = rand() % t.items;
	return( *(t.list_base+word) );
}

int main()
{
	struct term noun = {"noun.txt",NULL,0,NULL};
	struct term verb = {"verb.txt",NULL,0,NULL};
	struct term adjective = {"adjective.txt",NULL,0,NULL};

	build_vocabulary(&noun);
	build_vocabulary(&verb);
	build_vocabulary(&adjective);
	
	srand( (unsigned)time(NULL) );

	printf("Will you please take the %s %s ",
			add_word(adjective),
			add_word(noun)
		  );
	printf("and %s the %s?\n",
			add_word(verb),
			add_word(noun)
		  );

	return(0);
}
