/* Create BST & Non Recursive Traversals */
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#define SIZE 10

struct node
{
	int data;
	struct node *left, *right;
	int flag;
};

struct stack
{
	struct node *adr[SIZE];
	int top;
};

struct queue
{
	struct node *adr[SIZE];
	int front, rear;
};


/* fn decls */
struct node *createbst(struct node *);  /* this fn returns the adr of root
						of BST */
void preorder(struct node *), inorder(struct node *), postorder(struct node *);
void init_stack(struct stack *);
void push(struct stack *,struct node *);
struct node *pop(struct stack *);
int isempty(struct stack *);
void displaylevelwise(struct node *);
void init_q(struct queue *);
void addq(struct queue *,struct node *);
struct node *delq(struct queue *);
int isqempty(struct queue *);


void main()
{
	struct node *root = NULL;
	int choice;
	while (1)
	{
		clrscr();
		printf("Operations on BST\n");
		printf("1. Create BST\n");
		printf("2. Preorder\n");
		printf("3. Inorder\n");
		printf("4. Postorder\n");
		printf("5. Levelwise Display of nodes\n");
		printf("6. Exit\n\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				root = createbst(root);
				break;

			case 2:
				preorder(root);
				break;

			case 3:
				inorder(root);
				break;

			case 4:
				postorder(root);
				break;

			case 5:
				displaylevelwise(root);
				break;

			case 6:
				exit();

			default :
				printf("Wrong Choice, Try Again");
		}
		getch();
	}
}

struct node *createbst(struct node *root)
{
	struct node *newnode, *temp;
	char ask = 'y';
	while (ask == 'y' || ask == 'Y')
	{
		newnode = (struct node *) malloc(sizeof(struct node));
		printf("Enter the value to be put in BST :- ");
		scanf("%d",&newnode->data);
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->flag = 0;
		/* check whether it is 1st node. If so, make it the root of BST */
		if (root == NULL)
			root = newnode;
		else
		{
			temp = root;
			/* search in BST for proper place */
			while (1)
			{
				if (newnode->data < temp->data)
				{
					if (temp->left == NULL)
					{
						temp->left = newnode;
						break;
					}
					else
						temp = temp->left;
				}
				else  /* newnode->data > temp->data */
				{
					if (temp->right == NULL)
					{
						temp->right = newnode;
						break;
					}
					else
						temp = temp->right;
				}
			}  /* end of while(1) */
		}  /* end of if...else */
		flushall();
		printf("Add more nodes to BST ? ");
		scanf("%c",&ask);
	} /* end of while (ask=='y' || ask == 'Y') */
	return root;
}

void preorder(struct node *temp)
{
	struct stack s;
	init_stack(&s);
	while (1)
	{
		while (temp != NULL)
		{
			printf("%d ",temp->data);
			if (temp->right != NULL)
				push(&s,temp->right);

			temp = temp->left;
		}
		if (!isempty(&s))
			temp = pop(&s);
		else
			break;
	}
}

void inorder(struct node *temp)
{
	struct stack s;
	init_stack(&s);
	while (1)
	{
		while (temp != NULL)
		{
			push(&s,temp);
			temp = temp->left;
		}
		if (!isempty(&s))
		{
			temp = pop(&s);
			printf("%d ",temp->data);
			temp = temp->right;
		}
		else
			break;
	}
}

void postorder(struct node *temp)
{
	struct stack s;
	init_stack(&s);
	while (1)
	{
		while (temp != NULL)
		{
			push(&s,temp);
			temp = temp->left;
		}
		while (!isempty(&s))
		{
			temp = pop(&s);
			if (temp->flag == 1)
				printf("%d ",temp->data);
			else
			{
				temp->flag = 1;
				push(&s,temp);
				temp = temp->right;
				break;
			}
		}
		if (isempty(&s))
			break;
	}
}

void displaylevelwise(struct node *temp)
{
	struct queue q;
	init_q(&q);
	addq(&q,temp);
	while (!isqempty(&q))
	{
		temp = delq(&q);
		printf("%d ",temp->data);
		if (temp->left != NULL)
			addq(&q,temp->left);

		if (temp->right != NULL)
			addq(&q,temp->right);
	}
}

void init_q(struct queue *pq)
{
	pq->front = pq->rear = -1;
}

void addq(struct queue *pq,struct node *data)
{
	pq->rear++;
	pq->adr[pq->rear] = data;
	/* check wheteher it is the 1st element */
	if (pq->front == -1)
		pq->front = 0;
}

struct node *delq(struct queue *pq)
{
	return pq->adr[pq->front++];
}

int isqempty(struct queue *pq)
{
	if (pq->front == -1 || pq->front > pq->rear)
		return 1;

	return 0;
}




































void init_stack(struct stack *ps)
{
	ps->top = -1;
}

void push(struct stack *ps,struct node *temp)
{
	ps->top++;
	ps->adr[ps->top] = temp;
}

struct node *pop(struct stack *ps)
{
	return ps->adr[ps->top--];
}

int isempty(struct stack *ps)
{
	if (ps->top == -1)
		return 1;

	return 0;
}

























