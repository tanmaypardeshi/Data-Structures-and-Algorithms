/* To convert a postfix expression to infix expression */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define R 10
#define C 50

struct stack
{
	char data[R][C];
	int top;
};

/* fn decls */
void init_stack(struct stack *);
void push(struct stack *,char *);  /* char * indicates a dynamic string */
char *pop(struct stack *);

void main()
{
	char postfix[C], expr[C], op1[C], op2[C], str[2];
	int i;
	struct stack s;
	init_stack(&s);
	clrscr();
	printf("Enter the postfix expression :- ");
	gets(postfix);
	for (i=0; postfix[i] != '\0'; i++)
	{
		str[0] = postfix[i];  /* to convert char to string */
		str[1] = '\0';
		switch (postfix[i])  /* switch case doesn't work with strings */
		{
			case '+':
			case '-':
			case '/':
			case '*':
			case '$':
			case '^':
			case '%':
				/* op2 = pop(&s);  error, strings cannot be
				copied using = assignment operator */
				strcpy(op2,pop(&s));
				strcpy(op1,pop(&s));
				strcpy(expr,"(");
				strcat(expr,op1);
				strcat(expr,str);
				strcat(expr,op2);
				strcat(expr,")");
				push(&s,expr);
				break;

			default:  /* operands */
				push(&s,str);
		} /* end of switch case */
	} /* end of loop */
	printf("Infix expression is %s",pop(&s));
	getch();
}

void init_stack(struct stack *ps)
{
	ps->top = -1;
}

void push(struct stack *ps,char *str)
{
	ps->top++;
	/* ps->data[ps->top] = str;  error */
	strcpy(ps->data[ps->top],str);
}

char *pop(struct stack *ps)
{
	return ps->data[ps->top--];
}






