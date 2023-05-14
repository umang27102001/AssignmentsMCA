import java.util.*;

public class PrimsAlgo {
    public static class Tuple{
        int wt;
        int node;
        int prev;
        public Tuple(int wt,int node,int prev){
            this.wt=wt;
            this.node=node;
            this.prev=prev;
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
        PriorityQueue<Tuple>pq=new PriorityQueue<Tuple>((x,y)->x.wt-y.wt);
        ArrayList<ArrayList<Integer>>MST=new ArrayList<>();
        boolean[]vis=new boolean[V+1];
        int src=1;
        int mstWt=0;
        pq.add(new Tuple(0, src, -1));
        while(!pq.isEmpty()){
            int wt=pq.peek().wt;
            int node=pq.peek().node;
            int prev=pq.peek().prev;
            pq.poll();
            if(vis[node]) continue;
            if(prev!=-1){
                mstWt+=wt;
                ArrayList<Integer>al=new ArrayList<>();
                al.add(prev);
                al.add(node);
                MST.add(al);
            }
            vis[node]=true;
            for(ArrayList<Integer>al:adj.get(node)){
                int nbrNode=al.get(0);
                int nbrWt=al.get(1);
                if(!vis[nbrNode]){
                    pq.add(new Tuple(nbrWt, nbrNode, node));
                }
            }
        }
        System.out.println("The Weight of MST is: "+mstWt);
        System.out.println("\nEdges in MST:");
        for (ArrayList<Integer>al : MST) {
            System.out.print(al.get(0)+" ");
            System.out.println(al.get(1));

        }
    }  
}
