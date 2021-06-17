//Stacks
import java.util.Scanner;

class Stack{
    int a[];
    int top, max;
    Stack(int n)
    {
        max = n;
        a = new int[max];
        top = -1;
    }
    void push(int i)
    {
        if(top==max-1)
        {
            System.out.println("Stack overflow");
        }
        else {
            a[++top] = i;
        }
    }
    void pop()
    {
        if(top==-1)
        {
            System.out.println("Stack underflow");
        }
        else 
        {
            int ele = a[top--];
            System.out.println("popped element: "+ele);
        }
    }
    void display()
    {
        System.out.println("\nStack = ");
        if(top==-1)
        {
            System.out.println("The stack is empty...");
        }
        for(int i=top;i>=0;i--)
        {
            System.out.print(a[i]+" ");
        }
        System.out.println();
    }
}
public class Prog1b {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the size of the stack: ");
        int n = input.nextInt();
        boolean done = false;
        Stack stk = new Stack(n);
        do
        {
            System.out.println("Stack operations");
            System.out.println("1.push");
            System.out.println("2.pop");
            System.out.println("3.Display");
            System.out.println("Exit");
            System.out.println("Enter the choice: ");
            int choice = input.nextInt();
            switch(choice)
            {
                case 1: 
                    System.out.println("Enter elements to push: ");
                    stk.push(input.nextInt());
                    break;
                case 2: 
                    stk.pop();
                    break;
                case 3: 
                    stk.display();
                    break;
                case 4: 
                    done = true;
                    break;
                defalult:
                    System.out.println("Wrong Entry...");
                    break;
            }
        }while(!done);
        
   
}
    
}