#include <stdio.h>
#include <stdlib.h>

#define QSIZE 10000

int q[QSIZE];
int front = 0, rear = 0;

void enqueue(int x) {
    q[rear++] = x;
    if (rear == QSIZE) rear = 0;
}

int isEmpty() {
    return front == rear;
}

int peek() {
    return q[front];
}

void dequeue() {
    if (!isEmpty()) {
        front++;
        if (front == QSIZE) front = 0;
    }
}

int main() {
    int freq[256] = {0};
    int ch;
    int firstPrinted = 0;

    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') continue;
        unsigned char c = (unsigned char) ch;
        freq[c]++;
        enqueue(c);
        while (!isEmpty() && freq[(unsigned char)peek()] > 1) dequeue();
        if (firstPrinted) printf(" ");
        if (isEmpty()) printf("-1");
        else printf("%c", (char)peek());
        firstPrinted = 1;
    }

    printf("\n");
    return 0;
}
