//Exception Handling
import java.util.Scanner;
public class Prog3A{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a, b, result=0;
        System.out.println("Input of two numbers: ");
        a = s.nextInt();
        b = s.nextInt();
        try
        {
            result = a/b;
            System.out.println("Result is "+result);
        }
        catch(ArithmeticException e)
        {
            System.out.println("Divided by zero-impossible");
        }
 }
}