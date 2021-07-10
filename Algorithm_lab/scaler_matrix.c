#include<stdio.h>
#include<limits.h>
 
int main()
{
	int n,i;
	printf("Enter number of matrices:");
	scanf("%d",&n);
	n++;
	int A[n];
	printf("\nEnter dimension :\n");
	for(i=0; i<n; i++)
	{
		printf("Enter %d:",i);
		scanf("%d",&A[i]);
	}
	int size=sizeof(A)/sizeof(A[0]);
	printf("Minimum number of muultiplication is %d.",matrix_chain_multiplication(A,size));
}

int matrix_chain_multiplication(int A[],int n)
{
	int m[n][n];
	int i,j,k,l,q,p;
	p=INT_MAX;
	for(i=1; i<n; i++)
	{
		m[i][i]=0;
	}
	for(l=2; l<n; l++)
	{
		for(i=1; i<n-l+1; i++)
		{
			j=i+l-1;
			m[i][j]=p;
			for(k=i; k<=j-1; k++)
			{
				q= ((m[i][k])+(m[k+1][j]) + A[i-1]*A[k]*A[j]);
				if(q<m[i][j])
				{
					m[i][j]=q;
				}
			}
		}
	}
	return m[1][n-1];
}
