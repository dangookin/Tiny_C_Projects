/* mystring library header file */
/* 10 September 2021 */
/* Dan Gookin, dan@gookin.com */

#define mystring_version "1.0"
#define mystring_version_major 1
#define mystring_version_minor 0

char *left(char *s,int len);
char *mid(char *s, int offset, int len);
char *right(char *s,int len);
void strcaps(char *s);
char *strinsert(char *org, char *ins, int offset);
void strlower(char *s);
char *strrev(char *s);
int strsplit(char *org,int offset,char **s1,char **s2);
void strtabs(const char *s, int tab);
void strupper(char *s);
int strwords(char *s);

