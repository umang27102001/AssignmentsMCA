def solve(board,ind):
    if ind==len(board):
        for i in range (0,len(board)):
            for j in range(0,len(board)):
                print(board[i][j],end=" ")
            print()
        print()    
        return    
    for i in range(0,len(board)) :
        if isSafe(board,i,ind):
            board[i][ind]="Q"
            solve(board,ind+1)
            board[i][ind]="."

def isSafe(board,row,col):
    delRow=[-1,0,1]
    delCol=[-1,-1,-1]
    for i in range(0,3):
        nrow=row+delRow[i]
        ncol=col+delCol[i]
        while(nrow>=0 and nrow<len(board)and ncol>=0 and ncol<len(board)):
            if board[nrow][ncol]=="Q":
                return False
            nrow+=delRow[i]
            ncol+=delCol[i]
    return True            


n=6
board=[]
for i in range(0,n):
    a=[]
    for j in range(0,n):
        a.append(".")
    board.append(a)
solve(board,0)
