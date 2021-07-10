#include<stdio.h>
void mergesort(int A[],int lb,int ub);
void merge(int A[],int lb,int mid,int ub);
int main()
 {
   int A[25];
   int i,size,lb=0,ub;
   printf("Enter the number of elements: ");
    scanf("%d", &size);
	ub=size-1; 
    printf("Enter the elements to be sorted:\n");
    for (i = 0; i <size; i++)
    {
        scanf("%d", &A[i]);
    } 
   printf("\nBefore sorting  elements are:");
   for(i = 0; i<size; i++)
      printf("%d ", A[i]);
    mergesort(A,lb,ub);
    printf("\nAfter merge sort elements are:");
   for(i = 0; i<size; i++)
      printf("%d ",A[i]); 
   return 0;
}

//Apply merge sort algorithm .

void mergesort(int A[],int lb,int ub)
{
	int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        mergesort(A,lb,mid);
        mergesort(A,mid+1,ub);
        merge(A,lb,mid,ub);
    }
    else
     return ;
    
}

//merging part.

 void merge(int A[],int low, int mid, int high) {
   int l1, l2, i;
   int b[10];

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(A[l1] <= A[l2])
         b[i] = A[l1++];
      else
         b[i] = A[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = A[l1++];

   while(l2 <= high)   
      b[i++] = A[l2++];

   for(i = low; i <= high; i++)
      A[i] = b[i];
}

