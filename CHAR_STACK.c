
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 20
#define BOTTOM -1

char stack[3][SIZE];
int top;
char  *temp[15];

void init()
{
	top=BOTTOM;
}

int isfull()
{
	if(top==SIZE-1)
	{
		return 1;
	}
	else
	{
	return 0;
	} 
}

int isempty()
{
	if(top==BOTTOM)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(char item[])
{
	if(isfull())
	{
		printf("Stack is full!!!\n");
	}
	else
	{
		top++;
		strcpy(stack[top],item);
    }

}

void pop()
{
	
	if(isempty())
	{
		printf("Stack is empty!!!\n");
		
	}
	else
	{
		strcpy(temp,stack[top]);
		top--;
	}
	
	  

} 

void peek()
{
	
	if(isempty())
	{
		printf("Stack is empty!!!\n");
		
	}
	else
	{
		strcpy(temp,stack[top]);
		

	}
}

int main()
{
	

	push("vishal");
	push("Gadade");
	
	pop();

	printf("poped element: %s \n",temp);

	pop();
	printf("poped element: %s \n",temp);

	pop();
	printf("poped element: %s \n",temp);
	pop();
	
	
	
	
}