#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "LinkedList.h"


int link_my_struct(struct family ** myArray, int numOfNodes)
{
	assert(myArray);
	/*{
		return -1;
	}*/
	if (myArray==NULL)												// Error if the input array is null
	{
		return -1;
	}
	else if (numOfNodes < 2)										// Error if less than 2 nodes
	{
		return -2;
	}
	else
	{
		for (int i = 0; i < (numOfNodes - 1); i++)
		{
			(*(myArray + i))->next_ptr = *(myArray + i + 1);		// Links to the next node
		}

		for (int i = 1; i < (numOfNodes); i++)
		{
			(*(myArray + i))->previous_ptr = (*(myArray + i-1));	// Links to the previous node
		}
		return 0;
	}
}

int print_the_struct(struct family * headNode)
{
	int returnValue = -3;
	struct family * currentNode_ptr = NULL;
	int i = 0;

	if (!headNode)
	{
		returnValue = -1;
	}
	else if (!(headNode->next_ptr))			// Ensures the head node points to another node
	{
		returnValue = -2;
	}
	else
	{
		currentNode_ptr = headNode;			// Sets the surrent pointer to the value of the headnode

		while (currentNode_ptr)
		{
			printf("NODE #%d\n", i);
			printf("Index: \t\t%d\n", currentNode_ptr->index);
			printf("Name: \t\t%s\n", currentNode_ptr->name);
			printf("Initials: \t%s\n", currentNode_ptr->initials);
			printf("Age: \t\t%d\n", currentNode_ptr->age);
			printf("Next Node: \t0x%p\n", currentNode_ptr->next_ptr);
			printf("Current Node: \t0x%p\n", currentNode_ptr);
			printf("Previous Node: \t0x%p\n\n", currentNode_ptr->previous_ptr);
			
			currentNode_ptr = currentNode_ptr->next_ptr;

			i++;
		}
		returnValue = i;
	}

	return returnValue;
}

struct family * add_a_struct(struct family * headnode, struct family * newNode, int addAtThisPosition)
{
	struct family * currentNode_ptr = NULL;
	struct family * return_ptr = NULL;
	currentNode_ptr = headnode;

	int i = 0;

	if (addAtThisPosition == 0)										// If adding a new head node
	{
		newNode->next_ptr = headnode;
		headnode = newNode;
		return_ptr = headnode;
	}
	else															// Adds a node in the middle
	{
		for (i = 1; i < addAtThisPosition; i++)
		{
			currentNode_ptr = currentNode_ptr->next_ptr;			// Sets the current node to the next node
		}
		newNode->next_ptr = currentNode_ptr->next_ptr;				// Sets the new node to the next node
		currentNode_ptr->next_ptr = newNode;						// Sets the current node to the new node
		currentNode_ptr->next_ptr->previous_ptr = newNode;			// Sets the 
		newNode->previous_ptr = currentNode_ptr;
		return_ptr = headnode;
	}
	
	return return_ptr;
}

void clear_list(struct family * headnode)
{

}

struct family * create_node(int index, char name[20], char initials, int age)
{
	//int * ptr = 0;
	
	struct family *ptr = (struct family *)malloc(sizeof(struct family));
	ptr->name = name;
	ptr->age = age;
	ptr->initials = initials;

}



int main(void)
{
	int i = 0;
	int numStructVars = 0;
	struct family * returnValue = NULL;
	int * errorCode = 0;
	struct family * next_ptr = NULL;
	struct family * aNewNode_ptr = NULL;
	

	struct family familyVariable1 = { 1, "Eric", "ESS",41, NULL };
	struct family familyVariable2 = { 2, "Senay","SS", 40, NULL };
	struct family familyVariable3 = { 3, "Daniel","DMS", 12, NULL };
	struct family familyVariable4 = { 4, "Frosty","FS",3,NULL };

	_flushall();
	struct family * myArray[4] = { &familyVariable1, &familyVariable2, &familyVariable3, &familyVariable4 };
	numStructVars = sizeof(myArray) / sizeof(*(myArray));		// Determines the number of variables of the array
	
	assert(myArray);
	assert(numStructVars);
	link_my_struct(myArray, numStructVars);						// Passes to the function to link the nodes together.
	
	next_ptr = &familyVariable1;								// Sets the value of the pointer to the address of the first element of the array

	assert(next_ptr!=NULL);
	printf("The Original list.\n");
	print_the_struct(next_ptr);									// Passes the first element to the print function

	struct family aNewNode = { 5, "Nick", "NAS", 35, NULL };	// adds new information to the list
	aNewNode_ptr = &aNewNode;

	int insertPosition = 2;

	assert(insertPosition > 0);
	add_a_struct(next_ptr, aNewNode_ptr, insertPosition);

	printf("The new list. \n");
	print_the_struct(next_ptr);
	
	getchar();
	getchar();
	return 0;
}
