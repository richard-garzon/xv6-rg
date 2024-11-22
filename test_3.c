#include "types.h"
#include "stat.h"
#include "user.h"

// A function for the child process to waste CPU time
void spin() {
    volatile int i, j;
    for (i = 0; i < 1000000000; i++) {
        j += i;  // Useless computation to burn CPU cycles
    }
    exit();
}

int main() {
    int pid, i;
    int num_processes = 3;  // Number of child processes
    int tickets[] = {10, 20, 100};  // Tickets for each process

    // Create child processes
    for (i = 0; i < num_processes; i++) {
        pid = fork();
        if (pid < 0) {
            printf(1, "Fork failed\n");
            exit();
        } else if (pid == 0) {
            // In child process
            settickets(tickets[i]);  // Set tickets for the child process
            spin();                  // Burn CPU time
        }
        // Parent continues to create the next process
    }

    // Parent waits for all child processes
    for (i = 0; i < num_processes; i++) {
        wait();
    }

    // Scheduler output should indicate approximate proportional ticks
    printf(1, "All child processes completed.\n");
    exit();
}
