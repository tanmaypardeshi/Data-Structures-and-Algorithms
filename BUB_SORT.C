/*bubble sort*/

#include<stdio.h>
#include<conio.h>
#define SIZE 50

void sort(int [],int);
void accept(int [],int);

void main()
{
	int noe,nos[SIZE];
	clrscr();
	printf("Enter no of elements:- ");
	scanf("%d",&noe);
	accept(nos,noe);
	sort(nos,noe);
	getch();
}

void accept(int nos[],int noe)
{
	int i;
	printf("Enter elements:- ");
	for(i=0;i<noe;i++)
		scanf("%d",&nos[i]);
}

void sort(int nos[],int noe)
{
	int i,j,comp_cntr=0,temp,flag,swap_cntr=0;
	for(i=1;i<noe;i++)
	{
		flag=0;
		for(j=0;j<noe-i;j++)
		{
			comp_cntr++;
			if(nos[j]>nos[j+1])
			{
				swap_cntr++;
				temp=nos[j];
				nos[j]=nos[j+1];
				nos[j+1]=temp;
				flag=1;
			}

		}
		printf("\nAfter iteration %d array is ",i+1);

		for(j=0;j<noe;j++)
			printf("%d ",nos[j]);

		if(!flag)
			break;
	}
	printf("\nThe no. of comparisons are:- %d",comp_cntr);
	printf("\nThe no. of swappings are:- %d",swap_cntr);
}

