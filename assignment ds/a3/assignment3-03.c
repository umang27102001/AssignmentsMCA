// Enrollment no: 22/10/JC/010

// Sparse Matrix

#include<stdio.h>
int main()
{
int X[10][3],Y[3][10],Z[10][10],r1,c1,nz1,r2,c2,nz2,i,j,k,c=0,v=0,r3,c3,temp;
int x[10][3]={0};
int y[10][3]={0};
int z[10][3]={0};

//ri=number of rows in ith matrix
//ci=number of columns in ith matrix
//nzi=non zero elements
//Initialising the Matrices to 0
printf("Enter the Rows,Columns and Number of Non-Zero Elements of Matrix 1\n");
scanf("%d %d %d",&r1,&c1,&nz1);
X[0][0]=r1;
X[0][1]=c1;
X[0][2]=nz1;
for(i=1;i<=nz1;i++)
{
	printf("Enter the Rows Position,Column Position and Non Zero Value\n");
	for(j=0;j<3;j++)
	{
		scanf("%d",&X[i][j]);
	}
}
for(i=1;i<=nz1;i++)
{
	
		x[X[i][0]][X[i][1]]=X[i][2];
}
//Matrix 2
printf("Enter the Rows,Columns and Number of Non-Zero Elements of Matrix 2\n");
scanf("%d %d %d",&r2,&c2,&nz2);
Y[0][0]=r2;
Y[0][1]=c2;
Y[0][2]=nz2;
for(i=1;i<=nz2;i++)
{
	printf("Enter the Rows Position,Column Position and Non Zero Value\n");
	for(j=0;j<3;j++)
	{
		scanf("%d",&Y[i][j]);
	}
}
for(i=1;i<=nz2;i++)
{
	
		y[Y[i][0]][Y[i][1]]=Y[i][2];
}

printf("\nMATRIX X in (0:t,0:2)Form\n");
for(i=0;i<=nz1;i++)
{
	for(j=0;j<3;j++)
	printf("%d",X[i][j]);
	printf("\n");
}

printf("\nMATRIX Y (0:t,0:2)Form\n");
for(i=0;i<=nz1;i++)
{
	for(j=0;j<3;j++)
	printf("%d",Y[i][j]);
	printf("\n");
}
//Matrix B Ends



//Multiplication
if(X[0][1]!=Y[0][0])
{
	printf("The Multiplication is Not Possible\n");
}
else
{
	for ( i = 0; i < r1; i++) {
        for ( j = 0; j < c2; j++) {
            z[i][j] = 0;
 
            for (k = 0; k < r2; k++)
			 {
			 	if(x[i][k]!=0&&y[k][j]!=0)
			 	{
                z[i][j] += x[i][k] * y[k][j];
            }
            }
        }
    }
	

r3=X[0][0];
c3=Y[0][1];
Z[0][0]=r3;
Z[0][1]=c3;
c++;
for(i=0;i<r2;i++)
{
	for(j=0;j<c2;j++)
	{
		if(z[i][j]!=0)
		{
			v++;
		Z[c][0]=i;
		Z[c][1]=j;
		Z[c][2]=z[i][j];
		c++;	
	}
	}	
}
Z[0][2]=v;

printf("\n MATRIX Z (0:t,0:2)Form\n");
for(i=0;i<=v;i++)
{
	for(j=0;j<3;j++)
	printf("%d",Z[i][j]);
	printf("\n");
}

for(i=1;i<=v;i++)
{
	
		z[Z[i][0]][Z[i][1]]=Z[i][2];
}
//Matrix B Ends
// Matrix A Output

printf("\nMATRIX A \n");
for(i=0;i<r1;i++)
{
	for(j=0;j<c1;j++)
	printf("%d",x[i][j]);
	printf("\n");
}
//Matrix B Output 
printf("\n MATRIX B\n");
for(i=0;i<r2;i++)
{
	for(j=0;j<c2;j++)
	printf("%d",y[i][j]);
	printf("\n");
}
printf("\n MATRIX C\n");
for(i=0;i<r2;i++)
{
	for(j=0;j<c2;j++)
	printf("%d",z[i][j]);
	printf("\n");
}

}
return 0;	
}