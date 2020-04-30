/* Implementation of Dequeue Queue */
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
void addl(struct queue *,int);
void addr(struct queue *,int);
int dell(struct queue *);
int delr(struct queue *);
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
		printf("1. Add from Left\n");
		printf("2. Add from Right\n");
		printf("3. Delete from Left\n");
		printf("4. Delete from Right\n");
		printf("5. Display Queue\n");
		printf("6. Exit\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				if (isqfull(&q))
					printf("Dequeue is Full");
				else
				{
					printf("Enter the no :- ");
					scanf("%d",&no);
					addl(&q,no);
				}
				break;

			case 2:
				if (isqfull(&q))
					printf("Dequeue is Full");
				else
				{
					printf("Enter the no :- ");
					scanf("%d",&no);
					addr(&q,no);
				}
				break;

			case 3:
				if (isqempty(&q))
					printf("Dequeue is Empty");
				else
					printf("Element deleted is %d",dell(&q));

				break;


			case 4:
				if (isqempty(&q))
					printf("Dequeue is Empty");
				else
					printf("Element deleted is %d",delr(&q));

				break;

			case 5:
				if (isqempty(&q))
					printf("Dequeue is Empty");
				else
					displayq(&q);

				break;

			case 6:
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

void addl(struct queue *pq,int no)
{
	int i;
	/* check whether q is empty. If so, get front & rear to 0 */
	if (isqempty(pq))
		pq->front = pq->rear = 0;
	else
	{
		/* if rear != SIZE-1, shift elements from L to R */
		if (pq->rear != SIZE-1)
		{
			pq->rear++;
			for (i=pq->rear;i!=pq->front;i--)
				pq->data[i] = pq->data[i-1];
		}
		else
			pq->front--;
	}
	pq->data[pq->front] = no;
}


void addr(struct queue *pq,int no)
{
	int i;
	/* check whether q is empty. If so, get front & rear to 0 */
	if (isqempty(pq))
		pq->front = pq->rear = 0;
	else
	{
		/* if front != 0, shift elements from R to L */
		if (pq->front != 0)
		{
			pq->front--;
			for (i=pq->front;i!=pq->rear;i++)
				pq->data[i] = pq->data[i+1];
		}
		else
			pq->rear++;
	}
	pq->data[pq->rear] = no;
}

int dell(struct queue *pq)
{
	int no;
	no = pq->data[pq->front];
	pq->front++;
	/* check whether it crosses rear. If so, q is empty */
	if (pq->front > pq->rear)
		initq(pq);

	return no;
}

int delr(struct queue *pq)
{
	int no;
	no = pq->data[pq->rear];
	pq->rear--;
	/* check whether it crosses front. If so, q is empty */
	if (pq->rear < pq->front)
		initq(pq);

	return no;
}

int isqfull(struct queue *pq)
{
	if (pq->front == 0 && pq->rear == SIZE-1)
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
	int temp;
	for (temp=pq->front;temp<=pq->rear;temp++)
		printf("%d ",pq->data[temp]);
}










