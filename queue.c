#include <stdio.h>
#include<stdlib.h>
#define maxsize 10

void enqueue(int[], int*, int*, int, int);
void dequeue(int[], int*, int*);
void display(int[], int, int);

void main()
{
	int res = 1;
	int ch, item;
	int queue[maxsize];
	int f = -1;
	int r = -1;
	
	do
	{
		printf("\n\n*****Menu*****");
		printf("\n1. Enqueue");
		printf("\n2. Dequeue");
		printf("\n3. Dispaly");
		printf("\n4. Exit");
		printf("\nYour Choice:");
		
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("Enter Item to enqueue:");
					scanf("%d",&item);
					enqueue(queue, &f, &r, item, maxsize);
					break;
			case 2: printf("Dequeue:");
					dequeue(queue, &f, &r);
					break;
			case 3: printf("Display:");
					display(queue,f,r);
					break;
			case 4: exit(0);
					break;
			default:printf("\nDo You wanna continue?:");
					scanf("%d",&res);
		}
	}
	while(res==1);
}

void enqueue(int queue[maxsize], int *f, int *r, int item, int max)
{
	//to check overflow
	if(*r == max-1)
	{
		printf("Overflow!");
	}
	else
	{
		if(*r == -1)
		{
			*r = *r + 1;
			*f = *f + 1;
		}
		else
		{
			*r = *r + 1;
		}
	//enqueing
	queue[*r] = item;
	}
}

void dequeue(int queue[maxsize], int *f, int *r)
{
	//to check underflow
	if(*f == -1)
	{
		printf("Underflow!");
	}
	else
	{
		if(*f == *r)
		{
			*f = -1;
			*r = -1;
		}
		else
		{
			*f = *f + 1;
		}
	}
}
void display(int queue[maxsize], int f, int r)
{
	int i;
	if(f==-1&&r==-1)
	{
		printf("Empty!");
	}
	else
	{
		for(i=f; i<=r; i++)
		{
			printf("%d ",queue[i]);
		}
	}
}
