/* Quick Sort technique to sort the elements of an array */
#include <stdio.h>
#include <conio.h>
#define SIZE 50   /* Preprocessor */

/* fn decls */
void accept(int []), sort(int [],int,int);

int noe;

void main()
{
	int nos[SIZE];
	clrscr();
	printf("Enter the no of elements :- ");
	scanf("%d",&noe);
	accept(nos);
	sort(nos,0,noe-1);
	getch();
}

void accept(int nos[])
{
	int i;
	printf("Enter %d no of elements :- ",noe);
	for (i=0;i<noe;i++)
		scanf("%d",&nos[i]);
}

void sort(int nos[],int l,int h)
{
	int pivot_el = nos[l], low = l+1, high = h, temp, i;
	static int cntr;
	/* keep all elements < pivot element to left & > pivot element to
	the right. Do this process till low & high do not cross each other */
	while (low <= high)
	{
		while (nos[low] < pivot_el)  /* increment low till element
						on LHS is < pivot el */
			low++;

		while (nos[high] > pivot_el)  /* decrement high till element
						  on RHS is > pivot el */
			high--;

		if (low < high)
		{
			temp = nos[low];
			nos[low] = nos[high];
			nos[high] = temp;
			low++;
			high--;   /* continue the comparison */
		}
	}
	/* now fix the position of pivot element (Final position) */
	nos[l] = nos[high];
	nos[high] = pivot_el;
	/* now 2 partitions are created on either side of pivot element.
	   send these partitions again for quick sort as long as length
	   of partition is > 1 */
	high--;  /* to get rid of pivot el in left partition */

	cntr++;
	printf("\nAfter pass %d,",cntr);
	for (i=0;i<noe;i++)
		printf(" %d",nos[i]);

	if (l < high)
		sort(nos,l,high);  /* left partition */

	if (low < h)
		sort(nos,low,h);
}











