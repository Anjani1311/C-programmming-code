#include<stdio.h>
#include<stdlib.h>
int try_placing_queens(int n);
int is_safe(int i,int j, int n);
int *placed_queen;
int no_of_placed_queens=0;
int main()
{
	int n;
	int i;
	printf("Enter the value of Queens:");
	scanf("%d",&n);
	placed_queen=(int*)malloc(n * 2 * sizeof(int));
	for(i=0; i<n; ++i)
	{
	    *(placed_queen+i*2+0)=-1;
	    *(placed_queen+i*2+1)=-1;
		
	}
	
	printf("solution of %d queen:",n);
	if(try_placing_queens(n)==0)
	{
		for(i=0; i<n; i++)
		{
			printf("\nQueen %d : %d ,%d",(i+1),*(placed_queen+i*2+0),*(placed_queen+i*2+1));
		}
	}
	else
	{
		printf("\nsolution is not fond.");
	}
	
	return 1;
}

// Try to place queens.

int try_placing_queens(int n)
{
	int i,j;
	if(no_of_placed_queens==n)
	{
		return 0;
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(is_safe(i,j,n )==0)
			{
			  *(placed_queen+no_of_placed_queens*2+0)=i;
			  *(placed_queen+no_of_placed_queens*2+1)=j;
		      no_of_placed_queens++;
			  if(try_placing_queens(n)==0)
			  {
			  	return 0;
			  }	
			  else
			  {
			  	  *(placed_queen+(no_of_placed_queens-1)*2+0)=-1;
			  	  *(placed_queen+(no_of_placed_queens-1)*2+1)=-1;
			  	  no_of_placed_queens--;
			  }
			}
		}
	}
	return 1;
}

// check the postions for queens that the postion is safe or not.

 int is_safe(int row,int col,int n)
{
 	int i;
 	for(i=0; i<n; i++)
 	{
 		if(row==*(placed_queen+i*2+0))
	    {
	    	return 1;
		}
		if(col==*(placed_queen+i*2+1)) 
		{
	    	return 1;
		}
		if((row-col)==(*(placed_queen+i*2+0)- *(placed_queen+i*2+1))) 
		{
	    	return 1;
		}
		if((row+col)==(*(placed_queen+i*2+0)+*(placed_queen+i*2+1)))
		{
	    	return 1;
		}
    } 
    return 0;
 }

