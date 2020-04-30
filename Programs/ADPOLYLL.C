/* Addition of polynomials using Linked List (Dynamic) */
#include <stdio.h>
#include <conio.h>
#include <alloc.h>

struct node
{
	int coef, pow;
	struct node *next;
};

/* fn declarations */
struct node *createpoly(struct node *);
void displaypoly(struct node *);
struct node *addpoly(struct node *,struct node *,struct node *);

void main()
{
	struct node *p1, *p2, *p3;
	p1 = NULL;
	p2 = NULL;
	p3 = NULL;
	clrscr();
	printf("Enter poly 1 :- \n");
	p1 = createpoly(p1);
	printf("Enter poly 2 :- \n");
	p2 = createpoly(p2);
	p3 = addpoly(p1,p2,p3);
	clrscr();
	printf("Poly 1 is :- \n");
	displaypoly(p1);
	printf("\n\nPoly 2 is :- \n");
	displaypoly(p2);
	printf("\n\nAdded poly is :- \n");
	displaypoly(p3);
	getch();
}

struct node *createpoly(struct node *p)
{
	struct node *newnode, *temp;
	int i, no_terms;
	printf("Enter the no. of terms for poly :- ");
	scanf("%d",&no_terms);
	printf("\nEnter the terms in DESC order by power :- \n");
	for (i=0;i<no_terms;i++)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->next = NULL;
		printf("Enter the coeff & power :- ");
		scanf("%d %d",&newnode->coef,&newnode->pow);
		/* check whether it is 1st node of LL */
		if (p == NULL)
		{
			p = newnode;
			temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
	}
	return p;
}

void displaypoly(struct node *p)
{
	while (p != NULL)
	{
		if (p->coef > 0 && p->pow > 0)
			printf(" + %dx%d ",p->coef,p->pow);
		else if (p->coef > 0 && p->pow == 0)
			printf(" + %d ",p->coef);
		else if (p->coef < 0 && p->pow > 0)
			printf(" %dx%d ",p->coef,p->pow);
		else /* if (p->coef < 0 && p->pow == 0) */
			printf(" %d ",p->coef);

		/* suppress the terms where coeff = 0 */

		p = p->next;
	}
}

struct node *addpoly(struct node *p1,struct node *p2,struct node *p3)
{
	struct node *newnode, *temp;
	/* compare the pow of 2 terms of p1 and p2 & add them only if
	   there pow is same. Comparison continues till terms exist in
	   both polys */
	while (p1 != NULL && p2 != NULL)
	{
		/* we are not creating a newnode if addition of coeff of
			2 terms is 0 */
		if (p1->pow == p2->pow)
		{
			if (p1->coef + p2->coef == 0)
			{
				p1 = p1->next;
				p2 = p2->next;
				continue;
			}
		}
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->next = NULL;
		if (p1->pow == p2->pow)
		{
			newnode->coef = p1->coef + p2->coef;
			newnode->pow = p1->pow;
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			if (p1->pow > p2->pow)
			{
				newnode->coef = p1->coef;
				newnode->pow = p1->pow;
				p1 = p1->next;
			}
			else
			{
				newnode->coef = p2->coef;
				newnode->pow = p2->pow;
				p2 = p2->next;
			}
		}
		/* check whether it is 1st node of p3 */
		if (p3 == NULL)
		{
			p3 = newnode;
			temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
	}   /* end of comparison loop */
	/* case - 1, p2 is exhausted, copy terms of p1 in p3 */
	while (p1 != NULL)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->next = NULL;
		newnode->coef = p1->coef;
		newnode->pow = p1->pow;
		/* attach newnode to p3 */
		temp->next = newnode;
		temp = newnode;
		p1 = p1->next;
	}
	/* case - 2, p1 is exhausted, copy terms of p2 in p3 */
	while (p2 != NULL)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->next = NULL;
		newnode->coef = p2->coef;
		newnode->pow = p2->pow;
		/* attach newnode to p3 */
		temp->next = newnode;
		temp = newnode;
		p2 = p2->next;
	}
	return p3;
}










































