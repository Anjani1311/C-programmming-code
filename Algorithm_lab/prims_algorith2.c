#include<stdio.h>
#define Max 20
int problem_matrix[Max][Max],solution_matrix[Max][Max];
int prims(int no_of_node);
int check_visited_node_empty(int visited_node[],int no_of_node);
int check_visited_node( int visited_node[], int no_of_node,int j);
int main()
{
	int i,j,n,total_cost;
	printf("Enter no of vertices:");
	scanf("%d"  ,&n);
	printf("\nEnter the value of problem matrix:\n");
	for(i=1;i<=n;i++)
	{
		printf("%d    ",i);
	}
    printf("\n-------------------------------------\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		{
			scanf("%d",&problem_matrix[i][j]);
	    }
	    printf("\n");
    }
    
    prims(n);
    
}



int prims(int no_of_node)
{

	int i, r, j, k, visited_node[no_of_node];
	int new_min_path, from_node, to_node, current_path, total=0;
	for(i=0; i<no_of_node; i++){
		visited_node[i]=-1;
	}
	for(i=0; i<no_of_node; i++)
	{   
		if(check_visited_node_empty(visited_node,no_of_node)==1)
		{  
		    visited_node[i]=0;
		}
	    new_min_path=-1;
		from_node=-1;
		to_node=-1;
		for(k=0; visited_node[k]!=-1 && k<no_of_node; k++ )
		{  
			r=visited_node[k];
			for(j=0; j<no_of_node; j++)
			{    
				current_path=problem_matrix[r][j];
				if(new_min_path==-1){
					if(current_path!=-1){
						if(check_visited_node(visited_node,no_of_node,j)==1){
						
							new_min_path=current_path;
							from_node=r;
							to_node=j;
						}
					}
				}
				else 
				{
					if(new_min_path>current_path)
					{
						if(current_path!=-1)
						{
							if(check_visited_node(visited_node,no_of_node,j)==1)
							{  
								new_min_path=current_path;
								from_node=r;
							    to_node=j;
							   
						    }
						}
					}
				}
				
			}                                                                                                                                                                                    
		}
		visited_node[k]=to_node;
		solution_matrix[from_node][to_node]=new_min_path;
		
    }
    printf("solution matrix for problem matrix:\n");
    for(i=0; i<no_of_node; i++)
    {
    	for(j=0; j<no_of_node; j++)
    	{
    		printf("%d  ",solution_matrix[i][j]);
		}
		printf("\n");
	}
	for(i=0; i<no_of_node; i++)
    {
    	for(j=0; j<no_of_node; j++)
    	{
    		total=total+solution_matrix[i][j];
		}
	}
	printf("Total cost of spanning tree is %d.",total);
	
}

int check_visited_node_empty(int visited_node[],int no_of_node)
{
	if(visited_node[0]==-1)
	   return 1;
	else
	   return 0;
}
int check_visited_node( int visited_node[], int no_of_node,int j)
{
	int i;
	for(i=0; i<no_of_node; i++)
	{
	   if(visited_node[i]==j)
	       return 0;
	}
	return 1;
}

