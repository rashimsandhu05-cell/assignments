#include <iostream>
using namespace std;

struct Node{int d;Node*next;};

bool circular(Node* h){
    if(!h) return false;
    Node*t=h->next;
    while(t && t!=h) t=t->next;
    return t==h;
}

int main(){
    Node*a=new Node{2,0};
    Node*b=new Node{4,0};
    Node*c=new Node{6,0};
    Node*d=new Node{7,0};
    Node*e=new Node{5,0};
    a->next=b;b->next=c;c->next=d;d->next=e;e->next=a;

    cout<<(circular(a)?"True":"False");
}
