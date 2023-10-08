#include<stdio.h>
#include"Header.h"

void Selection_sort(int a[],int n)
{
	int i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}

}

int main()
{
  int n;

  printf("How many number's do you want to sort:");
  scanf("%d",&n);

  int* a;

a=(int *)malloc(n*sizeof(int));

if(a==NULL)
{
	printf("Insufficent memmory!!!\n");
	exit(0);
}
  Accept_array(a,n);
  printf("Your number's before sort:");
  Display_array(a,n);

  Selection_sort(a,n);

  printf("After Selection sort:");

  Display_array(a,n);
  
  free(a);
  
  return 0;
}