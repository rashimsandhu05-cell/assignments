#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head = NULL;

void insertBeg(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = head;
    head = p;
}

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

void deleteBeg() {
    if (!head) return;
    Node* t = head;
    head = head->next;
    delete t;
}

void deleteEnd() {
    if (!head) return;
    if (!head->next) { delete head; head = NULL; return; }
    Node* t = head;
    while (t->next->next) t = t->next;
    delete t->next;
    t->next = NULL;
}

void deleteNode(int key) {
    if (!head) return;
    if (head->data == key) { Node* t = head; head = head->next; delete t; return; }
    Node* t = head;
    while (t->next && t->next->data != key) t = t->next;
    if (t->next) { Node* d = t->next; t->next = d->next; delete d; }
}

void searchNode(int key) {
    Node* t = head;
    int pos = 1;
    while (t) {
        if (t->data == key) { cout << pos << "\n"; return; }
        t = t->next; pos++;
    }
    cout << -1 << "\n";
}

void display() {
    Node* t = head;
    while (t) { cout << t->data << " "; t = t->next; }
    cout << "\n";
}

int main() {
    int ch, x, key;
    while (1) {
        cout << "1.InsertBeg 2.InsertEnd 3.DeleteBeg 4.DeleteEnd 5.DeleteNode 6.Search 7.Display 8.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> x; insertBeg(x); break;
            case 2: cin >> x; insertEnd(x); break;
            case 3: deleteBeg(); break;
            case 4: deleteEnd(); break;
            case 5: cin >> key; deleteNode(key); break;
            case 6: cin >> key; searchNode(key); break;
            case 7: display(); break;
            case 8: return 0;
        }
    }
}
