Aim:
To implement the Best Fit algorithm in C to efficiently allocate items of different sizes into bins of fixed capacity such that the number of bins used is minimized.
  
#include <stdio.h>

void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];
    int binCount = 0;

    // Initialize bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    // Process each item
    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;
        int minSpace = capacity + 1;

        // Find best bin
        for (int j = 0; j < binCount; j++)
        {
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace)
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i];
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        }
        else
        {
            bin[binCount] -= items[i];
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++;
        }
    }

    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, capacity,itemSize;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    int items[n];

    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
         printf("Item %d: ", i + 1);
            scanf("%d", &itemSize);

            if (itemSize <= capacity)
            {
                items[i] = itemSize;
            }
            else
            {
                printf("Item size exceeds bin capacity. Please enter again.\n");
            }
        }
   
    bestFit(items, n, capacity);

    return 0;
}
