/* Program to convert infix expression to postfix */
#include <stdio.h>
#include <conio.h>
#define SIZE 10

struct stack
{
	char data[SIZE];
	int top;
};

/* fn decls */
void init_stack(struct stack *);
void push(struct stack *,char);
char pop(struct stack *);
int isempty(struct stack *);
int priority(char);
char peek(struct stack *);  /* to read the char @ top of stack */

void main()
{
	char infix[20], postfix[20], ch;
	struct stack s;
	int i, j = 0;  /* i to read each char from infix & j reqd to write
			  the chars to postfix */
	init_stack(&s);
	clrscr();
	printf("Enter the infix expression :- ");
	gets(infix);
	/* read 1 by 1 char from infix string */
	for (i=0; infix[i] != '\0'; i++)
	{
		switch (infix[i])
		{
			case '(':
				push(&s,'(');
				/* push(&s,infix[i]);  */
				break;

			case '+':
			case '-':
			case '/':
			case '*':
			case '%':
			case '^':
			case '$':
	while (!isempty(&s) && priority(peek(&s)) >= priority(infix[i]))
			   {
				postfix[j] = pop(&s);
				j++;
			   }
			   push(&s,infix[i]);
			   break;

			case ')':
				ch = pop(&s);
				while (ch != '(')
				{
					postfix[j] = ch;
					j++;
					ch = pop(&s);
				}
				break;

			default :   /* operands */
				postfix[j] = infix[i];
				j++;
		}  /* end of switch */
	} /* end of for loop */
	/* if stack is not empty, pop all operators from stack & append
	   them to postfix string */
	while (!isempty(&s))
	{
		postfix[j] = pop(&s);
		j++;
	}
	postfix[j] = '\0';  /* imp - close the target string to get rid
				of garbage values */
	printf("Postfix expression is %s",postfix);
	getch();
}

void init_stack(struct stack *ps)
{
	ps->top = -1;
}

void push(struct stack *ps,char ch)
{
	ps->top++;
	ps->data[ps->top] = ch;
}

char pop(struct stack *ps)
{
	return ps->data[ps->top--];
}

int isempty(struct stack *ps)
{
	if (ps->top == -1)
		return 1;

	return 0;
}

int priority(char ch)
{
	if (ch == '^' || ch == '$')
		return 3;

	if (ch == '/' || ch == '*' || ch == '%')
		return 2;

	if (ch == '+' || ch == '-')
		return 1;

	return 0;   /* for ( bracket */
}

char peek(struct stack *ps)
{
	return ps->data[ps->top];
}










