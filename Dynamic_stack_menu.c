#include<stdio.h>
#include<stdlib.h>
#define NEWNODE (struct node*)malloc(sizeof(struct node))
#define BOTTOM NULL

struct node 
{
  struct node *prev;
  int data;
  struct node *next;
};

struct node *top;

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

void push(int data)
{
	struct node *t=NULL;

	t=NEWNODE;

	if(t==NULL)
	{
		printf("Stack is full..!!!\n");
		return;//For exiting from function
	}
	
	t->data=data;
	t->next=NULL;
	t->prev=NULL;

	if(top==BOTTOM)
	{
		top=t;
	}
	else
	{
		top->next=t;
		t->prev=top;
		t->next=NULL;
		top=t;
    
    }

    printf("\n[%d] pushed succesfully.\n",data);

}

int pop()
{
	struct node *t=NULL;
	int temp;

	temp=top->data;
	t=top;
	top=top->prev;
	free(t);

	if(top!=BOTTOM)
	{
		top->next=NULL;
	} 
	return temp;

}

int peek()
{
	return top->data;
}

void Display()
{
	struct node *head;
	head=top;
	while(head->prev!=NULL)
		head=head->prev;

	printf("\nYour data: ");
	while(head!=NULL)
	{
		printf(" %d ",head->data);
		head=head->next;
	}
	printf("\n");
}

int main()
{

	init();

	while(1)
	{
		int op;
  printf("\n ***************\n");
    printf(" *    MENU     *\n");
    printf(" ***************\n");
		printf(" * 0.Exit      *\n");
		printf(" * 1.push      *\n");
		printf(" * 2.pop       *\n");
		printf(" * 3.peek      *\n");
		printf(" * 4.Display   *\n");
	  printf(" ***************\n");	

		printf("\nEnter the option:");
		scanf("%d",&op);

		switch(op)
		{
			case 0:
			       exit(0);

			case 1:
			       printf("Enter the data:");
			       scanf("%d",&op);
			       push(op);
			       break; 

			case 2:
			      if(isempty())
			      {
			      	printf("\nStack is empty..!!!\n");
			      }
			      else
			      {
			      	printf("\nPoped elemet is [%d].\n",pop());
			      }
				  break;

		    case 3:
		           if(isempty())
		           {
		           	printf("\nStack is empty..!!!\n");
		           }
		           else
		           {
		           	printf("\nPeeked element is [%d].\n",peek());
		           }
		           break;

		    case 4:
		          if(isempty())
		          {
		          	printf("Stack is empty..!!!\n");
		          }
		          else
		          {
		           Display();       
		          }
		          break;

		    default:
		    
		            printf("Invalid option!!!!\n");       

		}//Switch
	}//While

	return 0;
}
