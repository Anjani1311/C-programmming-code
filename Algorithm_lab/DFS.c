#include<stdio.h>
int G[30][30],solution_array[10],n,stack[10]; 
static top=0;
int DFS(int start_node);
int check_node(int node);
int push(int data);
int pop();
int is_safe1(int i);
int is_safe2(int i);
int main()
{
	int i,j,start_node;
	printf("Enter no of vertices:");
	scanf("%d",&n);
	printf("Enter Adjecency Matrix:");
	for(i=1;i<=n;i++)
	{
		for( j=1;j<=n;j++)
			scanf("%d",&G[i][j]);
		solution_array[i]=0;
	}
	printf("\nEntered matrix is:\n");
	for( i=1;i <=n;i++)
	{
		for(j=1;j <=n;j++)
			printf("%d  ",G[i][j]);
		printf("\n");
	}
	printf("Enter starting node:");
	scanf("%d",&start_node);
	DFS(start_node);
	printf("\nDFS of the graph is:");
	for(i=1; i<=n; i++)
	{
		printf("%d->",solution_array[i]);
	}
   return 0;
}

int DFS(int start_node)
{
	int p,i;
	push(start_node);
	for(i=1; i<=n; i++)
	{
		p=pop();
		solution_array[i]=p;
		check_node(p);
	}
}

int check_node(int node)
{
	int i;
	for( i=1; i<=n; i++)
	{
		if(G[node][i]==1)
		{
			if(is_safe1(i)==1 || is_safe2(i)==1)
			{
				continue;
			}
			else{
				push(i);
				continue;
			}
		}
		else
		{
			continue;
		}
	}
}

int push(int data)
{
	top=top+1;
	stack[top]=data;
}


int pop()
{
	int q;
	q=stack[top];
	top--;
	return q;
}

int is_safe1(int i)
{
	int j;
	for(j=1; j<n; j++)
	{
		if(stack[j]==i)
		   return 1;
	}
	return 0;
}

int is_safe2(int i)
{
	int j;
	for(j=1; j<=n; j++)
	{
		if(solution_array[j]==i)
		   return 1;
	}
	return 0;
}









