#include<stdio.h>
#include"Header.h"

void Merge(int a[],int lb,int mid,int ub)
{
	int i=lb;
	int j=mid+1;
	int k=lb;
	int temp[50];

	while(i<=mid&&j<=ub)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			i++;
			k++;
		}
		else
		{
			temp[k]=a[j];
			j++;
			k++;
		}
	}

	while(i<=mid)
	{
		temp[k]=a[i];
		i++;
		k++;
	}

	while(j<=ub)
	{
		temp[k]=a[j];
		j++;
		k++;
	}
	for(k=lb;k<=ub;k++)
	{
		a[k]=temp[k];
	}
}

void Merge_sort(int a[],int lb,int ub)
{
	int mid;

	if(lb<ub)
	{
		mid=(lb+ub)/2;
		Merge_sort(a,lb,mid);
		Merge_sort(a,mid+1,ub);
		Merge(a,lb,mid,ub);
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

  Merge_sort(a,0,n-1);

  printf("After insertion sort:");

  Display_array(a,n);

  free(a);

  return 0;
}