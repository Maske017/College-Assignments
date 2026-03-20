#include <stdio.h>

typedef struct node {
int data;
struct node* next;
} node;

void markEven(node* head) {
  node* current = head;
  // Iterate through the linked list
  while (current != NULL) {
    // Check if the current node's value is even
    if (current->data % 2 == 0) {
      // Allocate memory for the new node
      node* newNode = (node*) malloc(sizeof(node));
      // Set the new node's value to -1
      newNode->data = -1;
      // Link the new node to the current node's next node
      newNode->next = current->next;
      // Link the current node to the new node
      current->next = newNode;
      // Move the current pointer to the newly created node
      current = newNode->next;
    } else {
      // Move the current pointer to the next node if the value is not even
      current = current->next;
    }
  }
}

void deallocateList(node** head)
{
node* tmp = *head;

while (tmp != NULL)
{
*head = tmp->next;
free(tmp);
tmp = *head;
}

*head = NULL;
}

int insertList(node** head, int data)
{
node* newNode = (node*) malloc(sizeof(node));

if (newNode == NULL)
return -1;

newNode->data = data;
newNode->next = NULL;

newNode->next = *head;
*head = newNode;

return 1;
}



void printList(node* head)
{
node* tmp = head;

while (tmp != NULL)
{
printf("%d",tmp->data);
if (tmp->next != NULL)
{
printf(", ");
}
else
{
printf(".\n");
}
tmp = tmp->next;
}
}

int main(void)
{
node* head = NULL;

insertList(&head, 8);
insertList(&head, 3);
insertList(&head, 1);
insertList(&head, 7);
insertList(&head, 6);
insertList(&head, 2);

printf("Initial List:\n");
printList(head);
markEven(head);
printf("Marked List:\n");
printList(head);

deallocateList(&head);

}