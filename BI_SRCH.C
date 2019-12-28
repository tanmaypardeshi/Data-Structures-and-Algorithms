/* Binary Search - To search the record of a student */
#include <stdio.h>
#include <conio.h>
#define SIZE 50

int comp_cntr = 0;  /* imp as our fn cannot return 2 values, we have to
			take this as a global vars */

struct student
{
	int rollno;
	char name[10];
};

/* fn decls */
void accept(struct student [],int);
int search(struct student [],int,int);
/* search fns are always int fns bcoz they return the position of a
   record in a table */

void main()
{
	struct student recs[SIZE];
	int nor, rno, pos;
	clrscr();
	printf("Enter the no of records :- ");
	scanf("%d",&nor);
	accept(recs,nor);
	printf("Enter the rollno to search :- ");
	scanf("%d",&rno);
	pos = search(recs,nor,rno);
	if (pos == -1)
		printf("Record with rollno %d not found",rno);
	else
	{
		printf("Rrcord found after %d no. of comparisons",comp_cntr);
		printf("\nRollno - %d, Name - %s",rno,recs[pos].name);
	}
	getch();
}

void accept(struct student recs[],int nor)
{
	int i;
	for (i=0;i<nor;i++)
	{
		printf("Enter rollno & name :- ");
		scanf("%d %s",&recs[i].rollno,recs[i].name);
	}
}

int search(struct student recs[ ],int nor,int rno)
{
	int top = 0, bottom = nor-1, mid;
	while (top <= bottom)
	{
		mid = (top+bottom) / 2;
		comp_cntr++;
		if (rno == recs[mid].rollno)
			return mid;
		else
		{
			if (rno < recs[mid].rollno)
				/* search top half */
				bottom = mid - 1;
			else
				top = mid + 1;
		}
	}
	return -1;  /* search failed */
}






















