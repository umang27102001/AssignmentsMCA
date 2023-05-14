
def solve(sudoku):
    for i in range(0,9):
        for j in range(0,9):
            if(sudoku[i][j]==0):
                for k in range(1,10):
                    if isSafe(sudoku,i,j,k):
                        sudoku[i][j]=k
                        if solve(sudoku):
                            return True
                        sudoku[i][j]=0
                return False
    return True                

def isSafe(sudoku,row,col,val):
    i=0
    r=int(row/3)
    c=int(col/3)
    while i<9:
        if sudoku[i][col]==val:
            return False
        if sudoku[row][i]==val:
            return False
        if sudoku[r*3+int(i/3)][c*3+int(i%3)]==val:
            return False
        i+=1
    return True    
sudoku = [
    [3, 0, 6, 5, 0, 8, 4, 0, 0],
    [5, 2, 0, 0, 0, 0, 0, 0, 0],
    [0, 8, 7, 0, 0, 0, 0, 3, 1],
    [0, 0, 3, 0, 1, 0, 0, 8, 0],
    [9, 0, 0, 8, 6, 3, 0, 0, 5],
    [0, 5, 0, 0, 9, 0, 6, 0, 0],
    [1, 3, 0, 0, 0, 0, 2, 5, 0],
    [0, 0, 0, 0, 0, 0, 0, 7, 4],
    [0, 0, 5, 2, 0, 6, 3, 0, 0]]

solve(sudoku)

for i in range (0,len(sudoku)):
            for j in range(0,len(sudoku)):
                print(sudoku[i][j],end=" ")
            print()
        
