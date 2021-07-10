#include<stdio.h>
void  knapsack( int num, float weight[],float price[],float capacity);
void Descending_order(int num, float weight[],float price[], float ratio[]);
int main()
{
	float  weight[10],price[10],ratio[10],capacity,temp;
	int i,j,num;
	printf("Enter how many number of object available in market:");
	scanf("%d",&num);
	printf("\nEnter value of weight and price:\n");
	for(i=0; i< num; i++)
	{
		scanf(" %f %f",&weight[i],&price[i]);
    }
    printf("Enter capacity of the bag:");
    scanf("%f",&capacity);
    
    for(i=0; i< num; i++)
    {
      ratio[i]=price[i]/weight[i];
	}
	 printf("\nRatios are:");
	 for(i=0; i< num; i++)
    {
       printf("%.2f  ",ratio[i]);
	}
	
	Descending_order(num,weight,price, ratio);//Desending order//
	knapsack(num,weight,price,capacity);//Apply knapsack//
	                                                                                                                                                                                                                    
}

void   knapsack( int num, float weight[],float price[],float capacity)
{
	float x[10], tp=0;
	int i,j,u;
	u=capacity;
	
	for(i=0; i< num; i++)
	{
		x[i]=0.0;
	}
	
	for(i=0; i< num; i++)
	{
		if(weight[i]>=u)
		  break;
		else
		{
			x[i]=1.0;
			tp=tp+price[i];
			u=u-weight[i];
		}
	}
	if(i<num) //for choose last element in bag//
	{
		x[i]=u/weight[i];
		tp=tp+(x[i]*price[i]);
	}
	printf("\nmaximum profit:%f",tp);
	
	
}


void Descending_order(int num, float weight[],float price[], float ratio[])
{ 
  int i,j,temp;
  for(i=0; i< num; i++)
    {
      for(j=i+1; j< num; j++)
      {
      	     if(ratio[i] < ratio[j])
      	     {
      	   	    temp=ratio[i];
      	   	    ratio[i]=ratio[j];
      	   	    ratio[j]=temp;
      	   	    
      	   	    temp=weight[i];
      	   	    weight[i]=weight[j];
      	   	    weight[j]=temp;
      	   	    
      	   	    temp=price[i];
      	   	    price[i]=price[j];
      	   	    price[j]=temp;
      	   	
		     }
      
	   }
	}
	printf("\nratios in desending order:");
	for(i=0; i<num; i++)
	{
		printf("%.2f  ",ratio[i]);
	}	
}
