#include<stdio.h>
#include<stdlib.h>
#define NEWNODE (struct node *)malloc(sizeof(struct node))

struct node 
{
  struct node *previous;
  int data;
  int priority;
  struct node *next;
};
struct node *front;
struct node *rear;

void init()
{
	front=rear=NULL;
}
int isempty()
{
	return front==NULL;
}

struct node* Add_New_Data_in_Queue(struct node *head,int data,int p)//for accepting data
{
	struct node* t=NULL;

t=NEWNODE;

if(t==NULL)
{
	printf("Insufficent memory..!!!\n");
	exit(0);
}

if(front==NULL)
{
	t->data=data;
	t->priority=p;
	t->next=front;
	t->previous=rear;
	front=t;
	rear=t;
	head=front;
	return head;

}
	

	t->data=data;
	t->priority=p;
	t->next=front;
	t->previous=rear;
	rear->next=t;
	front->previous=t;
	rear=rear->next;

	return head;
}

void Display(struct node *f)//For display data
{
	struct node *t=NULL;

	if(isempty())
	{
		printf("Queue is empty..!\n");
		return;
	}

	t=f;

	printf("\nYour data is in from of [data | priority] :{ ");
	if(rear==front)
	{
		printf("[%d | %d ] }.\n",t->data,t->priority); // if only one data is present in linked list.
		return;
	}

	do
	{
		printf("[%d | %d ]",t->data,t->priority);
		t=t->next;
		if(t!=f)
		{
			printf(",");
		}
		else
		{
			printf("}.");
		}

	}
	while(t!=f);
	printf("\n");

}

int Find_Maximum_Privority(struct node *f)//Fro finding max data
{
	struct node *t=NULL;
	t=f;

	int maximum=t->priority;
	t=t->next;

	while(t!=f)
	{
      if(maximum<t->priority)
      {
      	
      	 maximum = t->priority;

      }
      t=t->next;
	}
	

	return maximum;

}

struct node* Delete_Maximum_priority(struct node *f)
{
    struct node *t = NULL;
    struct node *del = NULL;

    if(rear==front)//if only one data is present
    {
    	printf("[%d] data is Deleted.!\n",rear->data);
    	free(rear);
    	init();
    	return NULL;
    }

  

    t = f;

    int Maximum_priority = Find_Maximum_Privority(t);
    printf("Maximum_priority is: [%d].\n", Maximum_priority);

   
    t=t->next;

    while(t!=rear)
    {
    	if(Maximum_priority==t->priority)
    	{
    		del=t;
    		t->previous->next=t->next;
    		t->next->previous=t->previous;
    		printf("[%d] data is Deleted.!\n",del->data);
    	 free(del);
      }
      t=t->next;
    	
    }//While loop

    

    if(Maximum_priority==front->priority)//Deleting first
    {
    	del=front;
    	front=front->next;
    	front->previous=rear;
    	rear->next=front;
    	f=front;

    	printf("[%d] data is Deleted.!\n",del->data);
    	free(del);
    } 

    if(rear==front && front->priority==Maximum_priority)// if Both are at same node and  
    {                                                  //Max is found in that place
    	printf("[%d] data is Deleted.!\n",rear->data);
    	free(rear);
    	init();
    	return NULL;
    }

    if(Maximum_priority==rear->priority) // Deleting last
    {
    	del=rear;
    	rear=rear->previous;
    	rear->next=front;
    	front->previous=rear;
    	printf("[%d] data is Deleted.!\n",del->data);
    	free(del);
    }

    
    return f;
}


int peek_Q()
{
	if(rear==NULL)
	{
		printf("Queue is empty..!!\n");
		return -1;
	}
	else
	{
		return rear->data;
	}
}



int main()
{
	int p,data;
	init();
	struct node *head=NULL;	
	

int op;

 while(1)
  {
    printf("*************\n");
    printf("* 0.Exit    *\n");
    printf("* 1.Push    *\n");
    printf("* 2.Delete  *\n");
    printf("* 3.peek    *\n");
    printf("* 4.Display *\n");
    printf("*************\n");

    printf("Enter the option:");
    scanf("%d",&op);

    switch(op)
    {
      case 0:
            
            exit(0);

      case 1:
           
            printf("Enter the data:");
            scanf("%d",&data);
            printf("Enter the priority:");
            scanf("%d",&p);
            head=Add_New_Data_in_Queue(head,data,p);
          

            break;
       case 2:
            if(isempty())
            {
              printf("Queue is empty.!!!\n");
            }
            else
            {
              head=Delete_Maximum_priority(head);

            }
            break;

      case 3:
            if(isempty())
            {
              printf("Queue is empty!!!\n");
            }
            else
            {
              printf("Peeked element is: %d.\n",peek_Q());

            }

            break; 
      
      case 4:
            if(isempty())
            {
              printf("Queue is empty!!!\n");
            }
            else
            {
             Display(head);
            }

            break;


      default :
            
            printf("Invalid option..!!\n");                        
    }

  }
}


/* 

OUTPUT:


E:\DS (TCA)\Queue>gcc Delete_Maximum_Priority_first.c

E:\DS (TCA)\Queue>a.exe
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:1
Enter the data:1
Enter the priority:0
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:2
[1] data is Deleted.!
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:1
Enter the data:4
Enter the priority:3
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:1
Enter the data:55
Enter the priority:9
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:1
Enter the data:66
Enter the priority:2
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:1
Enter the data:99
Enter the priority:10
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:1
Enter the data:100
Enter the priority:15
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:4

Your data is in from of [data | priority] :{ [4 | 3 ],[55 | 9 ],[66 | 2 ],[99 | 10 ],[100 | 15 ]}.
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:3
Peeked element is: 100.
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:2
Maximum_priority is: [15].
[100] data is Deleted.!
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:4

Your data is in from of [data | priority] :{ [4 | 3 ],[55 | 9 ],[66 | 2 ],[99 | 10 ]}.
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:2
Maximum_priority is: [10].
[99] data is Deleted.!
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:4

Your data is in from of [data | priority] :{ [4 | 3 ],[55 | 9 ],[66 | 2 ]}.
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:1
Enter the data:33
Enter the priority:4
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:4

Your data is in from of [data | priority] :{ [4 | 3 ],[55 | 9 ],[66 | 2 ],[33 | 4 ]}.
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:3
Peeked element is: 33.
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:2
Maximum_priority is: [9].
[55] data is Deleted.!
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:2
Maximum_priority is: [4].
[33] data is Deleted.!
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:4

Your data is in from of [data | priority] :{ [4 | 3 ],[66 | 2 ]}.
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:2
Maximum_priority is: [3].
[4] data is Deleted.!
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:3
Peeked element is: 66.
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:4

Your data is in from of [data | priority] :{ [66 | 2 ] }.
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:2
[66] data is Deleted.!
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:4
Queue is empty!!!
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:3
Queue is empty!!!
*************
* 0.Exit    *
* 1.Push    *
* 2.Delete  *
* 3.peek    *
* 4.Display *
*************
Enter the option:0

E:\DS (TCA)\Queue>

*/