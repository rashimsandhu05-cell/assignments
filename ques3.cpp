#include <iostream>
using namespace std;

struct Node{int d;Node *next,*prev;};
Node *head=0;

int size(){
    int c=0;Node*p=head;
    while(p){c++;p=p->next;}
    return c;
}

int main(){
    Node*a=new Node{10,0,0};
    Node*b=new Node{20,0,0};
    Node*c=new Node{30,0,0};
    a->next=b;b->prev=a;
    b->next=c;c->prev=b;
    head=a;

    cout<<size();
}
