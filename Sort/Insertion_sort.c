#include<stdio.h>
#include"Header.h"

void Insertion_sort(int a[],int n)
{
	int i,j;
	int t;

	for(i=1;i<n;i++)
	{
		t=a[i];

		for(j=i-1;j>=0;j--)
		{
			if(a[j]>t)
			{
				a[j+1]=a[j];
			}
			else 
				break;
		}
		a[j+1]=t;
	}
}

int main()
{
  int n;

  printf("How amny number's do you want to  sort:");
  scanf("%d",&n);

  int *a;

  a=(int *)malloc(n*sizeof(int));

  if(a==NULL)
  {
  	printf("Insufficent memory\n");
  	exit(0);
  }

  Accept_array(a,n);

  printf("Your arry before sort:");

  Display_array(a,n);

  Insertion_sort(a,n);

  printf("After insertion sort:");

  Display_array(a,n);

  free(a);

  return 0;
}