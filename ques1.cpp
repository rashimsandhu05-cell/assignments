#include <bits/stdc++.h>
using namespace std;

struct Node{
    int d;
    Node *l,*r;
    Node(int x){d=x;l=r=NULL;}
};

Node* build(){
    int x; cin>>x;
    if(x==-1) return NULL;
    Node* n=new Node(x);
    n->l=build();
    n->r=build();
    return n;
}

void pre(Node* r){
    if(!r) return;
    cout<<r->d<<" ";
    pre(r->l);
    pre(r->r);
}

void in(Node* r){
    if(!r) return;
    in(r->l);
    cout<<r->d<<" ";
    in(r->r);
}

void post(Node* r){
    if(!r) return;
    post(r->l);
    post(r->r);
    cout<<r->d<<" ";
}

int main(){
    Node* root=build();
    pre(root); cout<<"\n";
    in(root); cout<<"\n";
    post(root);
}
