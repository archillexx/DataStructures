//Stack Operations

#include<stdio.h>
#define Max 5
int stack[Max], top = -1;
void push(int item) {
  if (top == Max - 1)
    printf("Stack overflow\n");
  else
    stack[++top] = item;
}
int pop() {
  if (top == -1)
    printf("Stack Underflow\n");
  else
    return (stack[top--]);
}
void display() {
  int i;
  if (top == -1)
    printf("Stack Underflow\n");
  else
    for (i = top; i >= 0; i--)
      printf("%d\n", stack[i]);
}
void palindrome(int num) {
  int temp = num, rem;
  top = -1;
  while (temp > 0) {
    rem = temp % 10;
    temp = temp / 10;
    push(rem);
  }
  while (num > 0) {
    rem = num % 10;
    num = num / 10;
    if (rem != pop())
      break;
  }
  if (num == 0)
    printf("Given number is palindrome\n");
  else
    printf("Given number is not a palindrome\n");
}
int main() {
  int choice, num;
  while (1) {
    printf("1.Push\n2.Pop\n3.Display\n4.Palindrome\n5. Exit\nChoice:");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      printf("Enter a number:");
      scanf("%d", & num);
      push(num);
      break;
    case 2:
      num = pop();
      if (num = 0)
        printf("Popped num is %d\n", num);
      break;
    case 3:
      display();
      break;
    case 4:
      printf("Enter a num:");
      scanf("%d", & num);
      palindrome(num);
      break;
    case 5:
      return 0;
    default:
      printf("Wrong choice, try again\n");
    }
  }
}

