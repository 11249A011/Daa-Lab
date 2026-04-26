Aim
To implement Randomized Quick Sort in C to sort a list of elements efficiently using a divide-and-conquer approach with a random pivot selection.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function: places pivot in correct position
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // Pivot element
    int i = (low - 1);      // Index of smaller element

    // Traverse and rearrange elements
    for (int j = low; j < high; j++)
    {
        // If current element is smaller than pivot
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]); // Move smaller element to left
        }
    }

    // Place pivot in correct position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // Return pivot index
}

// QuickSort function with random pivot
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Select a random pivot index
        int randomIndex = low + rand() % (high - low + 1);

        // Swap random pivot with last element
        swap(&arr[randomIndex], &arr[high]);

        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

    srand(time(NULL)); // Seed for random number generator

    // Input number of elements
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int numbersToSort[n];

    // Input array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &numbersToSort[i]);

    // Call QuickSort
    quickSort(numbersToSort, 0, n - 1);

    // Print sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", numbersToSort[i]);

    return 0;
}
