/*Operations on Doubly linked list*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node
{
	int data;
	struct node *prev,*next;
};

/*fn decln*/

struct node *createll(struct node *);
void displayll(struct node *);
void reversell(struct node *);
struct node *insertatbeg(struct node *);
void insertatend(struct node *);


void main()
{
	struct node *dbl;
	int choice;

	dbl=NULL;

	while(1)
	{
		clrscr();
		printf("Operations on dounly linked list");
		printf("\n1.Create DBL");
		printf("\n2.Display LL");
		printf("\n3.Display in reverse order");
		printf("\n4.Insert a node at beginning");
		printf("\n5.Insert a node at end");
		printf("\n6.Exit");

		printf("\n\nEnter your choice:- ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				dbl=createll(dbl);
				break;
			case 2:
				displayll(dbl);
				break;
			case 3:
				reversell(dbl);
				break;
			case 4:
				dbl=insertatbeg(dbl);
				break;
			case 5:
				insertatend(dbl);
				break;
			case 6:
				exit();
			default:
				printf("Error in choice,try again");
		}
		getch();
	}
}

/*fn defn*/

struct node *createll(struct node *dbl)
{
	struct node *newnode,*temp;
	char ask='y';

	while(ask=='y' || ask=='Y')
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data for newnode:- ");
		scanf("%d",&newnode->data);
		newnode->next=NULL;

		if(dbl==NULL)
		{
			newnode->prev=NULL;
			dbl=newnode;
			temp=newnode;
		}
		else
		{
			newnode->prev=temp;
			temp->next=newnode;
			temp=newnode;
		}
		flushall();
		printf("Add more nodes?:- ");
		scanf("%c",&ask);
	}/*end of while*/
	return dbl;
}

void displayll(struct node *temp)
{
	if(temp==NULL)
	{
		printf("First create LL");
		return;
	}

	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}

void reversell(struct node *temp)
{
	if(temp==NULL)
	{
		printf("First create LL");
		return;
	}

	while(temp->next!=NULL)
		temp=temp->next;

	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->prev;
	}
}


struct node *insertatbeg(struct node *dbl)
{
	struct node *newnode;

	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data for newnode:- ");
	scanf("%d",&newnode->data);

	newnode->next=dbl;
	newnode->prev=NULL;
	dbl->prev=newnode;

	return newnode;
}

void insertatend(struct node *dbl)
{
	struct node *temp,*newnode;

	newnode=(struct node *)malloc(sizeof(struct node));

	printf("Enter data for last node:- ");
	scanf("%d",&newnode->data);

	newnode->next=NULL;
	temp=dbl;
	while(temp->next!=NULL)
		temp=temp->next;

	newnode->prev=temp;
	temp->next=newnode;
}