/*m<=24根火柴棍，求可以构造出多少个满足A+B=C的等式， 
其中=和+各需2根火柴棍*/  
#include<stdio.h>  
int fun(int x)  
  {  
     int f[10]={6,2,5,5,4,5,6,3,7,6};  
     int sum=0;  
     while(x/10!=0) //x至少是十位数及以上  
      {  
         sum+=f[x%10];  
         x=x/10;  
       }  
      sum+=f[x];  
      return sum;  
   }  
int main()  
{  
   int a,b,c,m,i,sum=0;  
   scanf("%d",&m);//输入火柴棍个数  
   for(a=0;a<11111;a++)  
    {  
     for(b=0;b<11111;b++)  
       {  
           c=a+b;  
           if(fun(a)+fun(b)+fun(c)==m-4)  
            {  
               printf("%d+%d=%d\n",a,b,c);  
               sum++;  
            }  
        }  
     }  
   printf("可以拼出不同的等式数量是%d\n",sum);  
   getchar();getchar();  
   return 0;  
} 