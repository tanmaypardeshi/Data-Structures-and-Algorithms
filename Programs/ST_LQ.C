/* Implementation of static Linear Queue */
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
		printf("Primitive Operations on Static Linear Queue\n");
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
					printf("Linear Queue is Full");
				else
				{
					printf("Enter the no :- ");
					scanf("%d",&no);
					addq(&q,no);
				}
				break;

			case 2:
				if (isqempty(&q))
					printf("Linear Queue is Empty");
				else
					printf("Element deleted is %d",delq(&q));

				break;

			case 3:
				if (isqempty(&q))
					printf("Linear Queue is Empty");
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
	pq->rear++;
	pq->data[pq->rear] = no;
	/* imp - check whether it is 1st element */
	if (pq->front == -1)
		pq->front = 0;
}

int delq(struct queue *pq)
{
	return pq->data[pq->front++];/* imp - front proceeds after deletion */
}

int isqfull(struct queue *pq)
{
	if (pq->rear == SIZE-1)
		return 1;

	return 0;
}

int isqempty(struct queue *pq)
{
	if (pq->front == -1 || pq->front > pq->rear)
		return 1;

	return 0;
}

void displayq(struct queue *pq)
{
	int temp;
	for (temp=pq->front;temp<=pq->rear;temp++)
		printf("%d ",pq->data[temp]);
}










