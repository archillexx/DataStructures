//Tower of Hanoi
#include<stdio.h>
int count=0;
void tower(int n,char S,char T,char D)
{
	if(n==1)
	{
		printf("\n Move Disc %d from %c to %c",n,S,D);
		count++;
	}
	else
	{
		tower(n-1,S,D,T);
		printf("\n Move Disc %d from %c to %c",n,S,D);
		count++;
		tower(n-1,T,S,D);
	}
}
int main()
{
	int n;
	printf("\n Enter number of disks");
	scanf("%d",&n);
	tower(n,'A','B','C');
	printf("\nNo. of Disc Moves =%d",count);
	return 0;
}
