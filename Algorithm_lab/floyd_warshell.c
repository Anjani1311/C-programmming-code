#include<stdio.h>
int i, j, k,n,A[10][10];
int main()
{
  int i,j;
  printf("Enter no of vertices :");
  scanf("%d",&n);
  printf("\n");
  for(i=0;i<n;i++)
  for(j=0;j<n;j++){
    printf("dist[%d][%d]:",i,j);
    scanf("%d",&A[i][j]);
   }
 floydWarshell();
 printf ("\n shortest distances between every pair of vertices \n");
 for ( i = 0; i < n; i++)
 {
  for ( j = 0; j < n; j++)
   printf ("%d\t", A[i][j]);
   printf("\n");
 }
 return 0;
}

void floydWarshell ()
{
 for (k = 0; k < n; k++)
  for (i = 0; i < n; i++)
   for (j = 0; j < n; j++)
    if (A[i][k] + A[k][j] < A[i][j])
     A[i][j] = A[i][k] + A[k][j];
}
