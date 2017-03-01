#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int item;
	struct Node *next;
}node;


//function to add node
node* add(node *n, int item)
{
	//create a newnode by allocating it some memory
	node *newnode, *ptr;
	newnode = (node*)malloc(sizeof(node));

	//in case the RAM is not available
	if(newnode == NULL)
	{
		printf("\nMemory Not Avialble!");
		return n;
	}
	else
	{
		newnode->item = item;
		newnode->next = NULL;

		//in case the LL is empty
		if(n == NULL)
		{
			n = newnode;
		}
		else
		{
			ptr = n;

			//traverse the LL until last node
			while(ptr->next != NULL)
			{
				ptr = ptr->next;
			}

			//now I hav got the address of last node in LL
			ptr->next = newnode; //overwrite the NULL value stored previously with address of newnode
		}
		return n;
	}

}

//function to display the LL
void display(node *n)
{
	node *ptr = n;
	//treaverse the whole LL
	while(ptr!=NULL)
	{
		printf("%d ",ptr->item);
		ptr = ptr->next;
	}
}

//function to remove duplicates
node* delduplicate(node *n)
{
	node *out, *in;//out for parent item, in for child(coming after parent)
	out = n;

	if(out==NULL)
	{
		printf("\nNo Elements to Delete");
	}
	else
	{
		//traverse for parent
		while(out != NULL && out->next != NULL)
		{
			in = out;

			//traverse for child
			while(in->next != NULL)
			{
				//check condition that parent matches child
				if(out->item == in->next->item)
				{
					//if true, update in->next skipping next node
					in->next = in->next->next;
				}
				else
				{
					//else simply update child for traverse
					in = in->next;
				}
			}
			//update parent for traverse
			out = out->next;
		}
	}
	return n;
}

//main starts here
void main()
{
	//variables
	node *n = NULL;
	int ch, res = 1, item;

	//menu starts here

	do
	{
		printf("\n\n*****Menu*****");
		printf("\n1.Add Item to Linked List");
		printf("\n2.Remove Duplictes in Linked List");
		printf("\n3.Display The Linked List");
		printf("\nYour Chioce:");
		scanf("%d",&ch);

		//switching choice
		switch(ch)
		{
			case 1:	printf("\nInput Item To Enter:");
					scanf("%d",&item);
					n = add(n,item);
					break;
			case 2:	printf("\nRemoving Duplicates");
					n = delduplicate(n);
					break;
			case 3: display(n);
					break;
			default:printf("\nWrong Choice. Wanna Continue?");
					scanf("%d",&res);
		}
	}
	while(res==1);
}