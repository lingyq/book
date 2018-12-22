/*功能：同上，用数组模拟链表*/  
#include<stdio.h>  

int main()  
{
	int date[101],right[101];  
	int i,n,t,len;  

	scanf("%d",&n);  
	for(i=1;i<=n;i++)  
	scanf("%d",&date[i]);    
	len=n;  

	//初始化right数组,right数组存放的是date的下标值  
	for(i=1;i<=n;i++)  
	{  
		if(i!=n)  
			right[i]=i+1;  
		else  
			right[i]=0; //表示最后一个    

		len++;//date添加一个数；  
		scanf("%d",&date[len]);  

		//链表头部开始遍历  
		t=1;  
		while(t!=0)  
		{  
			if(date[right[t]]>date[len])  
			{  
				right[len]=right[t];  
				right[t]=len;  
				break;  
			}  
			t=right[t];    
		}  

		t=1;  
		while(t!=0)  
		{  
			printf("%d",date[t]);  
			t=right[t];  
		}  
		getchar();  
		getchar();  
		return 0;  
	}  
}   