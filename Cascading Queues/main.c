#include <stdio.h>
#include <stdlib.h>


struct Queue {
    int items[5];
    int front;
    int rear;
    int count;
};


void initializeQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}


int isEmpty(struct Queue* q) {
    return q->count == 0;
}


int isFull(struct Queue* q) {
    return q->count == 5;
}


void enqueue(struct Queue* q, int value) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % 5;
        q->items[q->rear] = value;
        q->count++;
    }
}


int dequeue(struct Queue* q) {
    if (!isEmpty(q)) {
        int value = q->items[q->front];
        q->front = (q->front + 1) % 5;
        q->count--;
        return value;
    }
    return -1;
}


int computeSum(struct Queue* q) {
    int sum = 0;
    for (int i = 0; i < q->count; i++) {
        sum += q->items[(q->front + i) % 5];
    }
    return sum;
}


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

int main() {
    struct Queue q1, q2, q3;
    initializeQueue(&q1);
    initializeQueue(&q2);
    initializeQueue(&q3);
    system("cls"); //for a clear console

    int input;

    while (1) {


// Print the current contents of each queue
            printf("Queue 1 (Q1): ");
        for (int i = 0; i < q1.count; i++) {
            printf("%d ", q1.items[(q1.front + i) % 5]);
        }
            printf("\n");

            printf("Queue 2 (Q2): ");
        for (int i = 0; i < q2.count; i++) {
            printf("%d ", q2.items[(q2.front + i) % 5]);
        }
            printf("\n");

            printf("Queue 3 (Q3): ");
        for (int i = 0; i < q3.count; i++) {
            printf("%d ", q3.items[(q3.front + i) % 5]);
        }
            printf("\n");

// Get user input
            printf("Enter a number (1 to 20): ");
            scanf("%d", &input);

// Validate user input
        if (input < 1 || input > 20) {
            printf("Invalid input. Please enter a number between 1 and 20.\n");
        continue;
        }

// Enqueue the input to Q1
        enqueue(&q1, input);

// Process and update queues
        processQ1(&q1, &q2, &q3);
    }

    return 0;
}
