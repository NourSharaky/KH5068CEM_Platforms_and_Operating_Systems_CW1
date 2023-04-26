
// Nour A Sharaky - 202000149
// KH5068CEM Platforms and Operating Systems CW1
// Process Control Block Implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ____________________________________________________________________________________



// Process Control Block (PCB) struct
struct PCB {
    int process_id;
    char state[20];
    char process_name[20];
    int priority;
    int burst_time;
    int arrival_time;
    struct PCB *next_pcb;
};

// ____________________________________________________________________________________

// Global variables for the FIFO queue
struct PCB *head = NULL;                    // Pointer to queue head
struct PCB *tail = NULL;                    // Pointer to queue tail
int processes_in_queue = 0;                      // Num of processes in queue

// ____________________________________________________________________________________

// Function to create a new process
struct PCB *create_process(int pid, char* name, int priority, int burst, int arrival) {

    // Allocate memory for a new PCB
    struct PCB *new_pcb = (struct PCB*)malloc(sizeof(struct PCB)); 

    new_pcb  ->  process_id = pid;           // Set the process ID
    strcpy(new_pcb->state, "NEW");           // Set the process state
    strcpy(new_pcb -> process_name, name);   // Set the process name
    new_pcb -> priority = priority;          // Set the priority
    new_pcb -> burst_time = burst;           // Set the burst time
    new_pcb -> arrival_time = arrival;       // Set the arrival time
    new_pcb -> next_pcb = NULL;              // Set the next pointer to NULL

    return new_pcb; // Return the new PCB
}

// ____________________________________________________________________________________

// Function to add a new process to the FIFO queue
void enqueue(struct PCB *new_pcb) {

    // If the queue is empty
    if (head == NULL) {                     
        head = new_pcb;                      // Set the head to the new PCB
        tail = new_pcb;                      // Set the tail to the new PCB
        new_pcb -> next_pcb = NULL;          // Set the next pointer to NULL

    // If the queue is not empty
    } else { 
        tail -> next_pcb = new_pcb;          // Set the next pointer of the tail to the new PCB
        tail = new_pcb;                      // Set the tail to the new PCB
        new_pcb -> next_pcb = NULL;          // Set the next pointer to NULL
    }

    // Increment the number of processes in the queue
    processes_in_queue++; 
}

// ____________________________________________________________________________________

// Function to remove the first process from the FIFO queue
struct PCB* dequeue() {

    // If the queue is empty
    if (head == NULL) { 
        // Return NULL
        return NULL;

    // If the queue is not empty
    } else { 
        struct PCB *removed_pcb = head;       // Store a pointer to the head PCB
        head = head -> next_pcb;              // Set the head to the next PCB

        // If the queue is now empty
        if (head == NULL) {
            // Set the tail to NULL
            tail = NULL; 
        }

        // Decrement the number of processes in the queue
        processes_in_queue--; 

        return removed_pcb; // Return the removed PCB
    }
}

// ____________________________________________________________________________________

// Function to change the state of a process
void change_state(struct PCB *pcb, char *new_state){
    // Update the state of the process
    strcpy(pcb->state, new_state); 
}

// ____________________________________________________________________________________

// Function to print information about a process
void print_process(struct PCB *pcb) {
    printf("Process ID: %d\n", pcb -> process_id);
    printf("State: %s\n", pcb -> state);
    printf("Process Name: %s\n", pcb -> process_name);
    printf("Priority: %d\n", pcb -> priority);
    printf("Arrival Time: %d\n", pcb -> arrival_time);
    printf("Burst Time: %d\n\n", pcb -> burst_time);
}

// ____________________________________________________________________________________

int main() {
    // Create some sample PCBs using the create_process function
    struct PCB *pcb1 = create_process(1, "Process A", 1, 4, 2);
    struct PCB *pcb2 = create_process(2, "Process B", 3, 6, 5);
    struct PCB *pcb3 = create_process(3, "Process C", 2, 2, 8);
    struct PCB *pcb4 = create_process(4, "Process D", 4, 8, 11);
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Add the PCBs to the FIFO queue using the enqueue function
    enqueue(pcb1);
    enqueue(pcb2);
    enqueue(pcb3);
    enqueue(pcb4);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Print information about each process in the queue
    struct PCB *current_pcb = head;
    while (current_pcb != NULL) {
        // Change the state of the process to "READY"
        change_state(current_pcb, "READY");
        print_process(current_pcb);
        current_pcb = current_pcb -> next_pcb;
    }

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Remove the first process from the queue using the dequeue function
    struct PCB *removed_pcb = dequeue();
    printf("Removed Process:\n");
    // Change the state of the removed process to "TERMINATED"
    change_state(removed_pcb, "TERMINATED");
    print_process(removed_pcb);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Print information about the remaining processes in the queue
    current_pcb = head;

    while (current_pcb != NULL) {
        // Change the state of the process to "RUNNING"
        change_state(current_pcb, "RUNNING");
        print_process(current_pcb);
        current_pcb = current_pcb -> next_pcb;
    }

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Free memory allocated for the removed process
    free(removed_pcb);
    
    return 0;
}
// ____________________________________________________________________________________
