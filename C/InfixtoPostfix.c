//InfixtoPostfix
#include<stdio.h>
char stack[20];
int top=-1;
void push(char s)
{
	stack[++top]=s;
}
char pop()
{
	return stack[top--];
}
int precd(char s)
{
	switch(s)
	{
		case '^' : return 4;
		case '%' : case '*' : case '/' : return 3;
		case '+' : case '-' : return 2;
		case '(' : case ')' : case '#' : return 1;
	}
	return 0;
}

void in_to_post(char infix[20],char postfix[20])
{
	int i,k=0;
	char symbol,ch;
	push('#');
	for(i=0;infix[i]!='\0';i++)
	{
		symbol=infix[i];
		if(isalnum(symbol))
			postfix[k++]=symbol;
		else if(symbol=='(')
			push(symbol);
		else if(symbol==')')
			while((ch=pop())!='(')
				postfix[k++]=ch;
		else
		{
			while(precd(symbol)<=precd(stack[top]))
			postfix[k++]=pop();
		push(symbol);
		}
	}
	
	while(stack[top]!='#')
		postfix[k++]=pop();
	postfix[k]='\0';
}

int main()
{
	char infix[20],postfix[20];
	printf("\n Enter infix expression :");
	scanf("%s",infix);
	in_to_post(infix,postfix);
	printf("%s",postfix);
	return 0;
}
