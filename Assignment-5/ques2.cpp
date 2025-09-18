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

int deleteOccurrences(int key) {
    int count = 0;
    while (head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        count++;
    }
    Node* cur = head;
    while (cur && cur->next) {
        if (cur->next->data == key) {
            Node* t = cur->next;
            cur->next = cur->next->next;
            delete t;
            count++;
        } else cur = cur->next;
    }
    return count;
}

void display() {
    Node* t = head;
    if (!t) { cout << "Empty\n"; return; }
    while (t) { cout << t->data << " "; t = t->next; }
    cout << "\n";
}

int main() {
    int ch, x, key;
    while (1) {
        cout << "1.InsertEnd 2.Display 3.DeleteOccurrences 4.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> x; insertEnd(x); break;
            case 2: display(); break;
            case 3: cin >> key; cout << "Count: " << deleteOccurrences(key) << "\n"; break;
            case 4: return 0;
        }
    }
}
