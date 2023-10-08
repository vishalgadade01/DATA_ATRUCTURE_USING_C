#include<time.h>
#include<stdlib.h>

void Accept_array(int [],int);//Function prototype /function declearation
void Display_array(int [],int);

void Accept_array(int a[],int n)
{
	srand(time(NULL));

	for(int i=0;i<n;i++)
	{
	a[i]=rand()%100;
    }
}

void Display_array(int a[],int n)
{
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}

	printf("\n");
}