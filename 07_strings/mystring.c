/* mystring library */
/* 10 September 2021 */
/* Dan Gookin, dan@gookin.com */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Return the left portion of a string
   s = string
   len = length to cut from the left
   return value: new string
 */  
char *left(char *s,int len)
{
	static char *buf;
	int x;

	buf = malloc(sizeof(char)*len+1);
	if( buf==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}

	for(x=0;x<len;x++)
	{
		if( *(s+x)=='\0' )
			break;
		*(buf+x) = *(s+x);
	}
	*(buf+x) = '\0';

	return(buf);
}

/* Return the middle portion of a string
   s = string
   offset = character into the string to start
   len = length to cut from the middle
   return value: new string
 */  
char *mid(char *s, int offset, int len)
{
	static char *buf;
	int x;

	buf = (char *)malloc(sizeof(char)*len+1);
	if( buf==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}

	for(x=0;x<len;x++)
	{
		*(buf+x) = *(s+offset-1+x);
		if( *(buf+x)=='\0')	
			break;
	}
	*(buf+x) = '\0';

	return(buf);
}

/* Return the right portion of a string
   s = string
   len = length to cut from the right
   return value: new string
 */  
char *right(char *s,int len)
{
	static char *buf;
	char *start;
	int x;

	buf = (char *)malloc(sizeof(char)*len+1);
	if( buf==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}

	start = s;
	while(*start!='\0')
	   start++;
	start -= len;
	if( start < s )
		exit(1);

	for(x=0;x<len;x++)
		*(buf+x) = *(start+x);
	*(buf+x) = '\0';

	return(buf);
}

/* Capitalize the first letter of words in a string
   s = string
   String is altered directly; nothing returned
 */  
void strcaps(char *s)
{
	enum { FALSE, TRUE };
	int inword = FALSE;	

	while(*s)
	{
		if( isalpha(*s) )
		{
			if( !inword )
			{
				*s = toupper(*s);
				inword = TRUE;
			}
		}
		else
		{
			inword = FALSE;
		}
		s++;
	}
}

/* Insert one string into another
   org = string
   int = string to insert into 'org'
   offset = where to insert the string
   return value: new string
 */  
char *strinsert(char *org, char *ins, int offset)
{
	static char *new;
	int size,index,append;

	size = strlen(org)+strlen(ins);
	if( offset<0 )
		return(NULL);

	new = malloc(sizeof(char) * size+1);
	if( new==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}
	
	offset -= 1;
	index = 0;
	append = 0;
	while( *org )
	{
		if( index==offset )
		{
			while( *ins )
			{
				*(new+index) = *ins;
				index++;
				ins++;
			}
			append = 1;
		}
		*(new+index) = *org;
		index++;
		org++;
	}
	if( !append )
	{
		while( *ins )
		{
			*(new+index) = *ins;
			index++;
			ins++;
		}
	}
	*(new+index) = '\0';

	return(new);
}

/* Convert a string to lowercase
   s = string
   String is altered directly; nothing returned
 */  
void strlower(char *s)
{
	while(*s)
	{
		if( *s>='A' && *s<='Z' )
		{
			*s += 32;
		}
		s++;
	}
}

/* Reverse cahracters in a string
   s = string
   Return value: String with reversed text
 */  
char *strrev(char *s)
{
	int len,i;
	static char *reversed;

	len = 0;
	while( *s )
	{
		len++;
		s++;
	}

	reversed = malloc( sizeof(char) * len );
	if( reversed==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	s--;
	i = 0;
	while(len)
	{
		*(reversed+i) = *s;
		i++;
		len--;
		s--;
	}
	*(reversed+i) = '\0';

	return(reversed);
}

/* Split a string into two parts
   org = string to split
   offset = location of the split
   s1 = address for the first part of the string
   s2 = address for the second part of the string
   Return value: 0, error; 1, success
 */  
int strsplit(char *org,int offset,char **s1,char **s2)
{
	int len;

	len = strlen(org);
	if(offset > len)
		return(0);
	*s1 = malloc(sizeof(char) * offset+1);
	*s2 = malloc(sizeof(char) * len-offset+1);
	if( s1==NULL || s2==NULL )
		return(0);
	strncpy(*s1,org,offset);
	strncpy(*s2,org+offset,len-offset);
	return(1);
}

/* Output text with a specific tab stop
   s = string to output
   tab = tab stop interval
   Return value: nothing
 */  
void strtabs(const char *s, int tab)
{
	int column,x,spaces;

	column = 0;
	while(*s)
	{
		if( *s == '\t')
		{
			spaces = tab - (column % tab);
			for( x=0; x<spaces; x++ )
				putchar(' ');
			column += spaces;
		}
		else
		{
			putchar(*s);
			if( *s=='\n' )
				column = 0;
			else
				column++;
		}
		s++;
	}
}

/* Convert a string to uppercase
   s = string to convert
   Return value: Nothing
 */  
void strupper(char *s)
{
	while(*s)
	{
		if( *s>='a' && *s<='z' )
		{
			*s &= 0xdf;
		}
		s++;
	}
}

/* Count the number of words in a string
   s = string
   Return value: number of words in the string
 */  
int strwords(char *s)
{
	enum { FALSE, TRUE };
	int inword = FALSE;	
	int count;

	count = 0;
	while(*s)
	{
		if( isalpha(*s) )
		{
			if( !inword )
			{
				count++;
				inword = TRUE;
			}
		}
		else
		{
			if( *s=='\'' && isalpha(*(s+1)))
				inword = TRUE;
			else
				inword = FALSE;
		}
		s++;
	}

	return(count);
}
