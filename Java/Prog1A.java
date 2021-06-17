//Students
import java.util.Scanner;
class Student
{
    String USN, Name, Prog, Phone;
    Scanner input = new Scanner(System.in);
    void read()
    {
        System.out.println("Enter the USN: ");  
        USN = input.nextLine();
        System.out.println("Enter the Name: ");
        Name = input.nextLine();
        System.out.println("Enter the Prog: ");
        Prog = input.nextLine();
        System.out.println("Enter the Phone number: ");
        Phone = input.nextLine();
    }
    void display()
    {
        System.out.println(USN+"\t\t"+Name+"\t\t"+Prog+"\t\t"+Phone);
    }
}
public class Prog1A {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the number of students: ");
        int n = input.nextInt();
        Student s[] = new Student[n];
        for(int i=0;i<n;i++){
            s[i] = new Student();
            s[i].read();
        }
        System.out.println("USN"+"\t\t"+"NAME"+"\t\t"+"PROG"+"\t\t"+"PHONE");
        int i;
        for(i=0;i<n;i++){
            s[i].display();
        }
}