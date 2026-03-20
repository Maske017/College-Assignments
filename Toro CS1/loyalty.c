//Marin Aske
//PA3
//CS1 Torosdagli
//4/3/2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 19 // Maximum length of customer name

// Structure to represent a customer
typedef struct customer {
    char name[MAXLEN + 1]; // Customer name
    int points; // Customer points
} customer;

// Structure to represent a node in the binary search tree
typedef struct treenode {
    customer* cPtr; // Pointer to customer data
    int size; // Size of the subtree rooted at this node
    struct treenode* left; // Pointer to left child
    struct treenode* right; // Pointer to right child
} treenode;

// Function prototypes
treenode* insert(treenode* root, customer* c);
treenode* delete(treenode* root, char* name);
void search(treenode* root, char* name, int depth);
int count_smaller(treenode* root, char* name);
void print_sorted(treenode* root, FILE *outfile, int print_to_terminal);
void free_tree(treenode* root);

// Helper function to create a new customer node
customer* create_customer(char* name, int points) {
    customer* new_customer = (customer*)malloc(sizeof(customer));
    if (new_customer != NULL) {
        strcpy(new_customer->name, name);
        new_customer->points = points;
    }
    return new_customer;
}

// Helper function to create a new tree node
treenode* create_treenode(customer* c) {
    treenode* new_node = (treenode*)malloc(sizeof(treenode));
    if (new_node != NULL) {
        new_node->cPtr = c;
        new_node->size = 1;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

// Function to insert a customer into the BST
treenode* insert(treenode* root, customer* c) {
    if (root == NULL) {
        return create_treenode(c); // Create new node if tree is empty
    }

    int cmp = strcmp(c->name, root->cPtr->name); // Compare names
    if (cmp < 0) {
        root->left = insert(root->left, c); // Insert into left subtree
    } else if (cmp > 0) {
        root->right = insert(root->right, c); // Insert into right subtree
    } else {
        // Customer already exists, update points
        root->cPtr->points += c->points;
        free(c); // Free memory allocated for new customer
    }

    // Update size of the subtree rooted at this node
    root->size = 1;
    if (root->left != NULL) {
        root->size += root->left->size;
    }
    if (root->right != NULL) {
        root->size += root->right->size;
    }

    return root;
}

// Function to delete a customer from the BST
treenode* delete(treenode* root, char* name) {
    if (root == NULL) {
        return NULL; // Tree is empty or customer not found
    }

    int cmp = strcmp(name, root->cPtr->name); // Compare names
    if (cmp < 0) {
        root->left = delete(root->left, name); // Delete from left subtree
    } else if (cmp > 0) {
        root->right = delete(root->right, name); // Delete from right subtree
    } else {
        // Found the node to delete
        if (root->left == NULL) {
            treenode* temp = root->right;
            free(root->cPtr);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            treenode* temp = root->left;
            free(root->cPtr);
            free(root);
            return temp;
        } else {
            // Node has two children
            // Find the maximum node in the left subtree
            treenode* max_left = root->left;
            while (max_left->right != NULL) {
                max_left = max_left->right;
            }
            // Replace the current node's data with the max_left's data
            strcpy(root->cPtr->name, max_left->cPtr->name);
            root->cPtr->points = max_left->cPtr->points;
            // Delete the max_left node
            root->left = delete(root->left, max_left->cPtr->name);
        }
    }

    // Update size of the subtree rooted at this node
    root->size = 1;
    if (root->left != NULL) {
        root->size += root->left->size;
    }
    if (root->right != NULL) {
        root->size += root->right->size;
    }

    return root;
}

// Function to search for a customer in the BST
void search(treenode* root, char* name, int depth) {
    if (root == NULL) {
        printf("%s not found\n", name);
        return;
    }

    int cmp = strcmp(name, root->cPtr->name); // Compare names
    if (cmp == 0) {
        printf("%s %d %d\n", name, root->cPtr->points, depth);
    } else if (cmp < 0) {
        search(root->left, name, depth + 1); // Search left subtree
    } else {
        search(root->right, name, depth + 1); // Search right subtree
    }
}

// Function to count the number of customers whose names come alphabetically before a particular customer
int count_smaller(treenode* root, char* name) {
    if (root == NULL) {
        return 0; // No smaller elements
    }

    int cmp = strcmp(name, root->cPtr->name); // Compare names
    if (cmp <= 0) {
        return count_smaller(root->left, name); // Search in left subtree
    } else {
        int left_count = (root->left != NULL) ? root->left->size : 0;
        return left_count + 1 + count_smaller(root->right, name); // Search in right subtree
    }
}

// Function to print the customers in sorted order
void print_sorted(treenode* root, FILE *outfile, int print_to_terminal) {
    if (root != NULL) {
        print_sorted(root->right, outfile, print_to_terminal); // Traverse right subtree
        fprintf(outfile, "%s %d\n", root->cPtr->name, root->cPtr->points); // Print customer data
        if (print_to_terminal) {
            printf("%s %d\n", root->cPtr->name, root->cPtr->points); // Print to terminal if specified
        }
        print_sorted(root->left, outfile, print_to_terminal); // Traverse left subtree
    }
}

// Function to free the memory allocated for the BST
void free_tree(treenode* root) {
    if (root != NULL) {
        free_tree(root->left); // Recursively free left subtree
        free_tree(root->right); // Recursively free right subtree
        free(root->cPtr); // Free customer data
        free(root); // Free node
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    // Open input file
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Open output file
    FILE *outfile = fopen(argv[2], "w");
    if (outfile == NULL) {
        perror("Error opening output file");
        fclose(infile);
        return 1;
    }

    // Read number of operations from input
    int n;
    fscanf(infile, "%d", &n);

    treenode* root = NULL; // Initialize BST root

    // Process each operation
    for (int i = 0; i < n; i++) {
        char command[15], name[MAXLEN + 1];
        int points;
        fscanf(infile, "%s", command); // Read command

        // Perform operation based on command
        if (strcmp(command, "add") == 0) {
            fscanf(infile, "%s %d", name, &points);
            customer* new_customer = create_customer(name, points);
            root = insert(root, new_customer);
            fprintf(outfile, "%s %d\n", name, new_customer->points);
        } else if (strcmp(command, "sub") == 0) {
            fscanf(infile, "%s %d", name, &points);
            treenode* node = root;
            int found = 0;
            while (node != NULL) {
                int cmp = strcmp(name, node->cPtr->name);
                if (cmp == 0) {
                    found = 1;
                    break;
                } else if (cmp < 0) {
                    node = node->left;
                } else {
                    node = node->right;
                }
            }
            if (found) {
                node->cPtr->points -= points;
                if (node->cPtr->points < 0) {
                    node->cPtr->points = 0;
                }
                fprintf(outfile, "%s %d\n", name, node->cPtr->points);
            } else {
                fprintf(outfile, "%s not found\n", name);
            }
        } else if (strcmp(command, "del") == 0) {
            fscanf(infile, "%s", name);
            root = delete(root, name);
            fprintf(outfile, "%s deleted\n", name);
        } else if (strcmp(command, "search") == 0) {
            fscanf(infile, "%s", name);
            search(root, name, 0);
        } else if (strcmp(command, "count_smaller") == 0) {
            fscanf(infile, "%s", name);
            int count = count_smaller(root, name);
            fprintf(outfile, "%d\n", count);
        }
    }

    // Print customers in sorted order
    print_sorted(root, stdout, 1);

    // Free memory allocated for the BST
    free_tree(root);

    // Close input and output files
    fclose(infile);
    fclose(outfile);

    return 0;
}
