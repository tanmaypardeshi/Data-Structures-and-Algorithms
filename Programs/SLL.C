/*Operations on Singly linked list*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>	/* malloc(),free() */

struct node
{
	int data;
	struct node *next;
};

/*fn declns*/

struct node *createsll(struct node *);
void displayll(struct node *);
struct node *insertatbeg(struct node *);
void insertatend(struct node *);
struct node *deleteatbeg(struct node *);
struct node *deleteatend(struct node *);
struct node *deleteatpos(struct node *);
struct node *insertatpos(struct node *);
void bub_sort(struct node *);
void reversell(struct node *);

void main()
{
	struct node *sl;
	int choice;
	sl=NULL; /*most important, LL is initialised*/

	while(1)
	{
		clrscr();
		printf("Operations on link list:- ");
		printf("\n1.Create Link list");
		printf("\n2.Display link list");
		printf("\n3.Insert a node at the beginning");
		printf("\n4.Insert a node at the end");
		printf("\n5.Delete a node from beginning");
		printf("\n6.Delete a node at the end");
		printf("\n7.Delete a node at a given position");
		printf("\n8.Insert a node at a given position");
		printf("\n9.Sort elements of a linked list");
		printf("\n10.Display elements in reverse order");
		printf("\n11.Exit");


		printf("\n\nEnter your choice:- ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				sl=createsll(sl);
				break;
			case 2:
				displayll(sl);
				break;
			case 3:
				sl=insertatbeg(sl);
				break;
			case 4:
				insertatend(sl);
				break;
			case 5:
				sl=deleteatbeg(sl);
				break;
			case 6:
				sl=deleteatend(sl);
				break;
			case 7:
				sl=deleteatpos(sl);
				break;
			case 8:
				sl=insertatpos(sl);
				break;
			case 9:
				bub_sort(sl);
				break;
			case 10:
				reversell(sl);
				break;
			case 11:
				exit();
			default:
				printf("Error in choice, try again");
		}
		getch();
	}
}


/*fn defns*/

struct node *createsll(struct node *sl)
{
	struct node *newnode,*temp;
	char ask='y';

	while(ask=='y' || ask=='Y')
	{
		/*allocate memory for newnode*/

		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data for newnode:- ");
		scanf("%d",&newnode->data);

		newnode->next=NULL;

		/*check whether it is 1st node of ll*/

		if(sl==NULL)
		{
			sl=newnode;
			temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		flushall();	/*cin.ignore(); in c++ */

		printf("Add more nodes ?:- ");
		scanf("%c", &ask);
	}
	return sl;
}

void displayll(struct node *temp)
{
	/*validation*/
	if(temp==NULL)
	{
		printf("First create link list");
		return;
	}
	while(temp!=NULL)
	{
		printf("%u %d %u    ",temp,temp->data,temp->next);
		temp=temp->next;
	}
}

struct node *insertatbeg(struct node *sl)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data for newnode:- ");
	scanf("%d", &newnode->data);

	/*set the links*/

	newnode->next=sl;

	return newnode;
}

void insertatend(struct node *sl)
{
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data for newnode:- ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;    /*as it is last node*/
	temp=sl;

	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=newnode;
}

struct node *deleteatbeg(struct node *sl)
{
	struct node *temp;
	temp=sl;
	sl=sl->next;  /*sl points to next node*/
	free(temp);
	return sl;
}

struct node *deleteatend(struct node *sl)
{
	struct node *temp;

	/*Case-1:Single node*/

	if(sl->next==NULL)
	{
		free(sl);
		return NULL;
	}

	temp=sl;
	/*Case-2:Bring temp to second last node of LL*/
	while(temp->next->next!=NULL)
		temp=temp->next;

	free(temp->next);
	temp->next=NULL;
	return sl;	/*unchanged*/
}

struct node *deleteatpos(struct node *sl)
{
	struct node *temp1,*temp2;
	int pos,cntr=0;

	printf("Enter the pos. of node to delete:- ");
	scanf("%d",&pos);

	/*case-1*/

	if(pos==1)
	{
		temp1=sl;
		sl=sl->next;
		free(sl);
		return sl;
	}

	/*case-2:Count the number of nodes in LL*.
	/*We need to confirm if posn exists or not before deletetion*/

	temp1=sl;
	while(temp1!=NULL)	/*means that temp1 is pointing to some valid
				  node*/
	{
		cntr++;
		temp1=temp1->next;
	}

	if(pos>cntr||pos<1)
	{
		printf("Invalid position");
		return sl;
	}
	/*now posn temp2 on node to delete and its previous node will be
	temp1*/

	cntr=2;
	temp1=sl;
	temp2=sl->next;

	while(temp2!=NULL)
	{
		if(pos==cntr)
			break;
		temp1=temp2;
		temp2=temp2->next;
		cntr++;
	}
	temp1->next=temp2->next;
	free(temp2);
	return sl;
}

struct node *insertatpos(struct node *sl)
{
	struct node *temp1,*temp2,*newnode;
	int pos,cntr=0;
	printf("Enter position of node:- ");
	scanf("%d",&pos);

	if(pos==1)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data for newnode:- ");
		scanf("%d",&newnode->data);

		newnode->next=sl;
		return newnode;
	}

	temp1=sl;
	while(temp1 != NULL)
	{
		cntr++;
		temp1=temp1->next;
	}

	if(pos>cntr+1 || pos<1)
	{
		printf("Invalid position");
		return sl;
	}

	cntr=2;
	temp1=sl;
	temp2=sl->next;

	while(temp2 != NULL)
	{
		if(pos==cntr)
			break;
		cntr++;
		temp1=temp2;
		temp2=temp2->next;
	}
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data for newnode:- ");
	scanf("%d", &newnode->data);
	temp1->next=newnode;
	newnode->next=temp2;
	return sl;
}

void bub_sort(struct node *sl)
{
	struct node *temp1,*temp2;
	int i,j,cntr=0;
	int temp;

	temp1=sl;

	while(temp1 != NULL)
	{
		cntr++;
		temp1=temp1->next;
	}

	for(i=1;i<cntr;i++)
	{
		temp1 = sl;
		temp2 = sl->next;
		for(j=0;j<cntr-i;j++)
		{
			if(temp1->data > temp2->data)
			{
				temp=temp1->data;
				temp1->data=temp2->data;
				temp2->data=temp;
			}
			temp1=temp2;
			temp2=temp2->next;
		}
	}
}

void reversell(struct node *temp)
{
	if(temp != NULL)
	{
		reversell(temp->next);
		printf("%d\t",temp->data);
	}
}
