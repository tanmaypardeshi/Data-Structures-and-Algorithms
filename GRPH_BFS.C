/* Accept a graph from user & display all vertices using BFS Traversal */
#include <stdio.h>
#include <conio.h>
#define SIZE 10

struct queue
{
	int data[SIZE];  /* To store vertex nos */
	int front, rear;
};

/* fn decls */
void init_q(struct queue *);
void addq(struct queue *,int);
int delq(struct queue *);
int isqempty(struct queue *);

void bfs(int [][],int);

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
	bfs(am,nov);
	getch();
}

void bfs(int am[SIZE][SIZE],int nov)
{
	struct queue q;
	int v, w;
	int visited[SIZE] = {0};   /* shortcut to initialise all elements of
					this array to 0 */
	init_q(&q);
	printf("Enter the starting vertex :- ");
	scanf("%d",&v);
	v = v - 1;  /* imp - to save space in visited[ ] */
	visited[v] = 1;
	addq(&q,v);
	while (!isqempty(&q))
	{
		v = delq(&q);
		printf("%d ",v+1);
		for (w=0;w<nov;w++)
		{
			if (am[v][w] == 1) /* is there an edge betn vertex v & w */
			{
				if (visited[w] == 0)
				{
					visited[w] = 1;
					addq(&q,w);
				}
			}
		}
	}
}

void init_q(struct queue *pq)
{
	pq->front = pq->rear = -1;
}

void addq(struct queue *pq,int no)
{
	pq->rear++;
	pq->data[pq->rear] = no;
	if (pq->front == -1)
		pq->front = 0;
}

int delq(struct queue *pq)
{
	return pq->data[pq->front++];
}


int isqempty(struct queue *pq)
{
	if (pq->front == -1 || pq->rear < pq->front)
		return 1;

	return 0;
}












