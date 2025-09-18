#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int q[MAX];
int front=0, rear=0;

int isEmpty() { return front==rear; }
int size() { return rear - front; }
void enqueue(int x) { q[rear++]=x; }
int dequeue() { return q[front++]; }
int qfront() { return q[front]; }

void push_one(int x) {
    enqueue(x);
    int s = size();
    for (int i=0;i<s-1;i++) enqueue(dequeue());
}

void pop_one() {
    if (isEmpty()) { printf("Stack Underflow\n"); return; }
    printf("%d popped\n", dequeue());
}

void peek_one() {
    if (isEmpty()) { printf("Stack is Empty\n"); return; }
    printf("Top: %d\n", qfront());
}

void display_one() {
    if (isEmpty()) { printf("Stack is Empty\n"); return; }
    for (int i=front;i<rear;i++) printf("%d ", q[i]);
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        if (scanf("%d", &choice)!=1) return 0;
        switch (choice) {
            case 1: scanf("%d", &val); push_one(val); break;
            case 2: pop_one(); break;
            case 3: peek_one(); break;
            case 4: display_one(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
