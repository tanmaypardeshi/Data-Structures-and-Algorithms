/* Operations on Singly Circular Linked List */
#include <stdio.h>
#include <conio.h>
#include <alloc.h>   /* malloc(), free() */

struct node
{
	int data;
	struct node *next;
};

/* fn decls */
struct node *createsll(struct node *);
void displayll(struct node *);
/* struct node *insertatbeg(struct node *);
void insertatend(struct node *);
struct node *deleteatbeg(struct node *);
struct node *deleteatend(struct node *);
struct node *deleteatpos(struct node *);
struct node *insertatpos(struct node *);
void bub_sort(struct node *);
void display_revll(struct node *);
   */

void main()
{
	struct node *scl;
	int choice;
	scl = NULL;  /* v. imp - LL is initialised */
	while (1)
	{
		clrscr();
		printf("Operations on SCLL\n");
		printf("1. Create LL\n");
		printf("2. Display LL\n");
		printf("3. To Add a Node at the begining of LL\n");
		printf("4. To Add a Node at the end of LL\n");
		printf("5. To Delete a Node at the begining of LL\n");
		printf("6. To Delete a Node at the end of LL\n");
		printf("7. To Delete a Node at given position\n");
		printf("8. To Insert a Node at given position\n");
		printf("9. To Sort the LL\n");
		printf("10. To Display the LL in Reverse Order\n");
		printf("11. Exit\n\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				scl = createsll(scl);
				break;

			case 2:
				displayll(scl);
				break;
					/*
			case 3:
			       sl = insertatbeg(sl);
			       break;

			case 4:
			       insertatend(sl);
			       break;

			case 5:
				sl = deleteatbeg(sl);
				break;

			case 6:
				sl = deleteatend(sl);
				break;

			case 7:
				sl = deleteatpos(sl);
				break;

			case 8:
			       sl = insertatpos(sl);
			       break;

			case 9:
				bub_sort(sl);
				break;

			case 10:
				display_revll(sl);
				break;
					  */
			case 11:
				exit();

			default :
				printf("Error in choice. Try again");
		}
		getch();
	}
}

struct node *createsll(struct node *scl)
{
	struct node *newnode, *temp;
	char ask = 'y';
	while (ask == 'y' || ask == 'Y')
	{
		/* allocate memory for newnode */
		newnode = (struct node *) malloc(sizeof(struct node));
		/* malloc() returns a void pointer & hence we need to
		   type cast it */
		printf("Enter data for newnode :- ");
		scanf("%d",&newnode->data);
		/* check whether it is 1st node of LL */
		if (scl == NULL)
		{
			newnode->next = newnode;
			scl = newnode;
			temp = newnode;
		}
		else
		{
			newnode->next = scl;
			temp->next = newnode;
			temp = newnode;
		}
		flushall();
		printf("Add more nodes ? ");
		scanf("%c",&ask);
	}
	return scl;
}

void displayll(struct node *scl)
{
	struct node *temp;
	/* validation */
	if (scl == NULL)
	{
		printf("1st create LL");
		return;
	}
	temp = scl;
	while (1)
	{
		printf("%d ",temp->data);
		temp = temp->next;
		if (temp == scl)
			break;
	}
	printf("\n\n");
	/* alternative method */
	do
	{
		printf("%d ",temp->data);
		temp = temp->next;
	} while (temp != scl);

}

struct node *insertatbeg(struct node *sl)
{
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("Enter data for 1st node :- ");
	scanf("%d",&newnode->data);
	/* set the links */
	newnode->next = sl;
	return newnode;
}

