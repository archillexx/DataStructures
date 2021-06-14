//Doubly LinkedList
#include<stdio.h>
#include<stdlib.h>
struct DList
{
	int ssn;
	char name[20];
	char desg[20];
	char dept[20];
	int sal;
	char phno[11];
	struct DList *left,*right;
};
typedef struct DList dnode;
dnode *start=NULL;
dnode *getnode()
{
	dnode *newnode;
	newnode=(dnode*)malloc(sizeof(dnode));
	if(newnode==NULL)
		printf("Memory Overflow\n");
	else
	{
		printf("\n Enter ssn, name, designation,department,salary, phone number");
		scanf("%d%s%s%s%d%s",&newnode->ssn,newnode->name,newnode->desg,
newnode->dept,&newnode->sal,newnode->phno);
		newnode->left=NULL;
		newnode->right=NULL;
	}
	return newnode;
}
void insert_front()
{
	dnode* newnode;
	newnode=getnode();
	if(start==NULL)
		start=newnode;
	else
	{
		newnode->right=start;
		start->left=newnode;
		start=newnode;
	}
}
void delete_front()
{
	dnode *temp;
	if(start==NULL)
		printf("Empty list");
	else
	{
		temp=start;
		start=start->right;
		if(start!=NULL)
			start->left = NULL;
		printf("Deleted node value is %d\n",temp->info);
		free(temp);
	}
}
void insert_end()
{
	dnode *newnode, *temp;
	newnode=getnode();
	if(start==NULL)
		start=newnode;
	else
	{
		temp=start;
		while(temp->right!=NULL)
			temp=temp->right;
		newnode->left=temp;
		temp->right=newnode;
	}
}
void delete_end()
{
	dnode *temp;
	if(start==NULL)
		printf("Empty list\n");
	else
	{
		temp=start;
		while(temp->right!=NULL)
			temp=temp->right;
		if(start==temp)//single node
			start=NULL;
		else
			(temp->left)->right = NULL;
		printf("Deleted node value is %d\n",temp->info);
		free(temp);			
	}
}
void display()
{
	int c=0;
	dnode *temp=start;
	if(start==NULL)
		printf("\n Empty list");
	else
	{
		printf("\n The details are");
		while(temp!=NULL)
		{
			printf("\n%d\t%s\t%s\t%s\t%d\t%s\t",temp->ssn,temp->name,temp->desg,
temp->dept,temp->sal,temp->phno);
			c++;
			temp=temp->right;
		}
		printf("\n Number of nodes is %d",c);
	}
}
int main()
{
	int n,m,i;
	while(1)
	{
		printf("\n Enter 1:create list\n 2:insert_front\n 3:insert_end\n4:delete_front\n 5:delete_end\n 6:traverse");
		scanf("%d",&m);
		switch(m)
		{
			case 1: printf("\n Enter n");
				   	scanf("%d",&n);
		 		   	for(i=0;i<n;i++)
				   	insert_end();
					break;
			case 2: insert_front();break;
			case 3: insert_end();break;
			case 4: delete_front();break;
			case 5: delete_end();break;
			case 6:	display();break;
			default:exit(0);break;
		}
	}
	return 0;
}

