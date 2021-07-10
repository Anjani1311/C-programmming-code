#include<stdio.h>
void max_min(int i, int j);
int max, min;
int a[50];

int main ()
{
 int i, num;
 printf ("\nEnter number of element in array: ");
 scanf ("%d",&num);
 printf ("Enter the elements: \n");
 for (i=1;i<=num;i++)
  scanf ("%d",&a[i]);
 max = a[0];
 min = a[0];
 max_min(1, num);
 printf ("Minimum element in array : %d\n", min);
 printf ("Maximum element in array : %d\n", max);
 return 0;
}

//select maximum and minimun in an array.

void max_min(int i, int j)
{
    int max1, min1, mid;
    if(i==j)//for only one element in array//
    {
        max = min = a[i];
    }
    else
    {
	   if(i == j-1)//for only two element in an array//
	   {
	        if(a[i] <a[j]){
	            max = a[j];
	            min = a[i];
	        }
	       else{
	            max = a[i];
	            min = a[j];
	        }
	    }
       else{
		   mid = (i+j)/2;
		   max_min(i, mid);
		   max1 = max; min1 = min;
		   max_min(mid+1, j);
		   if(max <max1)
		    max = max1;
		   if(min > min1)
		    min = min1;
		}
    }
}
