#include<stdio.h>
#include<stdlib.h>
#define NEWNODE (struct node *)malloc(sizeof(struct node))

struct node *head=NULL;

struct node
{
	struct node *up;
	struct node *prev;
  int data;
  struct node *next;
  struct node *down;
};

struct node *Create_linked_list(int n)
{
	struct node *f=NULL,*t=NULL,*l=NULL;
  
  f=NEWNODE;
  printf("Enter the data:");
  scanf("%d",&f->data);
 
  f->prev=NULL;
  f->next=NULL;
   f->up=NULL;
  f->down=NULL;

  l=f;

  for(int i=2;i<=n;i++)
  {
  	t=NEWNODE;
  	printf("Enter the data:");
  	scanf("%d",&t->data);
  	t->prev=l;
  	t->next=NULL;
  	l->next=t;
  	l=l->next;
  	t->up=NULL;
  	t->down=NULL;
  	
  }

  return f;
}

struct node *Create_linked_list1(struct node *head,int n)
{
	struct node *t=NULL,*f=NULL,*l=NULL,*s=NULL;
	s=head;

	f=NEWNODE;
	printf("Enter the data:");
	scanf("%d",&f->data);
	f->next=NULL;
	f->prev=NULL;
	f->up=s;
	f->down=NULL;
	s->down=f;

	s=s->next;
	l=f;
	for(int i=2;i<=n;i++)
	{
		t=NEWNODE;
		printf("Enter the data:");
		scanf("%d",&t->data);
		t->next=NULL;
		t->prev=l;
		l->next=t;

		if(s!=NULL)
		{
		s->down=t;
		t->up=s;
		s=s->next;
	  }
	  else
	  {
	  	t->up=NULL;
	  }
    l=t;
		t->down=NULL;
	}
	return f;
}

void Display()
{
	struct node *t=NULL,*v=NULL;
  v=head;
	t=v;

	while(v!=NULL)
	{

	while(t!=NULL)
	{
		printf("%2d ",t->data);
		t=t->next;
	}
	printf("\n");

	v=v->down;
	t=v;
	
  }
	
		
}

struct node *Free_all()
{
	struct node *t=NULL,*l=NULL;
	
	t=head;


while(head!=NULL)
{
	head=head->down;
	while(t!=NULL)
	{
		l=t;
		t=t->next;
		free(l);
   }
   head=t;
 }

 return head;

}


int main()
{
	struct node *temp=NULL;
	int n,row;

	printf("How many rows do you want to create:");
	scanf("%d",&row);

	printf("Enter the size of [1] row:");
	scanf("%d",&n);

	if(n<=0)
		{
			printf("Invalid input!!!\n");
			exit(0);
		}


	head=Create_linked_list(n);
	temp=head;

	for(int i=2;i<=row;i++)
	{
		printf("Enter the size of [%d] row:",i);
		scanf("%d",&n);
		if(n<=0)
		{
			printf("Invalid input!!!\n");
			exit(0);
		}

   temp=Create_linked_list1(temp,n);
  }
    
   printf("Your Matrix:\n");
 
	Display();

	head=Free_all();


	return 0;



}