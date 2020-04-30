/* Implementation of static Circular Queue */
#include <stdio.h>
#include <conio.h>
#define SIZE 5

struct queue
{
	int data[SIZE];
	int front, rear;
};

/* fn decls */
void initq(struct queue *);
void addq(struct queue *,int);
int delq(struct queue *);
int isqfull(struct queue *);
int isqempty(struct queue *);
void displayq(struct queue *);

void main()
{
	struct queue q;
	int no, choice;
	initq(&q);
	while (1)
	{
		clrscr();
		printf("Primitive Operations on Static Circular Queue\n");
		printf("1. Add to Queue\n");
		printf("2. Delete from Queue\n");
		printf("3. Display Queue\n");
		printf("4. Exit\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				if (isqfull(&q))
					printf("Circular Queue is Full");
				else
				{
					printf("Enter the no :- ");
					scanf("%d",&no);
					addq(&q,no);
				}
				break;

			case 2:
				if (isqempty(&q))
					printf("Circular Queue is Empty");
				else
					printf("Element deleted is %d",delq(&q));

				break;

			case 3:
				if (isqempty(&q))
					printf("Circular Queue is Empty");
				else
					displayq(&q);

				break;

			case 4:
				exit();

			default:
				printf("Error in choice, Try again");
		}
		getch();
	}
}

void initq(struct queue *pq)
{
	pq->front = pq->rear = -1;
}

void addq(struct queue *pq,int no)
{
	pq->rear = (pq->rear+1) % SIZE;
	pq->data[pq->rear] = no;
	/* imp - check whether it is 1st element */
	if (pq->front == -1)
		pq->front = 0;
}

int delq(struct queue *pq)
{
	int no;
	no = pq->data[pq->front];
	pq->front = (pq->front+1) % SIZE;  /* front also moves on a
						circular path */
	/* check whether it crosses rear. If so, it means last element is
	   deleted & now the queue is empty. So reset front & rear to -1 */
	if (pq->front == (pq->rear+1) % SIZE)
		pq->front = pq->rear = -1;

	return no;
}

int isqfull(struct queue *pq)
{
	if (pq->front == (pq->rear+1) % SIZE)
		return 1;

	return 0;
}

int isqempty(struct queue *pq)
{
	if (pq->front == -1)
		return 1;

	return 0;
}

void displayq(struct queue *pq)
{
	int temp = pq->front;
	/* imp, we have already checked that q is not empty. So no
	   condition in loop reqd initially */
	while (1)
	{
		printf("%d ",pq->data[temp]);
		temp = (temp+1) % SIZE;
		/* check whether it has crossed rear. If so, last element
		  is printed & we need to stop */
		if (temp == (pq->rear+1) % SIZE)
			break;
	}
}










