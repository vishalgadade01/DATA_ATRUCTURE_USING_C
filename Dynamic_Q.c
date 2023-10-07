#include<stdio.h>
#include<stdlib.h>
#define NEWNODE (struct node*)malloc(sizeof(struct node))

struct node
{
  int data;
  struct node *next;
};

struct node *front;
struct node *reare;

void init()
{
  front=reare=NULL;
}
int isempty()
{
  return reare==NULL;
}

void push_Q(int item)
{
  struct node *temp=NULL;
  temp=NEWNODE;
  if(temp==NULL)
  {
    printf("Queue  is Full!!!\n");
    return;
  }
  temp->data=item;
  temp->next=NULL;

  if(reare==NULL)
  {
    front=reare=temp;

  }
  else
  {
    reare->next=temp;
    reare=temp;

  }

  printf("[%d] is pushed sucessfully..\n",item);
}

int pop_Q()
{
  int temp;
  struct node *t=NULL;
  if(isempty())
  {
    printf("Queue  is empty.!!!\n");
    return -1;
  }
  
  temp=front->data;
  t=front;
  if(front!=reare)
  {
  front=front->next;
   }
  else
  {
    init();
  }
  free(t);
  return temp;

}

int peek_Q()
{
  if(isempty())
  {
    printf("Queue is empty.!!!\n");
    return -1;
  }

  return front->data;
}

void Display_Q()
{
  struct node *t=NULL;
  if(isempty())
  {
    printf("Queue  is empty..!!!\n");
    return;
  }
  t=front;
  printf("Your data:");

  while(t!=NULL)
  {
    printf("%d ",t->data);
    t=t->next;
  }
  printf("\n");
 

}



int main()
{
  init();
  int op;

  while(1)
  {
    printf("*************\n");
    printf("* 0.Exit    *\n");
    printf("* 1.Push    *\n");
    printf("* 2.Pop     *\n");
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
            scanf("%d",&op);
            push_Q(op);
            break;
      case 2:
            if(isempty())
            {
              printf("Queue is empty.!!!\n");
            }
            else
            {
              printf("Poped element is: %d \n",pop_Q());
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
             Display_Q();
            }

            break;


      default :
            
            printf("Invalid option..!!\n");                        
    }

  }

  return 0;
}

/*

OUTPUT:


E:\DS (TCA)\Q>gcc Dynamicq.c

E:\DS (TCA)\Q>a.exe
*************
* 0.Exit    *
* 1.Push    *
* 2.Pop     *
* 3.peek    *
* 4.Display *
*************
Enter the option:1
Enter the data:11
[11] is pushed sucessfully..
*************
* 0.Exit    *
* 1.Push    *
* 2.Pop     *
* 3.peek    *
* 4.Display *
*************
Enter the option:1
Enter the data:22
[22] is pushed sucessfully..
*************
* 0.Exit    *
* 1.Push    *
* 2.Pop     *
* 3.peek    *
* 4.Display *
*************
Enter the option:1
Enter the data:33
[33] is pushed sucessfully..
*************
* 0.Exit    *
* 1.Push    *
* 2.Pop     *
* 3.peek    *
* 4.Display *
*************
Enter the option:33
Invalid option..!!
*************
* 0.Exit    *
* 1.Push    *
* 2.Pop     *
* 3.peek    *
* 4.Display *
*************
Enter the option:3
Peeked element is: 11.
*************
* 0.Exit    *
* 1.Push    *
* 2.Pop     *
* 3.peek    *
* 4.Display *
*************
Enter the option:4
Your data:11 22 33
*************
* 0.Exit    *
* 1.Push    *
* 2.Pop     *
* 3.peek    *
* 4.Display *
*************
Enter the option:2
Poped element is: 11
*************
* 0.Exit    *
* 1.Push    *
* 2.Pop     *
* 3.peek    *
* 4.Display *
*************
Enter the option:4
Your data:22 33
*************
* 0.Exit    *
* 1.Push    *
* 2.Pop     *
* 3.peek    *
* 4.Display *
*************
Enter the option:3
Peeked element is: 22.
*************
* 0.Exit    *
* 1.Push    *
* 2.Pop     *
* 3.peek    *
* 4.Display *
*************
Enter the option:0

E:\DS (TCA)\Q>

*/