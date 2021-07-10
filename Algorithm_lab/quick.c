//Name:- Anjani kumari pandit
#include<stdio.h>
void quicksort(int A[],int lb,int ub);
int div(int A[],int lb,int ub);
void swap(int *i,int *j);
int main()
 {
   int A[20];
   int i,size,lb=0;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int ub=size-1;
    printf("Enter the elements to be sorted:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &A[i]);
    } 
   printf("\nBefore sorting  elements are:");
   for(i = 0; i< size; i++)
      printf("%d ", A[i]);
   quicksort(A, lb, ub); 
   printf("\nAfter quick sort elements are:");
   for(i = 0; i< size; i++)
      printf("%d ", A[i]); 
   return 0;
}

// Apply quick sort Algorithm

void quicksort(int A[],int lb,int ub)
{
	int pos;
	if(lb<ub){
		pos=div(A,lb,ub);
		quicksort( A, lb, pos-1);  
		quicksort( A, pos+1, ub);  
	}
}
// Division part of quick sort.


int div(int A[],int lb,int ub)
{
	int pivot=A[lb];
	int p=lb;
	int q=ub;
	while(p<q){
		while(A[p]<=pivot){
	    	p++;
		}
		while(A[q]>pivot){
	    	q--;
		}
		if(p<q)
			swap( &A[p],&A[q]);
	}
	swap(&A[lb],&A[q]);
	return q;
}
void swap(int *i,int *j)
{
	int temp=*i;
	*i=*j;
	*j=temp;
}



