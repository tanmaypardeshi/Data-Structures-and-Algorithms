/* Insertion Sort technique to sort the elements of an array */
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
	int i, j, key;
	for (i=1;i<noe;i++)
	{
		key = nos[i];
		j = i - 1;
		/* comparison loop */
		while (j >= 0 && nos[j] > key)
		{
			nos[j+1] = nos[j];
			j=j-1;
		}
		nos[j+1] = key;
		printf("\nAfter iteration %d, array is ",i);
		for (j=0;j<noe;j++)
			printf("%d ",nos[j]);

	}
}















