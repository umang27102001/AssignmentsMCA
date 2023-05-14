import java.util.*;
public class DijkastraAlgo{
    public static class Pair{
        int dist;
        int node;
        public Pair(int dist,int node){
            this.dist=dist;
            this.node=node;
        }
    }
    public static void main(String[] args) {
        int V=6;
        int E[][]={{1,2,1},{1,3,2},{2,3,2},{2,4,5},{3,5,3},{4,5,4},{4,6,8},{5,6,1},{2,5,7},{3,4,6}};

        ArrayList<ArrayList<ArrayList<Integer>>>adj=new ArrayList<>();
        for(int i=0;i<=V;i++){
            adj.add(new ArrayList<>());
        }
        for(int[]it:E){
            ArrayList<Integer>al=new ArrayList<>();
            ArrayList<Integer>bl=new ArrayList<>();
            al.add(it[1]);
            al.add(it[2]);
            adj.get(it[0]).add(al);
            bl.add(it[0]);
            bl.add(it[2]);
            adj.get(it[1]).add(bl);
        }
       
        int dist[]=new int[V+1];
        int prev[]=new int[V+1];
        int src=1;
        Arrays.fill(dist,(int)1e9);
        PriorityQueue<Pair>pq=new PriorityQueue<Pair>((x,y)->x.dist-y.dist);
        pq.add(new Pair(0,src));
        dist[src]=0;
        prev[src]=-1;
        while(!pq.isEmpty()){
            int node=pq.peek().node;
            int dis=pq.peek().dist;
            pq.poll();

            for(ArrayList<Integer>al:adj.get(node)){
                int nbrNode=al.get(0);
                int nbrDist=al.get(1);
                if(dist[nbrNode]>dis+nbrDist){
                    dist[nbrNode]=dis+nbrDist;
                    prev[nbrNode]=node;
                    pq.add(new Pair(dist[nbrNode], nbrNode));
                }
            }
        }

        //Array containing shortest dist between soure and all other nodes
        for(int i=1;i<=V;i++){
            System.out.print(dist[i]+" ");
        }
        //Array containing shortest path between soure and all other nodes
        System.out.println();
        for(int i=2;i<=V;i++){
            System.out.print(prev[i]+" ");
        }
    }
}