#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

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

char *number(void)
{
	static char n[2];

	n[0] = rand() % 10 + '0';
	n[1] = '\0';

	return(n);
}

char *symbol(void)
{
	char sym[8] = "!@#$%*_-";
	static char s[2];

	s[0] = sym[rand() % 8];
	s[1] = '\0';

	return( s );
}

/* Ensure that the passed string has at least one
   uppercase letter */
void check_caps(char *string)
{
	int found,r,len;
	char *s;

	/* initial scan */
	found = 0;
	s = string;
	while( *s )
	{
		if( isupper(*s) )
		{
			found = 1;
			break;
		}
		s++;
	}
	if(found)			/* exit if the string has a capital letter */
		return;

	/* make a random letter uppercase */
	len = strlen(string);
	s = string;
	while(1)
	{
		r = rand() % len;			/* random character in the string */
		if( islower( *(s+r) ))		/* if the character is lowercase */
		{
			*(s+r) = toupper(*(s+r));	/* make it uppercase */
			break;					/* and leave */
		}
	}
}

int main()
{
	char password[32];
	struct term noun = {"noun.txt",NULL,0,NULL};
	struct term verb = {"verb.txt",NULL,0,NULL};
	struct term adjective = {"adjective.txt",NULL,0,NULL};

	build_vocabulary(&noun);
	build_vocabulary(&verb);
	build_vocabulary(&adjective);
	
	srand( (unsigned)time(NULL) );

	password[0] = '\0';
	strcpy(password,add_word(noun));
	strcat(password,number());
	strcat(password,add_word(verb));
	strcat(password,symbol());
	strcat(password,add_word(adjective));

	check_caps(password);
	printf("%s\n",password);

	return(0);
}
