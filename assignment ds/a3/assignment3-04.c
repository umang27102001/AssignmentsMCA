// Enrollment no: 22/10/JC/010

// Upload your file showing the following:                                                                                                                           
// i)Recursive implementation using C  to provide solution (with minimal number of disk moves) to the "Tower of Hanoi" problem with n number of disks (where the value of n is provided by the user as input).                                                                                                                                   ii) Show by simulating the call stack manually (for n=3) the stack frames used for every function call. 

#include<stdio.h>
void tower(int n,char A,char C,char B,int it){
    if(n==0){
        return;
    }
    tower(n-1,A,B,C,it-1);
    printf("Moving disc %d from tower %c to %c\n",it,A,C);
    tower(n-1,B,C,A,it-1);
}
int main(){

    int n;char A='A';char B='B';char C='C';
    printf("Enter the number of discs \n");
    scanf("%d",&n);
    tower(n,A,C,B,n);
    return 0;
}
// here's a simulation of the call stack for n = 3:

// tower_of_hanoi(3, 'A', 'C', 'B')

// n = 3
// from = 'A'
// to = 'C'
// aux = 'B'
// tower_of_hanoi(2, 'A', 'B', 'C')

// n = 2
// from = 'A'
// to = 'B'
// aux = 'C'
// tower_of_hanoi(1, 'A', 'C', 'B')

// n = 1
// from = 'A'
// to = 'C'
// aux = 'B'
// prints Move disk 1 from A to C
// Returns to tower_of_hanoi(2, 'A', 'B', 'C')

// tower_of_hanoi(1, 'C', 'B', 'A')

// n = 1
// from = 'C'
// to = 'B'
// aux = 'A'
// prints Move disk 1 from C to B
// Returns to tower_of_hanoi(2, 'A', 'B', 'C')

// prints Move disk 2 from A to B
// Returns to tower_of_hanoi(3, 'A', 'C', 'B')

// tower_of_hanoi(2, 'B', 'C', 'A')

// n = 2
// from = 'B'
// to = 'C'
// aux = 'A'
// tower_of_hanoi(1, 'B', 'A', 'C')

// n = 1
// from = 'B'
// to = 'A'
// aux = 'C'
// prints Move disk 1 from B to A
// Returns to tower_of_hanoi(2, 'B', 'C', 'A')

// tower_of_hanoi(1, 'C', 'A', 'B')

// n = 1
// from = 'C'
// to = 'A'
// aux = 'B'
// prints Move disk 1 from C to A
// Returns to tower_of_hanoi(2, 'B', 'C', 'A')

// prints Move disk 2 from B to C
// Returns to tower_of_hanoi(3, 'A', 'C', 'B')

// prints Move disk 3 from A to C
// Returns to main().