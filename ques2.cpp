#include <iostream>
using namespace std;

struct Node { int data; Node *next; };
Node *head = 0;

void display() {
    if (!head) return;
    Node *p = head;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << head->data << "\n";
}

int main() {
    Node *a=new Node{20,0};
    Node *b=new Node{100,0};
    Node *c=new Node{40,0};
    Node *d=new Node{80,0};
    Node *e=new Node{60,0};
    a->next=b; b->next=c; c->next=d; d->next=e; e->next=a;
    head=a;

    display();
}
