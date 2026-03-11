/*
Problem Statement:
Implement Heap Sort using a Max Heap to sort an array in ascending order.
First build a max heap, then repeatedly extract the maximum element and
place it at the end of the array.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Sorted array in ascending order

Example:
Input:
6
12 11 13 5 6 7

Output:
5 6 7 11 12 13
*/

#include <stdio.h>

/* Swap two numbers */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify function to maintain max heap property */
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

/* Heap Sort function */
void heapSort(int arr[], int n)
{
    /* Build Max Heap */
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    /* Extract elements one by one */
    for(int i = n-1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

/* Print array */
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n;

    printf("Enter number of elements (max 10 recommended): ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}