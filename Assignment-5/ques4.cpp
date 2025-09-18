#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head = NULL;

void insertEnd(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    if (!head) head = p;
    else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = p;
    }
}

void display() {
    Node* t = head;
    if (!t) { cout << "Empty\n"; return; }
    while (t) { cout << t->data << " "; t = t->next; }
    cout << "NULL\n";
}

void reverseList() {
    Node* prev = NULL;
    Node* cur = head;
    Node* next = NULL;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

int main() {
    int ch, x;
    while (1) {
        cout << "1.InsertEnd 2.Display 3.Reverse 4.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> x; insertEnd(x); break;
            case 2: display(); break;
            case 3: reverseList(); break;
            case 4: return 0;
        }
    }
}
