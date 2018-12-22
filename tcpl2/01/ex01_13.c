#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN       1
#define OUT      0

int main(void)
{
    int c, i, j, nc, state;
    int maxvalue;
    int ovflow;
    int wl[MAXWORD];
    state = OUT;
    nc = 0;
    ovflow =0;
    for(i = 0; i < MAXWORD; ++i)
    {
        wl[i] = 0;
    }
    while((c = getchar()) != EOF) 
    {
        if(c == ' ' || c == '\n' || c == '\t') 
        {
            state = OUT;
            if(nc > 0)
            {
                if(nc < MAXWORD)
                {
                    ++wl[nc];
                }
                else
                {
                    ++ovflow;
                }
            }
            nc =0;
        } 
        else if(state == OUT) 
        {
            state = IN;
            nc = 1;   
        }
        else
        {
            ++nc;
        }
    }
    maxvalue = 0;
    for(i = 1; i < MAXWORD; ++i)
    {
        if(wl[i] > maxvalue)
        {
            maxvalue = wl[i];
        }
    }

#if 0
    for(i = MAXHIST; i >0 ; --i)
    {
        for(j = 1; j < MAXWORD; ++j)
        {
            if(wl[j] * MAXHIST / maxvalue >= i)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }
        putchar('\n');
    }
#else//和上面的注释代表比较，对比输出的情况，选择个人认为更直观的那种
    for(i = MAXHIST; i >0 ; --i) 
    {
        for(j = 1; j < MAXWORD; ++j)
        {
            if(wl[j] >= i)
            {
                printf(" * ");
            }            
            else
            {
                printf("   ");
            }
        }
        putchar('\n');
    }
#endif
    for(i = 1; i < MAXWORD; ++i)
    {
        printf("%2d ",i);
    }
    putchar('\n');

    for(i = 1; i < MAXWORD; ++i)
    {
        printf("%2d ",wl[i]);
    }
    putchar('\n');
    if(ovflow > 0)
    {
        printf("There are %d words >= %d\n",ovflow, MAXWORD);
    }
    
    return 0;
}