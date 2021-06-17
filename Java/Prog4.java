//QuickSort
import static java.util.Arrays.sort;
import java.util.Random;
import java.util.Scanner;
class sort
{
    static int count = 0;
    int partition(int a[], int low, int high)
    {
        int temp, i = low, j;
        int p = a[low];
        j = high+1;
        do
        {
            do
            {
                i++;
                count++;
            }while(i<=high&&a[i]<p);
            do
            {
                j--;
                count++;
            }while(j>=0&&a[j]>p);
            if(i<j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }while(i<j);
        
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;   
        return j;
    }
    void quicksort(int a[], int low, int high)
    {
        if(low<high)
        {
            int j = partition(a,low,high);
            quicksort(a,low,j-1);
            quicksort(a,j+1,high);
        }
    }
    
}


public class Prog4 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the no. of elements: ");
        int n = s.nextInt();
        int a[] = new int[1000];
        Random r = new Random();
        System.out.println("Enter the numbers to be sorted: ");
        for(int i=0;i<n;i++)
        {
            a[i] = r.nextInt(1000);
            System.out.print(a[i]+" ");
        }
        sort ob = new sort();
        ob.quicksort(a,0,n-1);
        System.out.println("The sorted array is: ");
        for(int i=0;i<n;i++)
        {
            System.out.print(a[i]+" ");
        }
        System.out.println("\n No.of basic operations: "+ob.count);
        
        
    }
    
}