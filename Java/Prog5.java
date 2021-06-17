//Merge Sort
import java.util.Random;
import java.util.Scanner;
class msort
{
    static int count=0;
    void merge_sort(int a[], double n)
    {
        if(n>1)
        {
            int p = (int)Math.floor(n/2);
            int q = (int)Math.ceil(n/2);
            int b[] = new int[p];
            int c[] = new int[q];
            System.arraycopy(a,0,b,0,p);
            System.arraycopy(a,p,c,0,q);
            merge_sort(b,p);
            merge_sort(c,q);
            merge(b,c,a);
        }
    }
    void merge(int b[], int c[], int a[])
    {
        int i=0, j=0, k=0;
        int p = b.length;
        int q = c.length;
        while((i<p)&&(j<q))
        {
            count++;
            if(b[i]<=c[j])
                a[k++] = b[i++];
            else
                a[k++] = c[j++];
        }
        while(i<p)
            a[k++] = b[i++];
        while(j<q)
            a[k++] = c[j++];
    }
}


public class Prog5
{
    public static void main(String[] args)
    {
        int n;
        Scanner s = new Scanner(System.in);
        System.out.println("Input numbers: ");
        n = s.nextInt();
        int a[] = new int[n];
        Random r = new Random();
        for(int i=0;i<n;i++)
        {
            a[i] = r.nextInt(1000);
            System.out.print(a[i]+" ");
        }
        msort ob = new msort();
        ob.merge_sort(a,n);
        System.out.println("Sorted numbers: ");
        for(int i=0;i<n;i++)
        {
            System.out.println(a[i]);
        }
        System.out.println("No.of basic operation: "+ob.count);
    }
}