// common.h

// Standard Linux IPC & Headers
#include <stdio.h>      
#include <sys/types.h>
#include <sys/msg.h>    // For Message Queues 
#include <sys/shm.h>    // For Shared Memory 
#include <unistd.h>     // For fork(), exec(), kill()
#include <stdlib.h>     // For exit()

// IPC Keys (MUST be unique integers)
#define SHKEY 300       
#define MSGKEY 500      

// Define the termination signal for Process -> Scheduler
#define SIG_FINISH SIGUSR1  // SIGUSR1 is a user-defined signal, often used for custom events.

// The core data structure for a process 
// (used in Message Queue and in Scheduler's internal PCB)
struct ProcessData {
    int id;
    int arrivaltime;
    int runtime;    
    int priority;
};

// The message structure used for Generator -> Scheduler IPC
// Must start with 'long mtype'
struct msgbuff {
    long mtype;  
    struct ProcessData pData;
};

// Global function prototypes (declared here, implemented elsewhere)
void initClk();
int getClk();
void destroyClk(bool terminateAll);