#include<stdio.h>

#define SIZE 3
#define BOTTOM -1

int stack[SIZE];
int top;

void init()
{
    top=BOTTOM;
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

void push(int item)
{
    if(isfull())
    {
        printf("Stack is full!!\n");

    }
    else
    {
        top++;
        stack[top]=item;
    }
}

int pop()
{
    int temp;

    if(isempty())
    {
        printf("\nStack is empty\n");
        return -1;
    }
    else
    {
        temp=stack[top];
        top--;
        return temp;
    }
}

int peek()
{
    if(isempty())
    {
        printf("\nStack is empty!!!\n");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

int main()
{
    int item;
    init();

    push(11);
    push(22);
    push(33);
    push(44);
    push(55);

    item=peek();
    printf("%d ",item);

    item=peek();
    printf("%d ",item);

    
    item=pop();
    printf("%d ",item);

    item=pop();
    printf("%d ",item);

    item=pop();
    printf("%d ",item);

    item=pop();
    

    return 0;


}