void insertatend(struct node *sl)
{
	struct node *newnode, *temp;  /* to traverse to last node */
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("Enter data for last node :- ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;  /* as it is last node */
	/* traverse to last node */
	temp = sl;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = newnode;
}

struct node *deleteatbeg(struct node *sl)
{
	struct node *temp;
	temp = sl;
	sl = sl->next;  /* sl points to next node */
	free(temp);
	return sl;
}

struct node *deleteatend(struct node *sl)
{
	struct node *temp;
	/* case 1, only single node in LL */
	if (sl->next == NULL)
	{
		free(sl);
		return NULL;   /* imp as LL is destroyed */
	}
	temp = sl;
	/* case - 2, multiple nodes */
	/* get temp to 2nd last node */
	while (temp->next->next != NULL)
		temp = temp->next;

	free(temp->next);
	temp->next = NULL;
	return sl;  /* unchanged sl */
}

struct node *deleteatpos(struct node *sl)
{
	struct node *temp1, *temp2;
	int pos, cntr = 0;
	printf("Enter the position of node to delete :- ");
	scanf("%d",&pos);
	/* case - 1, to delete the begining node */
	if (pos == 1)
	{
		temp1 = sl;
		sl = sl->next;
		free(temp1);
		return sl;   /* changed sl */
	}
	/* case - 2, to delete any other node in LL, we first need to
	   confirm whether that position exists or not */
	/* count the no of nodes in LL */
	temp1 = sl;
	while (temp1 != NULL)  /* this means temp1 is pointing to some valid node */
	{
		cntr++;
		temp1 = temp1->next;
	}
	/* validation */
	if (pos > cntr || pos < 1)
	{
		printf("Invalid Position");
		return sl; /* unchanged sl */
	}
	/* now position temp2 on node to delete & it's previous node will
	   be temp1 */
	cntr = 2;   /* it is temp2's position */
	temp1 = sl;
	temp2 = sl->next;
	while (temp2 != NULL)
	{
		if (pos == cntr)
			break;

		cntr++;
		temp1 = temp2;
		temp2 = temp2->next;
	}
	/* set the links */
	temp1->next = temp2->next;
	free(temp2);
	return sl;  /* unchanged */
}

struct node *insertatpos(struct node *sl)
{
	struct node *temp1, *temp2, *newnode;
	int pos, cntr = 0;
	printf("Enter the position of node :- ");
	scanf("%d",&pos);
	if (pos == 1)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter data for newnode :- ");
		scanf("%d",&newnode->data);
		newnode->next = sl;
		return newnode;  /* bcoz newnode becomes the 1st node */
	}
	/* count the no of nodes in LL */
	temp1 = sl;
	while (temp1 != NULL)
	{
		cntr++;
		temp1 = temp1->next;
	}
	/* validation */
	if (pos < 1 || pos > cntr + 1)
	{
		printf("Invalid position");
		return sl;  /* unchanged */
	}
	cntr = 2;
	temp1 = sl;
	temp2 = sl->next;
	while (temp2 != NULL)
	{
		if (pos == cntr)
			break;

		cntr++;
		temp1 = temp2;
		temp2 = temp2->next;
	}
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter data for newnode :- ");
	scanf("%d",&newnode->data);
	/* set the links */
	temp1->next = newnode;
	newnode->next = temp2;
	return sl;
}

void bub_sort(struct node *sl)
{
	struct node *temp1, *temp2;
	int i, j, temp, cntr = 0;  /* cntr is used to count the no of nodes in LL */
	temp1 = sl;
	while (temp1 != NULL)
	{
		cntr++;
		temp1 = temp1->next;
	}
	/* outer loop */
	for (i=1;i<cntr;i++)
	{
		temp1 = sl;
		temp2 = sl->next;
		for (j=0;j<cntr-i;j++)
		{
			if (temp1->data > temp2->data)
			{
				/* swap data of nodes */
				temp = temp1->data;
				temp1->data = temp2->data;
				temp2->data = temp;
			}
			temp1 = temp2;
			temp2 = temp2->next;
		}
	}
}

void display_revll(struct node *temp)
{
	if (temp != NULL)
	{
		display_revll(temp->next);
		printf("%d ",temp->data);
	}
}


















































