//Single LinkedList
#include<stdio.h>
#include<stdlib.h>
struct SLL
{
	char usn[11];
	char name[30];
	char branch[4];
	int sem;
	char phno[11];
	struct SLL *link;
};
typedef struct SLL node;
node *start=NULL;
node *getnode()
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	if(newnode==NULL)
		printf("Memory overflow");
	else
	{
		printf("\n Enter USN, name, branch, sem, phone number\n");
		scanf("%s%s%s%d%s",newnode->usn,newnode->name,newnode->branch,
				&newnode->sem,newnode->phno);
		newnode->link=NULL;
		return newnode;
	}
}
void insert_front()
{
	node *nn;
	nn=getnode();
	nn->link=start;
	start=nn;
}
void delete_front()
{
	node *temp;
	if(start==NULL)
		printf("\n List is empty");
	else
	{
		temp=start;
		start=start->link;
		free(temp);
	}
}
void insert_end()
{
	node *nn,*temp;
	nn=getnode();
	if(start==NULL)
		start=nn;
	else
	{
		temp=start;
		while(temp->link!=NULL)
			temp=temp->link;
		temp->link=nn;
	}
}
void delete_end()
{
	node *temp=start,*prev;
	if(start==NULL)
	{
		printf("\n Empty list");
		return;
	}
	if(start->link==NULL)
		start=NULL;
	else
	{
		while(temp->link!=NULL)
		{
			prev=temp;
			temp=temp->link;
		}
		prev->link=NULL;
	}	
	free(temp);
}
void display()
{
	int c=0;
	node *temp;
	if(start==NULL)
		printf("\n Empty list");
	else
	{
		temp=start;
		printf("\n The details are");
		while(temp!=NULL)
		{
			printf("\n%s\t%s\t%s\t%d\t%s\t",temp->usn,temp->name,temp->branch,
			temp->sem,temp->phno);
			c++;
			temp=temp->link;
		}
		printf("\n Number of nodes is %d",c);
	}
}
int main()
{
	int n,m,i;
	while(1)
	{
		printf("\n Enter 1:insert_front\n 2:insert_end\n 3:delete_front\n 4:delete_end\n 5:display");
		scanf("%d",&m);
		switch(m)
		{
			case 1: printf("\n Enter n");
				    scanf("%d",&n);
				    for(i=0;i<n;i++)
				      	insert_front();
				 	break;
			case 2: insert_end();break;
			case 3: delete_front();break;
			case 4: delete_end();break;
			case 5:	display();break;
			default:return 0;
		}
	}
}

