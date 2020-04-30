/* Accept a graph from user & display all vertices using DFS Traversal */
#include <stdio.h>
#include <conio.h>
#define SIZE 10

struct stack
{
	int data[SIZE];  /* To store vertex nos */
	int top;
};

/* fn decls */
void init_stack(struct stack *);
void push(struct stack *,int);
int pop(struct stack *);
int isempty(struct stack *);

void dfs(int [][],int);

void main()
{
	int am[10][10], nov, i, j;
	clrscr();
	printf("Enter the no of vertices for the graph :- ");
	scanf("%d",&nov);
	printf("Enter the data for the graph\n");
	for (i=0;i<nov;i++)
	{
		for (j=0;j<nov;j++)
		{
			printf("Is there an edge between vertex %d and vertex %d :- ",i+1,j+1);
			scanf("%d",&am[i][j]);
		}
	}
	dfs(am,nov);
	getch();
}

void dfs(int am[SIZE][SIZE],int nov)
{
	int visited[SIZE] = {0};
	struct stack s;
	int v, w;
	init_stack(&s);
	printf("Enter the starting vertex no :- ");
	scanf("%d",&v);
	v = v - 1;  /* imp - to save space in array */
	visited[v] = 1;
	printf("%d ",v+1);
	push(&s,v);
	while (1)
	{
		for (w=0;w<nov;w++)
		{
			if (am[v][w] == 1 && visited[w] == 0)
			{
				visited[w] = 1;
				printf("%d ",w+1);
				push(&s,w);
				v = w;
				w = -1;  /* v imp so that it will search for vertices
					from begining */
			}
		}
		if (!isempty(&s))
			v = pop(&s);
		else
			break;
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

int isempty(struct stack *ps)
{
	if (ps->top == -1)
		return 1;

	return 0;
}










