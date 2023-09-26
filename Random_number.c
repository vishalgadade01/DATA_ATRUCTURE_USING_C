#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Accept_aaray(int a[],int n)
{
	srand( time(NULL) );

	for(int  i=0;i<n;i++)
		{
			a[i]=rand()%10;


		}
}


void Display_array(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	int n;

	printf("How many number's do you want:");
	scanf("%d",&n);

	int a[n-1];

	Accept_aaray(a,n);

	printf("Your array is: ");

	Display_array(a,n);

	return 0;
}