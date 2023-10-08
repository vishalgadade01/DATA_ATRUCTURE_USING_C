#include<stdio.h>
#include"Header.h"

void inproved_Bubble_sort(int a[],int n)
{
  int i,j,temp;
  int flag;

  for(i=(n-1);i>0;i--)
  {
  	flag=0;
     for(j=0;j<i;j++)
     {
     	if(a[j]>a[j+1])
     	{
     		flag=1;
     		temp=a[j];
     		a[j]=a[j+1];
     		a[j+1]=temp;
     	}

     }//J for loop
     printf("%d \n",i);

     if(flag==0)
     {
     	break;
     }

  }//i for loop

}





int main()
{
  int n;

  printf("Enter the size of array:");
  scanf("%d",&n);

  int *a;

  a=(int *)malloc(n*sizeof(int));

  if(a==NULL)
  {
    printf("Insuffisient memory !!!\n");
    exit(0);
  }

  Accept_array(a,n);

  printf("Before sorting: ");

  Display_array(a,n);

  inproved_Bubble_sort(a,n);

  printf("After sorting: ");

  Display_array(a,n);

  free(a);



	return 0;
}