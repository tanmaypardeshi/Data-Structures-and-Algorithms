/* Primitive Operations on Static Stack */
#include <stdio.h>
#include <conio.h>
#define SIZE 5

struct stack
{
	int data[SIZE];
	int top;
};

/* fn decls */
void init_stack(struct stack *);
void push(struct stack *,int);
int pop(struct stack *);
int isfull(struct stack *);
int isempty(struct stack *);
void display(struct stack *);

void main()
{
	struct stack s;
	int choice, no;
	init_stack(&s);
	while (1)
	{
		clrscr();
		printf("Primitive Operations on Static Stack\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				/* validation - check whether stack is full */
				if (isfull(&s))
					printf("Stack is Full");
				else
				{
					printf("Enter the no :- ");
					scanf("%d",&no);
					push(&s,no);
				}
				break;

			case 2:
				/* validation - check whether stack is empty */
				if (isempty(&s))
					printf("Stack is Empty");
				else
					printf("Element popped is %d",pop(&s));
					/* nested fn call */

				break;

			case 3:
				if (isempty(&s))
					printf("Stack is Empty");
				else
					display(&s);

				break;

			case 4:
				exit();

			default:
				printf("Error in choice, try again");

		}
		getch();
	}
}

void init_stack(struct stack *ps)
{
	ps->top = -1;
}

void push(struct stack *ps,int no)
{
	ps->top++;
	ps->data[ps->top] = no;
}

int pop(struct stack *ps)
{
	return ps->data[ps->top--];
}

int isfull(struct stack *ps)
{
	if (ps->top == SIZE-1)
		return 1;

	return 0;
}

int isempty(struct stack *ps)
{
	if (ps->top == -1)
		return 1;

	return 0;
}

void display(struct stack *ps)
{
	int temp;
	for (temp=ps->top;temp!=-1;temp--)
		printf("%d\n",ps->data[temp]);
}







