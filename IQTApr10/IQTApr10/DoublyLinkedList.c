#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoublyLinkedList.h"

#define MAX_SEL_LENGTH 6 			//maximum size of the user input 
#define CMD_PREFIX 3 			//size of the first [0:3] chars in a command, used to determine the correct type of command (-ins or -del)

/*C Programming - Evaluation Exam 
This is a doubly linked-list intended to assess the examinee's capabilities with loops, if-else conditions, functions, pointers, and dynamic memory
Fill in the functions that have been left incomplete
Be sure to correctly handle the pointers when inserting and deleting from the list.
Be sure to test the -insp and -dell linked-list operations with values of 0 and the # of nodes in the list

Good luck!!*/		


int main(void)
{
	char selection[MAX_SEL_LENGTH] = "-loop";	//arbitrary value, just to keep the loop going until valid input is received
	int pos = 0;
	struct Node* newNode = NULL;
	char userInput[MAX_STR_LENGTH];
	
	while(strncmp(selection, "-exit", MAX_SEL_LENGTH) != 0)
	{
		printf("\nLinked list commands (-help for list of commands): ");
		scanf("%s", selection);
		
		if(strncmp(selection, "-help", MAX_SEL_LENGTH) == 0)
		{
			printf("\nInsert at head of list: -insh");
			printf("\nInsert at tail of list: -inst");
			printf("\nInsert at position: -insp");
			printf("\nPrint list: -prnt");
			printf("\nPrint list reverse: -prnr");
			printf("\nDelete from list: -dell");
			printf("\nExit: -exit");
			
		}
		
		else if(strncmp(selection, "-ins", CMD_PREFIX ) == 0)	//check the first 3 characters 
		{
			printf("Please enter a string.\n");
			getchar();
			//scanf("%s", &userInput);
			//fgets(userInput, 20, stdin);
			scanf("%[^\n]", userInput);
			
			newNode = CreateNewNode(userInput);				
			
			if(newNode)
			{
			
				if(selection[4] == 'h')			//last character determines the correct insert function to call
				{
					InsertNodeAtHead(newNode);
				}
				
				else if(selection[4] == 't')
				{
					InsertNodeAtTail(newNode);
				}
				
				else if(selection[4] == 'p')
				{
					printf("\npos: ");
					scanf("%d", &pos);		
					
					if(pos >= 0)
					{
						InsertNodeAtPosition(newNode, pos);
					}
					
					else
					{
						printf("\nError: invalid position entered");
					}
				}
			}
			
			else
			{
				printf("\nError encountered when creating new node");
			}
		}
		
		else if(strncmp(selection, "-prn", CMD_PREFIX) == 0)
		{

			if(selection[4] == 't')
			{
				PrintList();
			}
				
			else if (selection[4] == 'r')
			{
				PrintReverse();
			}
		}
			
		
		else if(strncmp(selection, "-dell", MAX_SEL_LENGTH) == 0)
		{
			printf("\npos: ");
			scanf("%d", &pos);
			
			if(pos >= 0)
			{
				DeleteAtPosition(pos);
			}
				
			else
			{
				printf("Error: invalid position entered");
			}
			
		}
		
	}
	
	CleanUpList();
	
	return 0;
}

struct Node* CreateNewNode(char data[MAX_STR_LENGTH])
{
	//STUDENT MUST DEFINE THIS METHOD 
	//INPUT: Get string input from the user
	//PROCESS: Create a new node from user input, allocate memory
	//RETURN: Pointer to the new node 

	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	strncpy(newNode->string, data, MAX_STR_LENGTH);
	newNode->next = NULL;
	newNode->previous = NULL;
	
	return newNode;
}

void InsertNodeAtHead(struct Node* node)
{
	//STUDENT MUST DEFINE THIS METHOD 
	//INPUT: A valid Node pointer
	//PROCESS: The Node pointer is inserted at the head of the list
	//headNode pointer is assigned to the new node
	//if empty list, headNode AND tailNode pointers assigned to the node
	
	struct Node * currentNode_ptr = NULL;

	if (!headNode)
	{
		headNode = node;
		tailNode = node;
		nodeCount = 1;
	}
	else if (headNode)
	{
		currentNode_ptr = headNode;
		node->next = currentNode_ptr;
		currentNode_ptr->previous = node;
		node->previous = NULL;
		headNode = node;
		nodeCount++;
	}
	else
	{
		printf("Error: Inserting head node");
	}

	return;
}

void InsertNodeAtTail(struct Node* node)
{
	//STUDENT MUST DEFINE THIS METHOD 
	//INPUT: A valid Node pointer
	//PROCESS: The Node pointer is inserted at the tail of the list
	//tailNode pointer is assigned to the new node
	//if empty list, headNode AND tailNode pointers assigned to the node

	struct Node * currentNode_ptr = NULL;

	if (!tailNode)
	{
		headNode = node;
		tailNode = node;
		nodeCount = 1;
	}
	else if (tailNode)
	{
		currentNode_ptr = tailNode;
		node->previous = currentNode_ptr;
		currentNode_ptr->next = node;
		node->next = NULL;
		tailNode = node;
		nodeCount++;
	}
	else
	{
		printf("Error: Inserting tail node");
	}
	
	return;
}

