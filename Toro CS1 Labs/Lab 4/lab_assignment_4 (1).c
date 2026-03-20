//Marin Aske
//CS1 Torosdagli
//LabAssignment4
//2/9/2024

#include <stdio.h>
#include <stdlib.h>

//declare struct node
typedef struct node 
{
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	//declare variable count
	int size = 0;
	//use while loop to repeat until head is not
	//equal to null
	while (head != NULL) 
	{
		//increment the count
		size++;
		//decrement the size 
		head = head->next;
	}
	//return the size
	//of the linked list
	return size;
}

// Parses the string in the linkedList.
// If the linked list is head->|a|->|b|->|c|,
// then toCstring function will return "abc".
char* toCstring(node* head) 
{
	//declare variable to store
	//the length of the string
	int size = length(head);
	//then allocate memory of type
	char* str = (char*)malloc(size + 1);
	int i = 0;
	//use while loop
	//until head not equal to 0
	while (head != NULL) 
	{
		//allocate each letter to 
		//the string array
		str[i] = head->letter;
		head = head->next;
		i++;
	}
	//set the last character
	//to null
	str[size] = '\0';
	//return the converted string
	return str;
}

// Inserts character to the linkedlist.
// If the linked list is head->|a|->|b|->|c|,
// then insertChar(&head, 'x') will update the linked list as follows:
// head->|a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	//allocate memory for the node
	node* newNode = (node*)malloc(sizeof(node));
	//set the character to 
	//the letter of node
	newNode->letter = c;
	newNode->next = NULL;
	//if head is null
	//the set the new node as head
	if (*pHead == NULL) 
	{
		*pHead = newNode;
	}
	//Otherwise
	else 
	{
		//cretae a current node and set to head
		node* currentnode = *pHead;
		//use while loop to iterate
		//the current node is not equal to 
		//null
		while (currentnode->next != NULL)
		{
			//set current node to current to next node
			currentnode = currentnode->next;
		}
		//set the next node as current node
		currentnode->next = newNode;
	}
}

// Delete all nodes in the linkedList.
void deleteList(node** pHead) 
{
	//set the current node as head
	node* currentnode = *pHead;
	//use while loop to iterate until current node 
	//is not null
	while (currentnode != NULL)
	{
		//set the temp to current node
		node* temp = currentnode;
		//set current to current next
		currentnode = currentnode->next;
		//delete the temp node
		free(temp);
	}
	//set head to null
	*pHead = NULL;
}

int main(void) 
{
	//declare local variables
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt", "r");
	fscanf(inFile, "%d\n", &numInputs);
	//use while loop to read until 
	//input greater than 0
	while (numInputs > 0) 
	{
		//read the string length
		fscanf(inFile, "%d\n", &strLen);
		//use for loop to read the string 
		for (i = 0; i < strLen; i++) 
		{
			//read the character
			fscanf(inFile, "%c", &c);
			//insert the charctare into linked list
			//by calling the function
			insertChar(&head, c);
		}
		//convert the characters to string
		//by calling function and store 
		//return variable to str
		str = toCstring(head);
		//print the string
		printf("String is: (%s)\n", str);
		//free the string
		free(str);
		//selete the current string
		deleteList(&head);
		//if head is null
		//list is empty, print the message
		if (head != NULL)
		{
			printf("deleteList is not correct!\n");
			break;
		}
		//decrement the count
		numInputs--;
	}
	//close the file
	fclose(inFile);
	return 0;
}