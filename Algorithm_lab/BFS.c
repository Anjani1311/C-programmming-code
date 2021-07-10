#include<stdio.h>
int G[30][30],solution_array[10],n,queue[10]; 
static rear=0,front=1;
int BFS(int start_node);
int check_node(int node);
int enqueue(int data);
int dequeue();
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
	BFS(start_node);
	printf("\nBFS of the graph is:");
	for(i=1; i<=n; i++)
	{
		printf("%d->",solution_array[i]);
	}
   return 0;
}

int BFS(int start_node)
{
	int p,i;
	enqueue(start_node);
	for(i=1; i<=n; i++)
	{
		p=dequeue();
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
				enqueue(i);
				continue;
			}
		}
		else
		{
			continue;
		}
	}
}

int enqueue(int data)
{
	rear=rear+1;
	queue[rear]=data;
}


int dequeue()
{
	int q;
	q=queue[front];
	front++;
	return q;
}

int is_safe1(int i)
{
	int j;
	for(j=1; j<n; j++)
	{
		if(queue[j]==i)
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