void InsertNodeAtPosition(struct Node* node, int pos)
{
	//STUDENT MUST DEFINE THIS METHOD 
	//INPUT: A valid Node pointer, position to place in the linked list
	//PROCESS: The Node pointer is inserted at the specified position
	//Nodes are properly linked to the new node

	struct Node * currentNode_ptr = NULL;
	int i = 0;
	currentNode_ptr = headNode;

	if (pos == 0)
	{
		InsertNodeAtHead(node);
	}
	else if (pos > nodeCount)
	{
		InsertNodeAtTail(node);
	}
	else
	{
		for (i = 1; i < pos-1; i++)
		{
			currentNode_ptr = currentNode_ptr->next;
		}
		node->next = currentNode_ptr->next;
		currentNode_ptr->next = node;
		currentNode_ptr->next->previous = node;
		node->previous = currentNode_ptr;
		nodeCount++;
	}
	
	return;
}

void PrintList()
{
	//STUDENT MUST DEFINE THIS METHOD 
	//INPUT: None
	//PROCESS: Traverse the list, print every node string in order
	//if empty list, display an error message to screen

	struct Node * currentNode_ptr = NULL;
	int i = 1;

	if (!headNode)
	{
		printf("Print error: Headnode does not exist");
	}
	
	currentNode_ptr = headNode;

	while (currentNode_ptr)
	{
		printf("NODE #%d\n", i);
		printf("String: \t%s\n", currentNode_ptr->string);
		printf("Previous node: \t0x%p\n", currentNode_ptr->previous);
		printf("Current node: \t0x%p\n", currentNode_ptr);
		printf("Next node: \t0x%p\n", currentNode_ptr->next);

		currentNode_ptr = currentNode_ptr->next;

		i++;
	}
	
	return;
}

void PrintReverse()
{
	//STUDENT MUST FILL IN THIS FUNCTION 
	//STUDENT MUST DEFINE THIS METHOD 
	//INPUT: None
	//PROCESS: Traverse the list, print every node string in reverse order
	//if empty list, display an error message to screen
	//RETURN: none

	struct Node * currentNode_ptr = NULL;
	int i = nodeCount;

	if (!tailNode)
	{
		printf("Print error: Headnode does not exist");
	}

	currentNode_ptr = tailNode;

	while (currentNode_ptr)
	{
		printf("NODE #%d\n", i);
		printf("String: \t%s\n", currentNode_ptr->string);
		printf("Previous node: \t0x%p\n", currentNode_ptr->previous);
		printf("Current node: \t0x%p\n", currentNode_ptr);
		printf("Next node: \t0x%p\n", currentNode_ptr->next);

		currentNode_ptr = currentNode_ptr->previous;

		i--;
	}
	
	return;
	
}

void DeleteAtPosition(int pos)
{
	//STUDENT MUST FILL IN THIS FUNCTION 
	//STUDENT MUST DEFINE THIS METHOD 
	//INPUT: integer position
	//PROCESS: Traverse the list, delete node specified by position, reconnect list 
	//If empty list, display error message to the screen
	//RETURN: None

	struct Node * currentNode_ptr = NULL;
	//struct Node * delNode_ptr = NULL;
	int i = 0;
	currentNode_ptr = headNode;

	if (pos < 1)
	{
		printf("Error: Invalid selection");
	}
	else if	(pos == 1)
	{
		currentNode_ptr = currentNode_ptr->next;
		currentNode_ptr->previous = NULL;
		headNode = currentNode_ptr;
		nodeCount--;
	}
	else if (pos > nodeCount)
	{
		currentNode_ptr = tailNode;
		tailNode = currentNode_ptr->previous;
		tailNode->next = NULL;
		nodeCount--;
	}
	else
	{
		for (i = 1; i < pos - 1; i++)
		{
			currentNode_ptr = currentNode_ptr->next;
		}
		currentNode_ptr->next->previous = currentNode_ptr;
		currentNode_ptr->next = currentNode_ptr->next->next;
		nodeCount--;
	}
	
	if (nodeCount == 2)
	{
		headNode->next = tailNode;
		tailNode->previous = headNode;
	}
	free(currentNode_ptr);
		
	return;
}

void CleanUpList()
{
	
	struct Node* travNode = headNode;
	struct Node* delNode;
	
	if(nodeCount > 0 && travNode != NULL)
	{
		while(travNode != NULL)
		{
			delNode = travNode;
			travNode = travNode->next;
			free(delNode);
			
		}
		
		nodeCount = 0;
	}

	return;
	
}

int IsEmpty()
{
	if (!headNode)
	{
		printf("The list is empty.");
		return 0;
	}
	else
	{
		return 1;
	}
}