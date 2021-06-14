//Binary Search Tree
#include<stdio.h>
#include<stdlib.h>
struct Tree
{
	int info;
	struct Tree *left,*right;
};
typedef struct Tree tnode;
tnode *root=NULL;
tnode* getnode()
{
	tnode *newnode;
	newnode=(tnode*)malloc(sizeof(tnode));
	printf("\n Enter the value");
	scanf("%d",&newnode->info);
	newnode->left=newnode->right=NULL;
	return(newnode);
}
void insert()
{
	tnode *nn,*temp=root,*prev;	
	nn=getnode();
	if(root==NULL)
		root=nn;
	else
	{
		while(temp!=NULL)
		{
			prev=temp;
			if(nn->info < temp->info)
				temp=temp->left;
			else
				temp=temp->right;
		}
		if(nn->info < prev->info)
			prev->left=nn;
		else
			prev->right=nn;
	}
}
void inorder(tnode *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->info);
		inorder(root->right);
	}
}
void preorder(tnode *root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->info);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(tnode *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->info);
	}
}


int search(int key)
{
	tnode *temp=root;

	while(temp!=NULL)
	{
		if(key==temp->info)
			return 1;
		else if(key<temp->info)
			temp=temp->left;
		else
			temp=temp->right;
	}
	return 0;
}

int main()
{
	int ch,key,n,i;
	while(1)
	{
		printf("\n Enter\n 1:insert\t 2:traverse\t 3:search\t 4:exit\t : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter no of terms");
				   	scanf("%d",&n);
				   	for(i=0;i<n;i++)
				  		insert();
				 	break;
			case 2:	if(root==NULL)
						printf("\n Tree empty");
				   	else
				  	{
						printf("\nInorder traversal:\t");
						inorder(root);
						printf("\nPreorder traversal:\t");
						preorder(root);
						printf("\nPostorder traversal:\t");
						postorder(root);
					}
					break;
					
			case 3: printf("\n Enter the key");
					scanf("%d",&key);
					if(search(key))
						printf("Search is successful");
					else
						printf("Search is unsuccessful");
				  	break;
				  	
			case 4:	return 0;
		}
	}
}
