#include <iostream>
using namespace std;

struct Node{char d;Node*next,*prev;};
Node*head=0;

bool pal(){
    if(!head)return true;
    Node*l=head,*r=head;
    while(r->next)r=r->next;
    while(l!=r && r->next!=l){
        if(l->d!=r->d)return false;
        l=l->next;
        r=r->prev;
    }
    return true;
}

int main(){
    Node*a=new Node{'L',0,0};
    Node*b=new Node{'E',0,0};
    Node*c=new Node{'V',0,0};
    Node*d=new Node{'E',0,0};
    Node*e=new Node{'L',0,0};
    a->next=b;b->prev=a;
    b->next=c;c->prev=b;
    c->next=d;d->prev=c;
    d->next=e;e->prev=d;
    head=a;

    cout<<(pal()?"True":"False");
}
