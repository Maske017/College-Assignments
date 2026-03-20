//Marin Aske
//CS1 Torosdagli
//Lab Assignment 7

#include <stdio.h>

void bubbleSort(int arr[], int n, int *totalSwaps) 
{
    int i, j;
    for (i = 0; i < n-1; i++) 
    {
        for (j = 0; j < n-i-1; j++) 
        {
            if (arr[j] > arr[j+1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*totalSwaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int *totalSwaps) 
{
    int i, j, min;
    for (i = 0; i < n-1; i++) 
    {
        min = i;
        for (j = i+1; j < n; j++) 
        {
            if (arr[j] < arr[min]) 
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        (*totalSwaps)++;
    }
}

int main() 
{
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    
    int totalSwaps1_bubble = 0, totalSwaps1_selection = 0;
    int totalSwaps2_bubble = 0, totalSwaps2_selection = 0;
    
    printf("array1:\n");
    
    int tempArray1_bubble[n1];
    for (int i = 0; i < n1; i++) 
    {
        tempArray1_bubble[i] = array1[i];
    }
    bubbleSort(tempArray1_bubble, n1, &totalSwaps1_bubble);
    for (int i = 0; i < n1; i++) 
    {
        printf("%d: %d swaps\n", array1[i], tempArray1_bubble[i] - array1[i]);
    }
    printf("Total swaps for array1 using Bubble Sort: %d\n", totalSwaps1_bubble);
    
    int tempArray1_selection[n1];
    for (int i = 0; i < n1; i++) 
    {
        tempArray1_selection[i] = array1[i];
    }
    selectionSort(tempArray1_selection, n1, &totalSwaps1_selection);
    for (int i = 0; i < n1; i++) 
    {
        printf("%d: %d swaps\n", array1[i], tempArray1_selection[i] - array1[i]);
    }
    printf("Total swaps for array1 using Selection Sort: %d\n", totalSwaps1_selection);
    
    printf("\narray2:\n");

    int tempArray2_bubble[n2];
    for (int i = 0; i < n2; i++) 
    {
        tempArray2_bubble[i] = array2[i];
    }
    bubbleSort(tempArray2_bubble, n2, &totalSwaps2_bubble);
    for (int i = 0; i < n2; i++) 
    {
        printf("%d: %d swaps\n", array2[i], tempArray2_bubble[i] - array2[i]);
    }
    printf("Total swaps for array2 using Bubble Sort: %d\n", totalSwaps2_bubble);
    
    int tempArray2_selection[n2];
    for (int i = 0; i < n2; i++) {
        tempArray2_selection[i] = array2[i];
    }
    selectionSort(tempArray2_selection, n2, &totalSwaps2_selection);
    for (int i = 0; i < n2; i++) {
        printf("%d: %d swaps\n", array2[i], tempArray2_selection[i] - array2[i]);
    }
    printf("Total swaps for array2 using Selection Sort: %d\n", totalSwaps2_selection);

    return 0;
}
