#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int val) {
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = val;
    printf("%d inserted\n", val);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("%d deleted\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void isEmpty() {
    if (front == -1)
        printf("Queue is Empty\n");
    else
        printf("Queue is not Empty\n");
}

void isFull() {
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front)
        printf("Queue is Full\n");
    else
        printf("Queue is not Full\n");
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void peek() {
    if (front == -1)
        printf("Queue is Empty\n");
    else
        printf("Front element: %d\n", queue[front]);
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: scanf("%d", &val); enqueue(val); break;
            case 2: dequeue(); break;
            case 3: isEmpty(); break;
            case 4: isFull(); break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
