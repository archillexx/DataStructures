//Circular Queue
#include<stdio.h>
#define max 3

char cq[max];
int rear=-1,front=0,count=0;
void insert(char ele)
{
	if(count==max)
		printf("\n Queue overflow");
	else
	{
		rear=(rear+1)%max;
		cq[rear]=ele;
		count++;
	}
}
void del()
{
	if(count==0)
		printf("\n Queue underflow");
	else
	{
		printf("\n The deleted element is %c",cq[front]);
		front=(front+1)%max;
		count--;
	}
}
void display()
{
	int i,c;
	if(count==0)
		printf("\n Queue is empty");
	else
	{
		i=front;
		for(c=1;c<=count;c++)
		{
			printf("%c\t",cq[i]);
			i=(i+1)%max;
		}
	}
}
int main()
{
	int choice;
	char element;
	while(1)
	{
		
		printf("\n Enter 1:insert\t Enter 2:delete\t Enter 3:display\t Enter 4:exit\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("\n Enter the element");
					element=getche();
					insert(element);break;
			case 2:	del();break;
			case 3:	display();break;
			case 4:	return 0;
		}
	}
}  

