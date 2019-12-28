/* Bubble Sort technique to sort the elements of an array */
#include <stdio.h>
#include <conio.h>
#define SIZE 50   /* Preprocessor */

/* fn decls */
void accept(int [],int), sort(int [],int);


void main()
{
	int nos[SIZE], noe;
	clrscr();
	printf("Enter the no of elements :- ");
	scanf("%d",&noe);
	accept(nos,noe);
	sort(nos,noe);
	getch();
}

void accept(int nos[],int noe)
{
	int i;
	printf("Enter %d no of elements :- ",noe);
	for (i=0;i<noe;i++)
		scanf("%d",&nos[i]);
}

void sort(int nos[],int noe)
{
	int i, j, flag, comp_cntr = 0, temp;
	for (i=1;i<noe;i++)
	{
		flag = 0;  /* imp - to initialise here only */
		/* comparison loop */
		for (j=0;j<noe-i;j++)
		{
			comp_cntr++;
			if (nos[j] > nos[j+1])
			{
				temp = nos[j];
				nos[j] = nos[j+1];
				nos[j+1] = temp;
				flag = 1;  /* update flag */
			}
		}
		printf("\nAfter iteration %d, array is ",i);
		for (j=0;j<noe;j++)
			printf("%d ",nos[j]);

		if (!flag)   /* (flag == 0) */
			break;
	}
	printf("\n\nNo. of comparisons are %d",comp_cntr);
}















