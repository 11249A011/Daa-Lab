Aim
To implement the Tower of Hanoi problem using recursion in C and display the sequence of moves required to transfer all disks from source to destination.
#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void toh(int diskcount, char s, char d, char t)
{
    // Base case: if only one disk, move it directly
    if (diskcount == 1)
    {
        printf("\nMove disk %d from %c to %c", diskcount, s, d);
        return;
    }

    // Step 1: Move n-1 disks from source to temporary using destination
    toh(diskcount - 1, s, t, d);

    // Step 2: Move the nth (largest) disk from source to destination
    printf("\nMove disk %d from %c to %c", diskcount, s, d);

    // Step 3: Move n-1 disks from temporary to destination using source
    toh(diskcount - 1, t, d, s);
}

int main()
{
    int n; // Number of disks

    // Input number of disks
    printf("Enter number of disks: ");
    scanf("%d", &n);

    // Call Tower of Hanoi function
    toh(n, 'S', 'D', 'T'); // S = Source, D = Destination, T = Temporary

    return 0;
}
