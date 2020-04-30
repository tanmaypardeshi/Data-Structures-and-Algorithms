/* Linear Search - To search the record of a student */
#include <stdio.h>
#include <conio.h>
#define SIZE 50

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
		printf("Rrcord found after %d no. of comparisons",pos+1);
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
	int i;
	/* search begins from 1st record */
	for (i=0;i<nor;i++)
	{
		if (rno == recs[i].rollno)
			return i;    /* search successful, terminate the process */
	}
	return -1;  /* search unsuccessful, terminate the process */
}























