import java.util.PriorityQueue;

public class Fpp {
    public static class Node {
        int[][] matrix = new int[3][3];
        int row;
        int col;
        int h;
        Node parent;
        int level;

        Node(int[][] matrix, int row, int col, int h, Node parent, int level) {
            this.matrix = matrix;
            this.row = row;
            this.col = col;
            this.h = h;
            this.parent = parent;
            this.level = level;
        }

    }

    public static int findCost(int[][] initialState, int[][] goalState) {
        int h = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (initialState[i][j] != 0 && initialState[i][j] != goalState[i][j]) {
                    h++;
                }
            }
        }
        return h;
    }

    public static void swap(int[][] matrix, int row, int col, int r, int c) {
        int temp = matrix[row][col];
        matrix[row][col] = matrix[r][c];
        matrix[r][c] =temp;
    }

    public static Node createNode(Node currentNode, int goalState[][],int cRow, int cCol, int nRow, int nCol, int level) {
        int newMatrix[][] = new int[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                newMatrix[i][j] = currentNode.matrix[i][j];
            }
        }
        swap(newMatrix, cRow, cCol, nRow, nCol);
        int h=findCost(newMatrix, goalState);
        Node newNode=new Node(newMatrix,nRow,nCol,h,currentNode,level+1);
        return newNode;
    }
    public static void printMat(int[][]matrix){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
            {
                System.out.print(matrix[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void printStates(Node node){
        if(node==null) return;
        printStates(node.parent);
        printMat(node.matrix);
        System.out.println();
    }
    public static void solve(int[][] initialState, int[][] goalState, int row, int col) {
        PriorityQueue<Node> pq = new PriorityQueue<>((x, y) -> (x.h + x.level) - (y.h + y.level));
        int h = findCost(initialState, goalState);
        pq.add(new Node(initialState, row, col, h, null, 0));
        while (!pq.isEmpty()) {
            Node  currentNode=pq.poll();
            int currentRow = currentNode.row;
            int currentCol = currentNode.col;
            int currentH = currentNode.h;
            int level = currentNode.level;
            if(currentH==0){
                printStates(currentNode);
                break;
            }
            int[] delRow = { -1, 0, 1, 0 };
            int[] delCol = { 0, 1, 0, -1 };
            for (int i = 0; i < 4; i++) {
                int nrow = currentRow + delRow[i];
                int ncol = currentCol + delCol[i];
                if (nrow >= 0 && nrow < 3 && ncol >= 0 && ncol < 3) {
                    Node temp = createNode(currentNode, goalState,currentRow, currentCol, nrow, ncol, level);
                    pq.add(temp);
                }
            }

        }
    }

    public static void main(String[] args) {
        int[][] initialState = { { 1, 2, 3 }, { 0, 4, 6 }, { 7, 5, 8 } };
        int[][] goalState = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } };
        solve(initialState, goalState, 1, 0);
    }
}
