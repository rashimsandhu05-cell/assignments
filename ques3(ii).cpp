#include <iostream>
using namespace std;

struct Node{int d;Node*next;};
Node *head=0;

int size(){
    if(!head)return 0;
    int c=0;Node*p=head;
    do{c++;p=p->next;}while(p!=head);
    return c;
}

int main(){
    Node*a=new Node{20,0};
    Node*b=new Node{40,0};
    Node*c=new Node{60,0};
    a->next=b;b->next=c;c->next=a;
    head=a;

    cout<<size();
}
