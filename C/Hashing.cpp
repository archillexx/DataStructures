//Hashing
#include<stdio.h>
#include<stdlib.h>
int L[100],max=10;
float A = 0.1352;
void display()
{
	int i;
	printf("\nHash Table contents are:");
	printf("\nIndex\tData\n");
	for(i=0;i<max;i++)
	    printf("\n%d\t%d\n",i,L[i]);
}

void linear_probe(int key, int num)
{
	int i;
	if(L[key]==-1)
	    L[key]=num;
	else
	{
		printf("\nCollision Detected");
		i=(key+1)%max;
		while(i!=key)
		{
			if(L[i]==-1)
			{
				L[i]=num;
				printf("\nCollision Resolved through Linear Probe");
				return;
			}
			else
			    i=(i+1)%max;
		}
		printf("\nHash Table is Full");
		display();
	}
}

int main()
{
	int i, num, addr, input;
	for(i=0;i<max;i++)
	    L[i]=-1;
	do
	{
		printf("\nEnter the Number: ");
		scanf("%d",&num);
		addr=num%max;
		printf("%d, %d",num, addr);
		linear_probe(addr, num);
		display();
		printf("\nEnter 1 to Continue: ");
		scanf("%d",&input);
	}while(input==1);
	return 0;
}
