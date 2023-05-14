import java.util.*;

public class KruskalAlgo {
    public static class DisjointSet{
       public ArrayList<Integer>parent=new ArrayList<>();
       public ArrayList<Integer>size=new ArrayList<>();
        public DisjointSet(int n){
            for(int i=0;i<=n;i++){
                parent.add(i);
                size.add(1);
            }
        }
        public int findPar(int n){
            if(parent.get(n)==n){
                return n;
            }
            int ulp=findPar(parent.get(n));
            parent.set(n,ulp);
            return ulp;
        }
        public void unionBySize(int u,int v){
            int ulp_u=findPar(u);
            int ulp_v=findPar(v);
            if(size.get(ulp_u)>size.get(ulp_v)){
                size.set(ulp_u,size.get(ulp_u)+1);
                parent.set(ulp_v,ulp_u);
            }
            else{
                size.set(ulp_v,size.get(ulp_v)+1);
                parent.set(ulp_u,ulp_v);
            }
        }
    }
    static class Edge implements Comparable<Edge>{
        int wt;int node;int nbr;
         Edge(int wt,int node,int nbr){
            this.wt=wt;this.node=node;this.nbr=nbr;
        }
        
        public int compareTo(Edge compare){
            return this.wt-compare.wt;
        }
    };
    public static void main(String[] args) {
        int V=6;
        int E[][]={{1,2,1},{1,3,2},{2,3,2},{2,4,5},{3,5,3},{4,5,4},{4,6,8},{5,6,1},{2,5,7},{3,4,6}};
        List<Edge>edj=new ArrayList<Edge>();
        for(int it[]:E){
            int wt=it[2];
            int node=it[0];
            int nbr=it[1];
            edj.add(new Edge(wt,node,nbr));
        }
        Collections.sort(edj);
        DisjointSet ds=new DisjointSet(V);
        int mstWt=0;
        ArrayList<ArrayList<Integer>>MST=new ArrayList<>();
        for(Edge it:edj){
            if(ds.findPar(it.node)!=ds.findPar(it.nbr)){
                ArrayList<Integer>al=new ArrayList<>();
                al.add(it.node);
                al.add(it.nbr);
                MST.add(al);
                mstWt+=it.wt;
                ds.unionBySize(it.node, it.nbr);
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
