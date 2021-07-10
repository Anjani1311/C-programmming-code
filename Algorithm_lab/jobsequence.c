#include<stdio.h>
void  job_sequence( int num, float profit[],float deadline[],int max_deadline,int jobs[]);
void Descending_order(int num,float profit [], float deadline[],int jobs[]);
int max_deadline(float deadline[],int num);
int main()
{
	float  profit [10],deadline[10];
	int i,j,num,max;
	int jobs[10];
	printf("Enter number of jobs:");
	scanf("%d",&num);
	printf("\nEnter profit and deadline and job_number:\n");
	for(i=0; i< num; i++)
	{
		scanf(" %f %f %d",&profit [i],&deadline[i],&jobs[i]);
    }
    max=max_deadline( deadline, num); //calculate maximum deadline//
    printf("maximum deadline is %d.",max);
    
    Descending_order( num, profit ,deadline,jobs);//arrange profit in desending order//
    job_sequence(num,profit,deadline,max,jobs);//Apply job sequenece//
	                                                                                                                                                                                                                    
}

//max_deadline//

int max_deadline(float deadline[],int num)
{
	int i;
	int max=deadline[0];
	for(i=0; i<num; i++)
	{
		if(deadline[i]>max)
		{
			max=deadline[i];
		}
	}
	return max;
}

//Desending order//

void Descending_order(int num,float profit [], float deadline[],int jobs[] )
{
	int i,j,temp;
    for(i=0; i< num; i++)
    {
      for(j=i+1; j< num; j++)
      {
      	     if(profit [i] < profit [j])
      	     {
      	   	    temp=profit [i];
      	   	    profit [i]=profit [j];
      	   	    profit [j]=temp;
      	   	    
      	   	    temp=deadline[i];
      	   	    deadline[i]=deadline[j];
      	   	    deadline[j]=temp;
      	   	    
      	   	    temp=jobs[i];
      	   	    jobs[i]=jobs[j];
      	   	    jobs[j]=temp;
      	   	  
		     }
      
	   }
	}
	printf("\nprofit in desending order:");
	for(i=0; i<num; i++)
	{
		printf("%.2f  ",profit[i]);
	}	
}

//job sequence//


void  job_sequence( int num, float profit[],float deadline[],int max_deadline ,int jobs[])
{
	int out_array[10];
	int i,j,u;
	u=max_deadline;
	for(i=1; i<=u; i++)
	{
		out_array[i]=0.0;
	}
	
	for(i=0; i<num; i++)
	{
		for(j=deadline[i]; j>=1; j--)
		{
			if(out_array[j]==0.0)
			{
				out_array[j]=jobs[i];
				break;
			}
		}
	}
	
	printf("\norder of job sequence:");
	for(i=1; i<=u; i++)
	{
		printf("%d->",out_array[i]);
	}
}



