Aim
To implement the Fractional Knapsack Algorithm using a greedy approach in C, in order to maximize the total profit by selecting items based on their value-to-weight ratio.
  #include <stdio.h>

// Structure to store item details
struct Item {
    int weight;   // Weight of the item
    int value;    // Value (profit) of the item
    float ratio;  // Value-to-weight ratio
};

// Function to sort items in descending order of ratio
void sort(struct Item items[], int n) {
    struct Item temp;

    // Bubble sort based on ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            // Swap if next item has higher ratio
            if (items[j].ratio < items[j + 1].ratio) {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;          // Number of items
    int capacity;   // Maximum capacity of knapsack

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];  // Array of items

    // Input weight and value of each item
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);

        // Calculate value-to-weight ratio
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items based on ratio (descending)
    sort(items, n);

    float totalProfit = 0.0;  // Stores maximum profit

    // Greedy selection of items
    for (int i = 0; i < n; i++) {

        // If full item can be taken
        if (capacity >= items[i].weight) {
            totalProfit += items[i].value;   // Add full value
            capacity -= items[i].weight;     // Reduce capacity
        } 
        else {
            // Take fractional part of item
            totalProfit += items[i].ratio * capacity;
            break;  // Knapsack is full
        }
    }

    // Output maximum profit
    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
