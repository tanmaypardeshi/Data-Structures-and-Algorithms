/*Example of linear/sequential search*/

#include<stdio.h>
#include<conio.h>
#define SIZE 50

struct student
{
	int rollno;
	char name[10];
};

/*fn decln*/

void accept(struct student [],int);
int search(struct student [],int,int);

/*search fns are always int fns as they return position of record in a table*/

void main()
{
	struct student recs[SIZE];
	int nor,rno,pos;
	clrscr();
	printf("Enter nor:- ");
	scanf("%d",&nor);
	accept(recs,nor);
	printf("Enter roll no. to search:- ");
	scanf("%d",&rno);

	pos=search(recs,nor,rno);

	if(pos==-1)
		printf("Recs with rollno. %d not found",rno);
	else
	{
		printf("Rec. found after %d no. of comparisons",pos+1);
		printf("\nRoll no:- %d, Name:- %s",rno,recs[pos].name);
	}
	getch();
}

void accept(struct student recs[],int nor)
{
	int i;
	for(i=0;i<nor;i++)
	{
		printf("Enter rollno. and name:- ");
		scanf("%d %s",&recs[i].rollno,recs[i].name);
	}
}

int search(struct student recs[],int nor,int rno)
{
	int i;
	for(i=0;i<nor;i++)
	{
		if(recs[i].rollno==rno)
			return i;
	}
	return -1;
}