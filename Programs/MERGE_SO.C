/* Merge Sort technique to sort the elements of an array */
#include <stdio.h>
#include <conio.h>
#define SIZE 50   /* Preprocessor */

/* fn decls */
void accept(int [],int), partition(int [],int,int), merge(int [],int,int,int,int);

void main()
{
	int nos[SIZE], i, noe;
	clrscr();
	printf("Enter the no of elements :- ");
	scanf("%d",&noe);
	accept(nos,noe);
	partition(nos,0,noe-1);
	printf("\nAfter sorting, elements are\n");
	for (i=0;i<noe;i++)
		printf("%d ",nos[i]);

	getch();
}

void accept(int nos[],int noe)
{
	int i;
	printf("Enter %d no of elements :- ",noe);
	for (i=0;i<noe;i++)
		scanf("%d",&nos[i]);
}

void partition(int nos[],int i,int j)
{
	int mid;
	if (i < j)
	{
		mid = (i+j)/2;
		partition(nos,i,mid);  /* left partition */
		partition(nos,mid+1,j);  /* right partition */
		merge(nos,i,mid,mid+1,j);  /* 2 partitions i.e. left & right */
	}
}

void merge(int nos[],int i1,int j1,int i2,int j2)
{
	int a, b, k, temp[SIZE];
	/* a to traverse the left partition i.e. from i1 to j1
	   & b for right partition i.e. from i2 to j2.
	   Also temp[] will store sorted elements & k to traverse temp[] */
	k = 0;
	a = i1;
	b = i2;
	/* compare left & right partitions & copy the min element.
	  Also this comparison will take place till elements exist in
	  both arrays */
	while (a <= j1 && b <= j2)
	{
		if (nos[a] < nos[b])
		{
			temp[k] = nos[a];
			a++; k++;
		}
		else
		{
			temp[k] = nos[b];
			b++; k++;
		}
	}
	/* case - 1, left partition elements copied, stop comparison &
	   copy only rigth partition elements */
	while (b <= j2)
	{
		temp[k] = nos[b];
		b++; k++;
	}
	/* case - 2, reverse of above */
	while (a <= j1)
	{
		temp[k] = nos[a];
		a++; k++;
	}
	/* now copy the elements from temp[] starting at 0 position to
	   nos[] @ appropriate positions */
	k = 0;
	for (a=i1;a<=j2;a++)
	{
		nos[a] = temp[k];
		k++;
	}
}






















