#include<stdio.h>
void binary_search(int A[],int first,int last,int key , int num);
void Descending_order(int A[],int num);
void Ascending_order(int A[],int num);
int is_array_sorted(int A[],int num);
int main()
{
   int A[10];
   int i,num,key,first,last,temp,j,order;
   printf("Enter the number of elements: ");
   scanf("%d", &num);
   printf("\nEnter the elements:\n");
   for (i = 0; i < num; i++)
   {
        scanf("%d", &A[i]);
    } 
    is_array_sorted(A,num);//check array is sorted or not//
    first=0;
    last=num-1;
    printf("\nEnter searching element: ");
    scanf("%d", &key);
    printf("\nfor Accending order press '1' and for desending order press '0':");
    scanf("%d", &order);
    switch(order)
    {
    	case 0:Descending_order(A,num);
    	       binary_search(A,first,last,key,num);
    	       break;
    	case 1:Ascending_order(A,num);
    	       binary_search(A,first,last,key,num);
    	       break;
    	default:printf("\nyou have enter wrong input.");
	}
    
}

//Desending order//

void Descending_order(int A[],int num)
{ 
  int i,j,temp;
  for(i=0; i< num; i++)
    {
      for(j=i+1; j< num; j++)
      {
      	     if(A[i] < A[j])
      	     {
      	   	    temp=A[i];
      	   	    A[i]=A[j];
      	   	    A[j]=temp;
      	   	    
		     }
      
	   }
	}
	printf("Descending order:");
	for(i=0; i<num; i++)
	{
		printf("%d ",A[i]);
	}	
}

//Assesnding order//

void Ascending_order(int A[],int num)
{
   int i,j,temp	;
   for(i=0; i< num; i++)
    {
      for(j=i+1; j< num; j++)
      {
      	     if(A[i] > A[j])
      	     {
      	   	    temp=A[i];
      	   	    A[i]=A[j];
      	   	    A[j]=temp;
      	   	    
		     }
      
	   }
	}
	printf("Ascending order:");
	for(i=0; i<num; i++)
	{
		printf("%d ",A[i]);
	}	
}

//check element is in asending order or desending order//

int is_array_sorted(int A[],int num)
{
	int a=1,b=1,i=0;
	while((a==1 || b==1) && i<num-1)
	{
		if(A[i]<A[i+1])
		   b=0;
		else if(A[i]>A[i+1])
		   a=0;
		i++;
	}
	if(a==1)
		return 0;//Ascending order//
	else if(b==1)
	    return 1;//desending order//
	else
	    printf("\nyou have enter wrong order.\n");
}

//Apply binary search//

void binary_search(int A[],int first,int last,int key, int num)
{
	int middle;
	int check;
	check=is_array_sorted(A,num); //Assign value return by is_array_sorted//
	while(first<=last)
	{
		middle=(first+last)/2;
		if(check==0){
			if(A[middle]==key) {
			    printf("\nElement is present at index %d.",middle);
		       	break;
		    }
	 	    else if(A[middle]<key)//check in desending order//
		   {
		    	first=middle+1;
	    	}
	     	else
	     	{
		 	    last=middle-1;
		    }
		}
		else if(check==1){
			if(A[middle]==key){
			    printf("\nElement is present at index %d.",middle);
		       	break;
		    }
	 	    else if(A[middle]>key)//check in assending order//
		   {
		    	first=middle+1;
	    	}
	     	else
	     	  last=middle-1;

		}
	}
	if(first>last){
		printf("\nElement is not found in array.");//Element is not in array//
	}
	
}

