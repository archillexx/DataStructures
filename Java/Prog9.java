//Prims Algorithm
import java.util.Scanner;
class mst
{
    void prim(int c[][], int n, int source)
    {
        int a=0, b=0, min, mincost=0, ne=0;
        int tvertex[] = new int[n];
        tvertex[source] = 1;
        while(ne<n-1)
        {
            min=999;
            for(int i=0;i<n;i++)
            {
                if(tvertex[i]==1)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(c[i][j]<min&&tvertex[j]==0)
                        {
                            min = c[i][j];
                            a=i;
                            b=j;
                        }
                    }
                }
            }
            System.out.println("edge from vertex" +a+ "to vertex" +b+ "and the cost is" +min);
            tvertex[b] = 1;
            ne++;
            mincost+=min;
        }
        System.out.println("The cost of min spanning tree: "+mincost);

    }
}


public class Prog9 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the no. of vertices: ");
        int n = s.nextInt();
        int c[][] = new int[n][n];
        System.out.println("Enter the matrix: ");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                c[i][j] = s.nextInt();
            }
        }
        System.out.println("Enter the source node: ");
        int source = s.nextInt();
        mst obj = new mst();
        obj.prim(c,n,source);

    }
}