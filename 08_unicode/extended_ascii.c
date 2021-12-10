#include <stdio.h>

int main()
{
    int x,y;

    printf("      ");
    for(x=0; x<16; x++)
        printf(" %X ",x);
    putchar('\n');

    for( x=0x80;x<0x100; x+=0x10 )
    {
        printf(" 0x%2x ",x);
        for( y=0; y<0x10; y++ )
        {
            printf(" %c ",x+y);
        }
        putchar('\n');
    }

    return(0);
}
