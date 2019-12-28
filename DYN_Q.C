/* Implementation of Dynamic Queue */
#include <stdio.h>
#include <conio.h>
#include <alloc.h>

struct node
{
	int data;
	struct node *next;
};

struct node *front, *rear;

/* fn decls */
void init_q();
void addq(int);
int delq();
int isqempty();
void displayq();

void main()
{
	int choice, no;
	init_q();
	while (1)
	{
		clrscr();
		printf("Primitive Operations on Dynamic Queue\n");
		printf("1. Add to Queue\n");
		printf("2. Delete from Queue\n");
		printf("3. Display Queue\n");
		printf("4. Exit\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("Enter the no :- ");
				scanf("%d",&no);
				addq(no);
				break;

			case 2:
				if (isqempty())
					printf("Dynamic Queue is Empty");
				else
					printf("Element deleted is %d",delq());

				break;

			case 3:
				if (isqempty())
					printf("Dynamic Queue is Empty");
				else
					displayq();

				break;

			case 4:
				exit();

			default:
				printf("Error in choice, Try Again");
		}
		getch();
	}
}

void init_q()
{
	front = rear = NULL;
}

void addq(int no)
{
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data = no;
	newnode->next = NULL;
	/* check whether it is 1st node of LL */
	if (front == NULL)
	{
		front = newnode;
		rear = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
	}
}

int delq()
{
	struct node *temp;
	int no;
	temp = front;
	no = front->data;
	front = front->next;
	/* check whether the node deleted is last node. if so, reset front
	   & rear */
	if (front == NULL)
		rear = NULL;

	free(temp);
	return no;
}

void displayq()
{
	struct node *temp;
	for (temp=front;temp!=NULL;temp=temp->next)
		printf("%d ",temp->data);
}

int isqempty()
{
	if (front == NULL)
		return 1;

	return 0;
}





























