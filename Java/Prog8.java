//Kruskals Algorithm
import java.util.Scanner;
class Mstkruskal
{
    void kruskal(int cost[][],int n)
    {
        int par[] = new int[n];
        for(int i=0;i<n;i++)
            par[i] = -1;
        int a=0,b=0,u=0,v=0,min,mincost=0,ne=0;
        System.out.println("The MST edges are: ");
        while(ne < n-1)
        {
            min = 999;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(cost[i][j] < min)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
            while(par[u]!=-1)
                u=par[u];
            while(par[v]!=-1)
                v=par[v];
            if(u!=v)
            {
                System.out.println("From vertex "+a+" to vertex "+b+" and the cost: "+min);
                mincost += min;
                par[b]=a;
                ne++;
            }
            cost[a][b]=cost[b][a]=999;
        }
        System.out.println("Cost of MST: "+mincost);
    }
}

public class Prog8 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the number of vertices: ");
        int n = s.nextInt();
        int c[][] = new int[n][n];
        System.out.println("Enter the cost matrix: ");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                c[i][j] = s.nextInt();
                if(c[i][j]==0)
                {
                    c[i][j]=999;
                }
            }
        }
        Mstkruskal obj = new Mstkruskal();
        obj.kruskal(c,n);
    }
}