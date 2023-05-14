public class FloydWarshalAlgo {
    public static void main(String[] args) {
        int[][] adj = {
                { 0, 5, 0, 10 },
                { 0, 0, 3, 0 },
                { 0, 0, 0, 1 },
                { 0, 0, 0, 0 } };
        
        for(int i=0;i<adj.length;i++){
            for(int j=0;j<adj[0].length;j++){
                if(i!=j&&adj[i][j]==0){
                    adj[i][j]=(int)1e9;
                }
            }
        }
        
        for(int k=0;k<adj.length;k++){
            for (int i = 0; i < adj.length; i++) {
                for (int j = 0; j < adj.length; j++) {
                    adj[i][j]=Math.min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        
        for(int i=0;i<adj.length;i++){
            for(int j=0;j<adj[0].length;j++){
                if(adj[i][j]==(int)1e9){
                    adj[i][j]=0;
                }
            }
        }
        for(int i=0;i<adj.length;i++){
            for(int j=0;j<adj[0].length;j++){
               System.out.print(adj[i][j]+" ");
            }
            System.out.println();
        }

    
    }
}
