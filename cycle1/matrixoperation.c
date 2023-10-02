//add,multiply,display transpose of a matrix
#include<stdio.h>
#include<stdlib.h>
int a[50][50],b[50][50],i,j,n,m,p,q;
void add();
void multiply();
void transpose();
int main()
{
	int ch;
	printf("Enter the order of first matrix:");
	scanf("%d %d",&n,&m);
	printf("Enter the elements of the matrix:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Matrix 1 is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	

	printf("Enter the order of second matrix:");
	scanf("%d %d",&p,&q);
	printf("Enter the elements of the matrix:");
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}

	printf("Matrix 2 is:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	do
	{
	printf("\n1.Add\n2.Multiply\n3.Transpose\n4.Exit");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		add();
		break;
			
		case 2:
		multiply();
		break;
		
		case 3:
		transpose();
		break;
		
		case 4:
		exit(0);
		break;
		
		default:
		printf("Invalid choice");
	}
	}while(ch!=4);
}

void add(int c[50][50])
{	
	if(m==p and n==q)
	{
		printf("Sum of the matrix is:\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				c[i][j]=a[i][j]+b[i][j];
				printf("%d ",c[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("The matrix are not in the same size.Please try again!!");
	}
}
void multiply(int c[50][50])
{	
	printf("Product of the matrix is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			c[i][j]=a[i][j]*b[j][i];
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	
}
void transpose()
{
	printf("Transpose of the matrix 1 is:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[j][i]);
		}
		printf("\n");
	}
	printf("Transpose of the matrix 2 is:\n");
	for(i=0;i<q;i++)
	{
		for(j=0;j<p;j++)
		{
			printf("%d ",b[j][i]);
		}
		printf("\n");
	}
}