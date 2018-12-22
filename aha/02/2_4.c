/* 
功能：链表中插入数据并输出所有数据  
*/  
#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
	int date;  
	struct node *next;  
};  

int main()  
{  
	struct node *head,*p,*q,*t;  
	int i,n,a;  

	scanf("%d",&n);  
	head=NULL;  

	for(i=1;i<=n;i++)  
	{  
		scanf("%d",&a);  
		p=(struct node *)malloc(sizeof(struct node));  
		p->date=a;  
		p->next=NULL;  

		if(head==NULL)  
		head=p;  
		else  
		q->next=p;  
		q=p;  
	}
	
	scanf("%d",&a);  
	t=head;  
	while(t!=NULL)  
	{
		if(t->next->date>a)  
		{  
			p=(struct node *)malloc(sizeof(struct node));  
			p->date=a;  
			p->next=t->next;  
			t->next=p;  
			break;  
		}  
		t=t->next;  
	}
	
	//输入链表中所有数  
	t=head;  
	while(t!=NULL)  
	{  
		printf("%d ",t->date);  
		t=t->next;  
	}
	
	getchar();getchar();  
	return 0;  
}