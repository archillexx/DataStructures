//Evaluation of Postfix
#include<stdio.h>
#include<math.h>
#include<ctype.h>
int stack[30];
int top=-1;
void push(int ele)
{
	stack[++top]=ele;
}
int pop()
{
	return (stack[top--]);
}
int evaluate(int a, char op, int b)
{
	switch(op)
	{
		case '+':return(a+b);
		case '-':return(a-b);
		case '*':return(a*b);
		case '/':return(a/b);
		case '%':return(a%b);
		case '^':return(pow(a,b));
	}
}
int main()
{
	char postfix[100];
	int i, op1, op2;
	printf("\n Enter the expression");
	scanf("%s",postfix);
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isdigit(postfix[i]))
			push(postfix[i]-'0');
		else
		{
			op2=pop();
			op1=pop();
			push(evaluate(op1,postfix[i],op2));
		}
	}
 	printf("Evaluated expression value is %d",pop());
}

