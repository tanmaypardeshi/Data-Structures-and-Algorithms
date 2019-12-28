/* Selection Sort technique to sort the elements of an array */
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
	int i, j, comp_cntr = 0, swap_cntr = 0, temp, min;
	/* min is the position of element which is least no */
	for (i=0;i<noe-1;i++)
	{
		min = i;
		/* comparison loop */
		for (j=i+1;j<noe;j++)
		{
			comp_cntr++;
			if (nos[j] < nos[min])
				min = j;
		}
		/* swap element @ pos i with element @ pos min */
		temp = nos[i];
		nos[i] = nos[min];
		nos[min] = temp;
		swap_cntr += 3;

		printf("\nAfter iteration %d, array is ",i);
		for (j=0;j<noe;j++)
			printf("%d ",nos[j]);

	}
	printf("\n\nNo. of comparisons are %d",comp_cntr);
	printf("\nNo of swaps are %d",swap_cntr);
}















