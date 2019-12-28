/* Program to evaluate postfix expression */
#include <stdio.h>
#include <conio.h>
#include <ctype.h>   /* to check for operands fn - isalpha() */
#include <math.h>  /* for pow() */
#define SIZE 10

struct stack
{
	int data[SIZE];
	int top;
};

/* fn decls */
void init_stack(struct stack *);
void push(struct stack *,int);
int pop(struct stack *);


void main()
{
	char postfix[20];
	int i, op1, op2, val;  /* val to accept the value of operand */
	struct stack s;
	init_stack(&s);
	clrscr();
	printf("Enter the postfix expression :- ");
	gets(postfix);
	/* read each char from postfix string */
	for (i=0; postfix[i] != '\0'; i++)
	{
		/* operand */
		if (isalpha(postfix[i]))
		{
			printf("Enter the value for operand %c :- ",postfix[i]);
			scanf("%d",&val);
			push(&s,val);
		}
		else /* operator */
		{
			op2 = pop(&s);
			op1 = pop(&s);
			if (postfix[i] == '+')
				push(&s,op1+op2);
			else if (postfix[i] == '-')
				push(&s,op1-op2);
			else if (postfix[i] == '*')
				push(&s,op1*op2);
			else if (postfix[i] == '/')
				push(&s,op1/op2);
			else if (postfix[i] == '%')
				push(&s,op1%op2);
			else /* $ or ^ */
				push(&s,pow(op1,op2));
		}
	}
	printf("Result of evaluating expression is %d",pop(&s));
	getch();
}

void init_stack(struct stack *ps)
{
	ps->top = -1;
}

void push(struct stack *ps,int val)
{
	ps->top++;
	ps->data[ps->top] = val;
}

int pop(struct stack *ps)
{
	return ps->data[ps->top--];
}





