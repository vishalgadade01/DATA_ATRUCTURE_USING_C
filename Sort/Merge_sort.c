#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Accept(int [],int);//Function prototype OR Function Decleration
void Display(int [],int);
void Merge_sort(int [],int,int);
void Merge(int [],int,int,int);

void Accept(int a[],int n)
{
	int i;

	srand(time(NULL));

	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
	}
}

void Display(int a[],int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}

	printf("\n");
}

void Merge_sort(int a[],int lb,int ub)
{
	int mid;

	if(lb<ub)
	{
		mid=(lb+ub)/2;
		Merge_sort(a,lb,mid);//This function has recurssion.(calling it self);
		Merge_sort(a,mid+1,ub);
		Merge(a,lb,mid,ub);
	}
}

void Merge(int a[],int lb,int mid,int ub)
{
	int i=lb;
	int j=mid+1;
	int k=lb;
	int *temp;


	temp=(int *)malloc((ub+1)*sizeof(int));
     
     if(temp==NULL)
     {
     	printf("Insufficent memory !!!\n");
     	exit(0);
     }
	while(i<=mid&&j<=ub)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=a[j];
			k++;
			j++;
		}
	}

	while(i<=mid)
	{
		temp[k]=a[i];
		k++;
		i++;
	}

	while(j<=ub)
	{
		temp[k]=a[j];
		k++;
		j++;
	}

	for(k=lb;k<=ub;k++)
	{
		a[k]=temp[k];
	}
	free(temp);
}

int main()
{
	int n;

	printf("How many number's do you want to sort:");
	scanf("%d",&n);

	int  *a;

	a=(int *)malloc(sizeof(int));

	if(a==NULL)
	{
		printf(" Insufficent memory !!!!\n");
		exit(0);
	}

	Accept(a,n);

	printf("Before sorting:");

	Display(a,n);

	Merge_sort(a,0,n-1);

	printf("After Merge sort:");

	Display(a,n);

	free(a);

	return 0;
}