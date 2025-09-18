#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(Queue *q, int val) {
    if (isFull(q)) return;
    if (isEmpty(q)) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = val;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    int val = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MAX;
    return val;
}

void interleaveQueue(Queue *q) {
    int size = (q->rear - q->front + MAX) % MAX + 1;
    if (size % 2 != 0) {
        printf("Queue size must be even\n");
        return;
    }
    Queue firstHalf;
    initQueue(&firstHalf);

    for (int i = 0; i < size / 2; i++) {
        enqueue(&firstHalf, dequeue(q));
    }

    while (!isEmpty(&firstHalf)) {
        enqueue(q, dequeue(&firstHalf));
        enqueue(q, dequeue(q));
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    int n, val;
    scanf("%d", &n);  
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    interleaveQueue(&q);
    display(&q);

    return 0;
}
