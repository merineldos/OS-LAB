#include <stdio.h>
#include <stdlib.h>

int rear = 0, pagefaults = 0, n;
int frames[3], counter[3], time[3];

// Function to initialize frames and counters
void initialize() {
    for (int i = 0; i < 3; i++) {
        frames[i] = -1; // -1 indicates an empty frame
        counter[i] = 0; // Initialize usage counter
        time[i] = 0;    // Initialize timestamp for LFU
    }
}

// Function to display the current state of frames
void display() {
    for (int i = 0; i < 3; i++) {
        if (frames[i] != -1) {
            printf("%d ", frames[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

// Function to find the least frequently used frame
int findlfu() {
    int lfuframe = 0;
    int min = counter[0];
    int oldesttime = time[0];

    for (int i = 0; i < 3; i++) {
        if (counter[i] < min) {
            min = counter[i];
            oldesttime = time[i];
            lfuframe = i;
        } else if (counter[i] == min && time[i] < oldesttime) {
            // If frequencies are the same, choose the oldest
            oldesttime = time[i];
            lfuframe = i;
        }
    }
    return lfuframe;
}

// Function to implement LFU page replacement algorithm
void lfu(int pages[], int n) {
    int found, lfuframe, currenttime = 0;

    for (int i = 0; i < n; i++) {
        found = 0; // Flag to check if page is found

        // Check if the page is already in one of the frames
        for (int j = 0; j < 3; j++) {
            if (frames[j] == pages[i]) {
                found = 1; // Page hit
                printf("Page %d is already in the frame\n", pages[i]);
                time[j] = currenttime; // Update timestamp
                counter[j]++;           // Increment usage counter
                break; // Exit inner loop if found
            }
        }

        // If page not found, we need to replace a frame
        if (!found) {
            lfuframe = findlfu(); // Find the least frequently used frame
            frames[lfuframe] = pages[i]; // Replace it with the new page
            counter[lfuframe] = 1; // Reset the usage counter for the new page
            time[lfuframe] = currenttime; // Set the current time
            pagefaults++; // Increment page fault counter
            printf("Page %d is loaded into frame %d\n", pages[i], lfuframe);
        }
        currenttime++; // Increment the current time
        display(); // Show current state of frames
    }
    printf("Number of page faults: %d\n", pagefaults); // Display total page faults
}

int main() {
    printf("Enter the number of pages: \n");
    scanf("%d", &n);
    int pages[n]; // Array to hold page reference sequence
    printf("Enter the page sequence: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    initialize(); // Initialize frames and counters
    lfu(pages, n); // Call the LFU function
    return 0;
}
