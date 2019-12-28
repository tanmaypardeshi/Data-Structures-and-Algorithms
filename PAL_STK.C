/* Accept a word from user & determine whether it is a palindrome or not.
Hint - Use a stack to create reverse word */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define SIZE 20

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

void main()
{
	char word[SIZE], revword[SIZE];
	struct stack s;
	int i;   /* for traversal in a string */
	init_stack(&s);
	clrscr();
	printf("Enter the word :- ");
	gets(word);
	/* now push every char from word into stack */
	for (i=0;word[i] != '\0';i++)
		push(&s,word[i]);


	/* now pop every char from stack & add it to revword */
	i = 0;  /* imp to reset i to 0 */
	while (!isempty(&s))
	{
		revword[i] = pop(&s);
		i++;
	}
	revword[i] = '\0';  /* close the target string */
	if (stricmp(word,revword) == 0)
		printf("Given word %s and it's reverse %s are same",word,revword);
	else
		printf("Given word %s and it's reverse %s are not same",word,revword);

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











