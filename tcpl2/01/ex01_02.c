#include <stdio.h>

int main(void)
{
#if 0
    printf("\65\n");
    printf("\060\n");
    printf("\x40\n");
    printf("hello, world\y"); //会报警告，warning: unknown escape sequence: '\y'，这条语句会直接输出字符y
    printf("hello, world\7");
    printf("hello, world\?");
    printf("Audible or visual alert. \a\n");  
    printf("Form feed. \f\n");
    printf("Form feed.\b \n");
    printf("This escape, \r, moves the active position to the initial position of the current line.\n");
    printf("Vertical tab \v is tricky, as its behaviour is unspecified under certain conditions.\n");
#else
    int i ;
    for(i = 0; i <128; i++)
    {
        printf("ASCII : %d  0x%0x    %c\n",i,i,i);
    }
#endif

    return 0;
}