//Polynomials
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct polynomial
{
	int cof, px, py, pz, add_flag;
	struct polynomial *link;
};

typedef struct polynomial poly;

poly *head1,*head2,*head3;


void build_poly(poly *head)
{
	poly *newnode;
	int n;
	printf("Enter no. of terms in the polynomial:");
	scanf("%d",&n);
	while(n!=0)
	{
		newnode=(poly*)malloc(sizeof(poly));
		printf("Enter coff,pow_x,pow_y,powz:");
		scanf("%d%d%d%d",&newnode->cof,&newnode->px,&newnode->py,&newnode->pz);
		newnode->add_flag=0;
		newnode->link = head->link;
		head->link = newnode;
		n--;		
	}
}

void display_poly(poly *head)
{
	poly *temp=head->link;
	while(temp!=head)
	{
		printf("(%dx^%dy^%dz^%d)",temp->cof,temp->px,temp->py,temp->pz);
		temp=temp->link;
		if(temp!=head)
			printf("+");
	}
}
void add_poly()
{
	poly *nn, *poly1, *poly2;
	for(poly1=head1->link;poly1!=head1;poly1=poly1->link)
	{
		nn=(poly*)malloc(sizeof(poly));
		*nn=*poly1;//copy term data into newnode
		for(poly2=head2->link;poly2!=head2;poly2=poly2->link)
		{
			if(poly2->add_flag ==0 && poly1->px==poly2->px && poly1->py==poly2->py && poly1->pz==poly2->pz)
			{
				nn->cof+=poly2->cof;
				poly2->add_flag = 1;
			}
		}
		nn->link=head3->link;
		head3->link = nn;		
	}
	//left out terms of polynomial 2
	for(poly2=head2->link;poly2!=head2;poly2=poly2->link)
	{
		if(poly2->add_flag==0)
		{
			nn=(poly*)malloc(sizeof(poly));
			*nn=*poly2;
			nn->link=head3->link;
			head3->link=nn;
		}
	}
}

int eval_poly(poly *head)
{
	poly *temp=head->link;
	int x, y, z;
	int sum=0;
	printf("Enter values of x, y, z:");
	scanf("%d%d%d",&x,&y,&z);
	while(temp!=head)
	{
		sum=sum+temp->cof*pow(x,temp->px)*pow(y,temp->py)*pow(z,temp->pz);
		temp=temp->link;
	}
	return sum;
}

int main()
{
	head1=(poly*)malloc(sizeof(poly));
	head1->link=head1;
	head2=(poly*)malloc(sizeof(poly));
	head2->link=head2;
	head3=(poly*)malloc(sizeof(poly));
	head3->link=head3;
	printf("Enter polynomial1\n");
	build_poly(head1);
	printf("Enter polynomial2\n");
	build_poly(head2);
	add_poly();
	printf("Polynomial 1 is:");
	display_poly(head1);
	printf("Polynomial 2 is:");
	display_poly(head2);
	printf("Result Polynomial is:");
	display_poly(head3);
	printf("The evaluated outcome = %d\n",eval_poly(head3));
}


