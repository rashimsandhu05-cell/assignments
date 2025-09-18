#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int q1[MAX], q2[MAX];
int f1=0, r1=0, f2=0, r2=0;

int q1_empty() { return f1==r1; }
int q2_empty() { return f2==r2; }
int q1_size() { return r1 - f1; }
int q2_size() { return r2 - f2; }

void q1_enqueue(int x) { q1[r1++] = x; }
int q1_dequeue() { return q1[f1++]; }
int q1_front() { return q1[f1]; }

void q2_enqueue(int x) { q2[r2++] = x; }
int q2_dequeue() { return q2[f2++]; }

void push(int x) {
    q2_enqueue(x);
    while (!q1_empty()) q2_enqueue(q1_dequeue());
    int i=0;
    for (i=f2;i<r2;i++) q1[i-f2]=q2[i];
    r1 = r2 - f2;
    f1 = 0;
    r1 = r1;
    f2 = r2 = 0;
}

void pop_stack() {
    if (q1_empty()) { printf("Stack Underflow\n"); return; }
    printf("%d popped\n", q1_dequeue());
}

void peek_stack() {
    if (q1_empty()) { printf("Stack is Empty\n"); return; }
    printf("Top: %d\n", q1_front());
}

void display_stack() {
    if (q1_empty()) { printf("Stack is Empty\n"); return; }
    for (int i=f1;i<r1;i++) printf("%d ", q1[i]);
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        if (scanf("%d", &choice)!=1) return 0;
        switch (choice) {
            case 1: scanf("%d", &val); push(val); break;
            case 2: pop_stack(); break;
            case 3: peek_stack(); break;
            case 4: display_stack(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
