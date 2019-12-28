/* Accept a digraph from user & display OD & ID of each vertex */
#include <stdio.h>
#include <conio.h>


void main()
{
	int am[10][10], nov, i, j, od, id;
	clrscr();
	printf("Enter the no of vertices for the graph :- ");
	scanf("%d",&nov);
	printf("Enter the data for the graph\n");
	for (i=0;i<nov;i++)
	{
		for (j=0;j<nov;j++)
		{
			printf("Is there an edge between vertex %d and vertex %d :- ",i+1,j+1);
			scanf("%d",&am[i][j]);
		}
	}
	for (i=0;i<nov;i++)
	{
		id = od = 0;
		for (j=0;j<nov;j++)
		{
			od += am[i][j];  /* i is constant, j is variable */
			id += am[j][i];  /* j is row, i is col */
		}
		printf("\nFor vertex %d, OD = %d, ID = %d",i+1,od,id);
	}
	getch();
}