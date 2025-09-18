#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = val;
    printf("%d inserted\n", val);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("%d deleted\n", queue[front++]);
}

void isEmpty() {
    if (front == -1 || front > rear)
        printf("Queue is Empty\n");
    else
        printf("Queue is not Empty\n");
}

void isFull() {
    if (rear == MAX - 1)
        printf("Queue is Full\n");
    else
        printf("Queue is not Full\n");
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void peek() {
    if (front == -1 || front > rear)
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
