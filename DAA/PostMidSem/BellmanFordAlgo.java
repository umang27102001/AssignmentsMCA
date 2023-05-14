import java.util.*;

public class BellmanFordAlgo {
    public static void main(String[] args) {
        int V=6;
        int E[][]={{1,2,1},{1,3,2},{2,3,2},{2,4,5},{3,5,3},{4,5,4},{4,6,8},{5,6,1},{2,5,7},{3,4,6}};
        int dist[]=new int[V+1];
        int prev[]=new int[V+1];

        Arrays.fill(dist,(int)1e9);
        int src=1;
        prev[src]=-1;
        dist[src]=0;
        for(int i=0;i<V;i++){
            for(int[]it:E){
                if(dist[it[1]]>dist[it[0]]+it[2]){
                    dist[it[1]]=dist[it[0]]+it[2];
                    prev[it[1]]=it[0];
                }
            }
        }
        for(int it[]:E)
        {
            if(dist[it[1]]>dist[it[0]]+it[2]){
                System.out.println("Shortest Path not Possibl as Graph contains Negative Weight Cycle");
            }
        }
        for(int i=1;i<=V;i++){
            System.out.print(dist[i]+" ");
        }
        System.out.println();
        for(int i=2;i<=V;i++){
            System.out.print(prev[i]+" ");
        }
    }
}
