/*Operations on Singly Circular linked list*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node
{
	int data;
	struct node *next;
};


/*fn declns*/

struct node *createll(struct node *);
void displayll(struct node *);
struct node *insertatbeg(struct node *);
void insertatend(struct node *);
struct node *deleteatbeg(struct node *);


void main()
{
	struct node *scl;
	int choice;

	scl=NULL;

	while(1)
	{
		clrscr();
		printf("Operations on SCL");
		printf("\n1.Create SCL");
		printf("\n2.Display SCL");
		printf("\n3.Insert a node at beginning");
		printf("\n4.Insert a node at end");
		printf("\n5.Delete a node at beginning");
		printf("\n6.Exit");

		printf("\n\nEnter your choice:- ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				scl=createll(scl);
				break;
			case 2:
				displayll(scl);
				break;
			case 3:
				scl=insertatbeg(scl);
				break;
			case 4:
				insertatend(scl);
				break;
			case 5:
				scl=deleteatbeg(scl);
				break;
			case 6:
				exit();
			default:
				printf("Error in choice, Try again.");
		}
		getch();
	}
}


struct node *createll(struct node *scl)
{
	struct node *newnode,*temp;
	char ask='y';

	while(ask=='y' || ask=='Y')
	{
		newnode=(struct node *)malloc(sizeof(struct node));

		printf("Enter data for newnode:- ");
		scanf("%d", &newnode->data);

		/*check whether it is first node*/

		if(scl==NULL)
		{
			newnode->next=newnode;	/*to make it circular*/
			scl=newnode;
			temp=newnode;
		}

		else
		{
			newnode->next=scl;
			temp->next=newnode;
			temp=newnode;
		}
		flushall();
		printf("Add more nodes?:- ");
		scanf("%c",&ask);
	}
	return scl;
}

void displayll(struct node *scl)
{
	struct node *temp;

	if(scl==NULL)
	{
		printf("First create LL");
		return;
	}
	temp=scl;
	while(1)
	{
		printf("%d\t",temp->data);
		temp=temp->next;

		if(temp==scl)
			break;
	}

	/*Alternative method:-

	do
	{
		printf("%d",temp->data);
		temp=temp->next;
	}while(temp!=scl);

	*/

}

struct node *insertatbeg(struct node *scl)
{
	struct node *newnode,*temp;

	newnode=(struct node *)malloc(sizeof(struct node));

	printf("Enter data for newnode:- ");
	scanf("%d",&newnode->data);

	newnode->next=scl;
	temp=scl;

	while(1)
	{
		temp=temp->next;

		if(temp->next==scl)
			break;
	}
	temp->next=newnode;

	return newnode;
}

void insertatend(struct node *scl)
{
	struct node *newnode,*temp;

	newnode=(struct node *)malloc(sizeof(struct node));

	printf("Enter data for newnode:- ");
	scanf("%d",&newnode->data);

	temp=scl;

	while(1)
	{
		temp=temp->next;
		if(temp->next==scl)
			break;
	}
	temp->next=newnode;
	newnode->next=scl;
}


struct node *deleteatbeg(struct node *scl)
{
	struct node *temp;
	temp=scl;
	while(1)
	{
		temp=temp->next;

		if(temp->next==scl)
			break;
	}
	if(temp==scl)
	{
		free(scl);
		return NULL;
	}
	temp->next=scl->next;
	free(scl);
	return temp->next;
}
