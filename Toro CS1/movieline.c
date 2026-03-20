//Marin Aske
//CS1 Torosdagli
//PA3 Movieline.c

// Including necessary libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define constants
#define MAX 51
#define MAXTIME 2000000000
#define NUMQS 12
#define NONE -1

// Define a structure for a customer
typedef struct customer {
    char* name;         // Name of the customer
    int lineNum;        // Line number of the queue the customer is in
    int checkoutTime;   // Time taken by the customer to checkout
    int arrivalTime;    // Arrival time of the customer
} customer;

// Define a structure for a node in a queue
typedef struct node {
    customer* cPtr;     // Pointer to a customer
    struct node* next;  // Pointer to the next node
} node;

// Define a structure for a queue
typedef struct queue {
    node* head;         // Pointer to the head of the queue
    node* tail;         // Pointer to the tail of the queue
    int size;           // Size of the queue
} queue;

// Function to return the size of a queue
int size(queue* qPtr) {
    return qPtr->size;
}

// Function to check if a queue is empty
int empty(queue* qPtr) {
    return size(qPtr) == 0;
}

// Function to determine which queue a customer should join
int getLine(queue* lines[], char* name) {

    int value = (name[0] - 'A') % 13;

    if (value != 0) {
        return value - 1;
    }

    int res = NONE;

    for (int i = 0; i < NUMQS; i++) {

        if (empty(lines[i])) {
            continue;
        }

        if (res == NONE || size(lines[i]) < size(lines[res])) {
            res = i;
        }
    }

    if (res == NONE) return 0;

    return res;
}

// Function to create a new customer
customer* createCustomer(char* name, int numTickets, int arriveTime, queue* lines[]) {

    customer* temp = malloc(sizeof(customer));
    temp->checkoutTime = 30 + numTickets * 5;
    temp->arrivalTime = arriveTime;

    temp->name = calloc(strlen(name) + 1, sizeof(char));
    strcpy(temp->name, name);

    temp->lineNum = getLine(lines, name);

    return temp;
}

// Function to get the customer at the front of the queue without dequeuing
customer* peek(queue* qPtr) {
    if (qPtr->head == NULL) {
        return NULL;
    }
    return qPtr->head->cPtr;
}

// Function to get the arrival time of the customer at the front of the queue
int getArrivalTime(queue* qPtr) {
    customer* temp = peek(qPtr);
    if (temp == NULL) {
        return MAXTIME;
    }
    return temp->arrivalTime;
}

// Function to get the next queue with a customer arrival time
int getNext(queue* lines[], int* q, int aI, int bI) {
    int res = NONE;
    int early = NONE;

    for (int i = aI; i < bI; i++) {
        int index = q[i];

        if (empty(lines[index])) continue;

        if (res == NONE || getArrivalTime(lines[index]) < early) {
            res = index;
            early = getArrivalTime(lines[index]);
        }
    }

    return res;
}

// Function to get non-empty queues
int* getNonEmpty(queue* lines[], int* numNonEmpty) {

    int* res = calloc(NUMQS, sizeof(int));
    int f = 0;

    for (int i=0; i<NUMQS; i++) {
        if (!empty(lines[i])) {
            res[f] = i;
            f++;
        }
    }

    *numNonEmpty = f;
    res = realloc(res, f*sizeof(int));

    return res;
}

// Function to create a new empty queue
queue* makeNewQueue() {
    queue* ptr = malloc(sizeof(queue));
    ptr->head = NULL;
    ptr->tail = NULL;
    ptr->size = 0;

    return ptr;
}

// Function to enqueue a customer into a queue
void enqueue(queue* qPtr, customer* cust) {

    node* temp = malloc(sizeof(node));
    temp->cPtr = cust;
    temp->next = NULL;

    if (qPtr->head == NULL) {
        qPtr->head = temp;
    } else {
        qPtr->tail->next = temp;
    }
        
    qPtr->tail = temp;
    qPtr->size++;
}

// Function to dequeue a customer from a queue
customer* dequeue(queue* qPtr) {

    node* temp = qPtr->head;
    customer* value = temp->cPtr;

    if (qPtr->head == qPtr->tail) {
        qPtr->tail = NULL;
    } 

    qPtr->head = qPtr->head->next;
    qPtr->size--;

    free(temp);

    return value;
}

// Main function
int main() {

    // Array of queues representing different lines
    queue* lines[NUMQS];
    for (int i = 0; i < NUMQS; i++) {
        lines[i] = makeNewQueue();
    }

    // Open file for input
    char filename[MAX];
    printf("Enter the filename (Please include file .in extention as well): ");
    scanf("%s", filename);
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read number of operations and number of booths
    int numOps, numBooths;
    fscanf(fp, "%d%d", &numOps, &numBooths);

    // Process each operation
    for (int i = 0; i < numOps; i++) {
        char name[MAX];
        int numTickets, arriveTime;
        fscanf(fp, "%s%d%d", name, &numTickets, &arriveTime);
        customer* temp = createCustomer(name, numTickets, arriveTime, lines);

        enqueue(lines[temp->lineNum], temp);
    }

    fclose(fp);

    // Get non-empty queues
    int numNonEmpty;
    int* q = getNonEmpty(lines, &numNonEmpty);
    int each = numNonEmpty / numBooths;
    int getExtra = numNonEmpty % numBooths;

    int j = 0;

    // Simulate each booth
    for (int i = 0; i < numBooths; i++) {
        printf("Booth %d\n", i + 1);

        int currentTime = 0;

        int amount = each;
        if (i < getExtra) amount++;

        int nextPerson = getNext(lines, q, j, j + amount);
        while (nextPerson != NONE) {
            customer* temp = dequeue(lines[nextPerson]);

            if (temp->arrivalTime > currentTime) {
                currentTime = temp->arrivalTime;
            }

            currentTime += temp->checkoutTime;

            printf("%s from line %d checks out at time %d.\n", temp->name, temp->lineNum + 1, currentTime);

            nextPerson = getNext(lines, q, j, j + amount);

            free(temp->name);
            free(temp);
        }

        j += amount;

        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < NUMQS; i++) {
        free(lines[i]);
    }
        
    free(q);

    return 0;
}
