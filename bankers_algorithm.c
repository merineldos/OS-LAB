#include <stdio.h>
#define p 5  // Number of processes
#define r 3  // Number of resources

// Function to display a matrix
void display(int arr[p][r]) {
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d-", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to determine if the system is in a safe state
int isSafeState(int max[p][r], int allocation[p][r], int available[r], int sequence[p]) {
    int need[p][r];      // Need matrix
    int work[r];         // Work array, initialized to available resources
    int finish[p] = {0}; // Finish array, initialized to 0 (false)

    // Calculate the Need matrix = Max - Allocation
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printf("Need matrix: \n");
    display(need);

    // Initialize the Work array to Available resources
    for (int i = 0; i < r; i++) {
        work[i] = available[i];
    }

    int count = 0; // Number of processes that can finish
    int flag, found, k = 0; // Sequence index

    // Banker's Algorithm main loop
    while (count < p)
     {
        found = 0; // Reset found for each iteration

        // Check each process
        for (int i = 0; i < p; i++) 
        {
            if (finish[i] == 0) { // Process i has not finished
                flag = 1; // Assume resources can be allocated

                // Check if all resources in Need[i] <= Work
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) { // Not enough resources
                        flag = 0;
                        break;
                    }
                }

                // If resources are sufficient
                if (flag ==1) {
                    printf("Available resources:");
                    for (int j = 0; j < r; j++) {
                        printf(" %d", work[j]);
                    }
                    printf("\n");

                    printf("Process %d can be allocated resources: ", i);
                    for (int j = 0; j < r; j++) {
                        printf("%d ", need[i][j]);
                        work[j] += allocation[i][j]; // Release resources
                    }
                    printf("\n");

                    finish[i] = 1;         // Mark process i as finished
                    sequence[k++] = i;     // Add process to the safe sequence
                    count++;               // Increment count of finished processes
                    found = 1;             // Found at least one process to allocate
                }
            }
        }

        if (found == 0) // If no process could be allocated, system is not in a safe state
            return 0;
    }
    return 1; // System is in a safe state
}

// Function to execute the Banker's Algorithm
void bankers(int max[p][r], int allocation[p][r], int available[r]) {
    int sequence[p]; // Safe sequence array

    if (isSafeState(max, allocation, available, sequence)) {
        printf("Safe state\nSafe sequence: ");
        for (int i = 0; i < p; i++) {
            printf("P%d ", sequence[i]);
        }
        printf("\n");
    } else {
        printf("Not in a safe state\n");
    }
}

int main() {
    int available[] = {3, 3, 2}; // Initial available resources
    int max[p][r] = { // Maximum resources required by each process
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };
    int allocation[p][r] = { // Resources currently allocated to each process
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    printf("Max matrix:\n");
    display(max);
    printf("Allocation matrix:\n");
    display(allocation);

    bankers(max, allocation, available);

    return 0;
}
