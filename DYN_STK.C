/* An eg of Dynamic Stack */
#include <stdio.h>
#include <conio.h>
#include <alloc.h>

struct node
{
	int data;
	struct node *next;
};

/* fn decls */
void init_stack();
void push(int);
int pop();
int isempty();
void display();

/* global var - imp */
struct node *top;

void main()
{
	int no, choice;
	init_stack();
	while (1)
	{
		clrscr();
		printf("Primitive Operations on Static Stack\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("Enter the no to push :- ");
				scanf("%d",&no);
				push(no);
				break;

			case 2:
				if (isempty())
					printf("Stack is empty");
				else
					printf("Element popped is %d",pop());

				break;

			case 3:
				if (isempty())
					printf("Stack is empty");
				else
					display();

				break;

			case 4:
				exit();

			default:
				printf("Wrong Choice");
		}
		getch();
	}
}

void init_stack()
{
	top = NULL;
}

void push(int no)
{
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data = no;
	/* check whether it is 1st node in stack */
	if (top == NULL)
	{
		newnode->next = NULL;
		top = newnode;
	}
	else
	{
		newnode->next = top;
		top = newnode;  /* top ascends */
	}
}

int pop()
{
	struct node *temp;
	int no;
	no = top->data;
	temp = top;
	top = top->next;  /* top descends */
	free(temp);
	return no;
}

int isempty()
{
	if (top == NULL)
		return 1;

	return 0;
}

void display()
{
	struct node *temp;
	for (temp=top;temp != NULL; temp = temp->next)
		printf("%d\n",temp->data);
}







