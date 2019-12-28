/* Merging of 2 Sorted LLs into 1 list */
#include <stdio.h>
#include <conio.h>
#include <alloc.h>

struct node
{
	int data;
	struct node *next;
};

/* fn declarations */
struct node *createlist(struct node *);
void displaylist(struct node *);
struct node *mergelist(struct node *,struct node *,struct node *);
void bub_sort(struct node *);

void main()
{
	struct node *sl1 = NULL, *sl2 = NULL, *sl3 = NULL;
	clrscr();
	printf("Enter LL1 :- \n");
	sl1 = createlist(sl1);
	printf("\nEnter LL2 :- \n");
	sl2 = createlist(sl2);
	bub_sort(sl1);
	bub_sort(sl2);
	sl3 = mergelist(sl1,sl2,sl3);
	clrscr();
	printf("LL1 is :-\n");
	displaylist(sl1);
	printf("\n\nLL2 is :-\n");
	displaylist(sl2);
	printf("\n\nMerged List is :-\n");
	displaylist(sl3);
	getch();
}

struct node *createlist(struct node *sl)
{
	struct node *newnode, *temp;
	char ask = 'y';
	while (ask == 'y')
	{
		newnode = (struct node *) malloc(sizeof(struct node));
		printf("Enter data for newnode :- ");
		scanf("%d",&newnode->data);
		newnode->next = NULL;
		/* check whether it is 1st node of LL */
		if (sl == NULL)
		{
			sl = newnode;
			temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
		flushall();
		printf("Add more nodes ? ");
		scanf("%c",&ask);
	}
	return sl;
}

void displaylist(struct node *sl)
{
	while (sl != NULL)
	{
		printf("%d ",sl->data);
		sl = sl->next;
	}
}

void bub_sort(struct node *sl)
{
	int i, j, temp, cntr = 0;
	struct node *t1, *t2;
	/* count the no. of nodes in LL */
	t1 = sl;
	while (t1 != NULL)
	{
		cntr++;
		t1 = t1->next;
	}
	for (i=1;i<cntr;i++)
	{
		t1 = sl;
		t2 = sl->next;
		for (j=1;j<=cntr-i;j++)
		{
			if (t1->data > t2->data)
			{
				temp = t1->data;
				t1->data = t2->data;
				t2->data = temp;
			}
			t1 = t2;
			t2 = t2->next;
		}
	}
}

struct node *mergelist(struct node *sl1,struct node *sl2,struct node *sl3)
{
	struct node *newnode, *temp;
	/* Compare the data of LL1 and LL2 & copy the value from a node
	   of LL which is less. Comparison of nodes is possible, till
	   nodes exist in both the lists */
	while (sl1 != NULL && sl2 != NULL)
	{
		newnode = (struct node *) malloc(sizeof(struct node));
		newnode->next = NULL;
		if (sl1->data < sl2->data)
		{
			newnode->data = sl1->data;
			sl1 = sl1->next;
		}
		else
		{
			newnode->data = sl2->data;
			sl2 = sl2->next;
		}
		/* attach newnode to sl3 */
		/* 1st check whether it is 1st node of sl3 */
		if (sl3 == NULL)
		{
			sl3 = newnode;
			temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
	}  /* end of while loop for comparing nodes of LL1 and LL2 */
	/* case - 1, LL2 is exhausted. Now copy remaining nodes of LL1
	  in LL3 */
	while (sl1 != NULL)
	{
		newnode = (struct node *) malloc(sizeof(struct node));
		newnode->next = NULL;
		newnode->data = sl1->data;
		sl1 = sl1->next;
		/* attach newnode to sl3 - imp */
		temp->next = newnode;
		temp = newnode;
	}
	/* case - 2, LL1 is exhausted. Now copy remaining nodes of LL2
	  in LL3 */
	while (sl2 != NULL)
	{
		newnode = (struct node *) malloc(sizeof(struct node));
		newnode->next = NULL;
		newnode->data = sl2->data;
		sl2 = sl2->next;
		/* attach newnode to sl3 - imp */
		temp->next = newnode;
		temp = newnode;
	}
	return sl3;
}








































