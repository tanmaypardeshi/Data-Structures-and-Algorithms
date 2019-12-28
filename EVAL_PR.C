/* Program to evaluate prefix expression */
#include <stdio.h>
#include <conio.h>
#include <ctype.h>   /* to check for operands fn - isalpha() */
#include <math.h>  /* for pow() */
#include <string.h>
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
	char prefix[20];
	int i, j = 0, op1, op2, vals[20]; /* vals[] will accept the value of operand */
	struct stack s;
	init_stack(&s);
	clrscr();
	printf("Enter the prefix expression :- ");
	gets(prefix);
	for (i=0;prefix[i] != '\0'; i++)
	{
		if (isalpha(prefix[i]))
		{
			printf("Enter the value for operand %c :- ",prefix[i]);
			scanf("%d",&vals[j]);
			j++;
		}
	}
	j--;  /* j is pointing to last value */
	/* read each char from prefix string R to L */
	for (i=strlen(prefix)-1; i >= 0; i--)
	{
		/* operand */
		if (isalpha(prefix[i]))
		{
			push(&s,vals[j]);
			j--;
		}
		else /* operator */
		{
			op1 = pop(&s);
			op2 = pop(&s);
			if (prefix[i] == '+')
				push(&s,op1+op2);
			else if (prefix[i] == '-')
				push(&s,op1-op2);
			else if (prefix[i] == '*')
				push(&s,op1*op2);
			else if (prefix[i] == '/')
				push(&s,op1/op2);
			else if (prefix[i] == '%')
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