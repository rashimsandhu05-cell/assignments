#include <iostream>
using namespace std;
const int MAX = 5;
int q[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        cout << "Queue is Full\n";
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    q[rear] = x;
    cout << x << " inserted\n";
}

void dequeue() {
    if (front == -1) {
        cout << "Queue is Empty\n";
        return;
    }
    cout << q[front] << " deleted\n";
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

void isEmpty() {
    if (front == -1) cout << "Queue is Empty\n";
    else cout << "Queue is not Empty\n";
}

void isFull() {
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front)
        cout << "Queue is Full\n";
    else
        cout << "Queue is not Full\n";
}

void display() {
    if (front == -1) { cout << "Queue is Empty\n"; return; }
    int i = front;
    while (true) {
        cout << q[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << "\n";
}

void peek() {
    if (front == -1) cout << "Queue is Empty\n";
    else cout << "Front element: " << q[front] << "\n";
}

int main() {
    int choice, val;
    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; enqueue(val); break;
            case 2: dequeue(); break;
            case 3: isEmpty(); break;
            case 4: isFull(); break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}

