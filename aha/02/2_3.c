//说明：在linux下使用gcc，securecrt终端下，需要将Option-->Session Options...-->Appearance-->ANSI/OEM-简体中文  才能正确显示中文？？？

//https://www.zhihu.com/question/40772140/answer/88991689
//打印输出来的是 码，解释这个码是终端的事情，所以自动解码双字节码还是unicode，然后选择点阵字库还是矢量字库，然后默认某个字体输出，都是终端的事情，和printf没有关系啊。

/*
输入一下数据：
2 4 1 2 5 6
3 1 3 5 6 4
*/
#include <stdio.h>  
  
struct queue  
{  
    int data[1000];  
    int head;  
    int tail;  
};  
struct stack  
{  
    int data[10];  
    int top;  
};  
int main()  
{  
    struct queue q1,q2;  
    struct stack s;  
    int i,t,book[10];  
    //初始化队列  
    q1.head=1;  
    q1.tail=1;  
    q2.head=1;  
    q2.tail=1;  
    //初始化栈  
    s.top=0;  
    //初始化用来标记的数组，用来标记哪些牌已经放在桌上  
    for(i=1; i<=9; i++)  
        book[i]=0;  
        //依次向队列中插入6个数，即小哼和小哈手中的牌  
    for(i=1; i<=6; i++)  
    {  
        scanf("%d",&q1.data[q1.tail]);  
        q1.tail++;  
    }  
    for(i=1; i<=6; i++)  
    {  
        scanf("%d",&q2.data[q2.tail]);  
        q2.tail++;  
    }  
    while(q1.head<q1.tail&&q2.head<q2.tail)  //当队列不为空时循环  
    {  
        t=q1.data[q1.head];    //小哼出第一张牌  
        //判断小哼是否赢牌  
        if(book[t]==0)     //表示桌面上没有此牌  
        {  
            q1.head++;   //打出的牌出队  
            s.top++;     //打出的牌入栈  
            s.data[s.top]=t;  
            book[t]=1;   //标记桌面上有此牌  
        }  
        else  
        {  
            //小哼赢得此牌  
            q1.head++;       //打出的牌入队  
            q1.data[q1.tail]=t;  
            q1.tail++;  
            while(s.data[s.top]!=t)  //把桌上可以赢得的牌依次放入手中牌的末尾  
            {  
                book[s.data[s.top]]=0;  //取消标记  
                q1.data[q1.tail]=s.data[s.top];    //依次放入末尾  
                q1.tail++;  
                s.top--;     //栈中少了一张牌，栈减1  
            }  
            //收回桌上牌面为t的牌  
            book[s.data[s.top]]=0;  
            q1.data[q1.tail]=s.data[s.top];  
            q1.tail++;  
            s.top--;  
        }  
        if(q1.head==q1.tail)   //小哈手中的牌如果已经打完，游戏结束  
            break;  
        //小哈出牌同小哼  
        t=q2.data[q2.head];  
        if(book[t]==0)  
        {  
            q2.head++;  
            s.top++;  
            s.data[s.top]=t;  
            book[t]=1;  
        }  
        else  
        {  
            q2.head++;  
            q2.data[q2.tail]=t;  
            q2.tail++;  
            while(s.data[s.top]!=t)  
            {  
                book[s.data[s.top]]=0;  
                q2.data[q2.tail]=s.data[s.top];  
                q2.tail++;  
                s.top--;  
            }  
            book[s.data[s.top]]=0;  
            q2.data[q2.tail]=s.data[s.top];  
            q2.tail++;  
            s.top--;  
        }  
    }  
    if(q2.head==q2.tail)  
    {  
        printf("小哼win\n");  
        printf("小哼当前手中的牌是");  
        for(i=q1.head; i<=q1.tail-1; i++)  
            printf(" %d ",q1.data[i]);  
        if(s.top>0)  
        {  
            printf("\n桌上的牌是");
            for(i=1; i<=s.top; i++)  
                printf("%d ",s.data[i]);  
        }  
        else  
            printf("\n桌上已经没有牌了");  
    }  
    else  
    {  
            printf("小哈win\n");  
            printf("小哈当前手中的牌是");  
        for(i=q2.head; i<=q2.tail-1; i++)  
                printf(" %d ",q2.data[i]);  
        if(s.top>0)  
        {  
            printf("\n桌上的牌是");  
            for(i=1; i<=s.top; i++)  
				printf(" %d ",s.data[i]);  
        }  
        else  
                printf("\n桌上已经没有牌了");  
    }  
    getchar();  
    getchar();  
    return 0;  
} 