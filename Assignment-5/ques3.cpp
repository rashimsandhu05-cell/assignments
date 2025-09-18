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
    cout << "\n";
}

void findMiddle() {
    if (!head) { cout << "List is empty\n"; return; }
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle: " << slow->data << "\n";
}

int main() {
    int ch, x;
    while (1) {
        cout << "1.InsertEnd 2.Display 3.FindMiddle 4.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> x; insertEnd(x); break;
            case 2: display(); break;
            case 3: findMiddle(); break;
            case 4: return 0;
        }
    }
}
