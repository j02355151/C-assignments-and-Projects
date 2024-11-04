#include <stdio.h>
#include <stdlib.h>

// Structure definition for a queue
struct Queue {
    int items[5];
    int front;
    int rear;
    int count;
};

// Function to initialize a queue
void initializeQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Function to check if a queue is empty
int isEmpty(struct Queue* q) {
    return q->count == 0;
}

// Function to check if a queue is full
int isFull(struct Queue* q) {
    return q->count == 5;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* q, int value) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % 5;
        q->items[q->rear] = value;
        q->count++;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* q) {
    if (!isEmpty(q)) {
        int value = q->items[q->front];
        q->front = (q->front + 1) % 5;
        q->count--;
        return value;
    }
    return -1; // Return -1 to indicate an empty queue
}

// Function to compute the sum of elements in a queue
int computeSum(struct Queue* q) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += q->items[(q->front + i) % 5];
    }
    return sum;
}

// Function to process Queue 1 based on specified conditions
void processQ1(struct Queue* q1, struct Queue* q2, struct Queue* q3) {
    int sumQ1 = computeSum(q1);

    if (sumQ1 > 30 || isFull(q1)) {
        while (!isEmpty(q1)) {
            int value = dequeue(q1);

            if (value % 2 == 0) {
                value *= 2;
                enqueue(q2, value);
            }
        }

        while (!isEmpty(q2)) {
            int value = dequeue(q2);

            if (value % 2 != 0) {
                enqueue(q3, value);
            }
        }

        while (!isEmpty(q3)) {
            int value = dequeue(q3);

            if (value % 2 == 0) {
                sumQ1 += value * 2;
            } else {
                sumQ1 += value;
            }
        }

        printf("Current sum: %d\n", sumQ1);
    }
}

// Main function
int main() {
    // Initialization of three queues
    struct Queue q1, q2, q3;
    initializeQueue(&q1);
    initializeQueue(&q2);
    initializeQueue(&q3);

    int input;

    while (1) {
        system("clear"); // Use "cls" if you are on Windows

        // Print the current contents of each queue (you can add this part based on your needs)

        printf("Enter a number (1 to 20): ");
        scanf("%d", &input);

        if (input < 1 || input > 20) {
            printf("Invalid input. Please enter a number between 1 and 20.\n");
            continue;
        }

        enqueue(&q1, input);
        processQ1(&q1, &q2, &q3);
    }

    return 0;
}
