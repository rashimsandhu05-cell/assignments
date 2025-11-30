#include <bits/stdc++.h>
using namespace std;

struct Node{
    int d;
    Node *l,*r;
    Node(int x){d=x;l=r=r=NULL;}
};

Node* insertNode(Node* r,int x){
    if(!r) return new Node(x);
    if(x<r->d) r->l=insertNode(r->l,x);
    else if(x>r->d) r->r=insertNode(r->r,x);
    return r;
}

Node* minNode(Node* r){
    while(r->l) r=r->l;
    return r;
}

Node* deleteNode(Node* r,int x){
    if(!r) return r;
    if(x<r->d) r->l=deleteNode(r->l,x);
    else if(x>r->d) r->r=deleteNode(r->r,x);
    else{
        if(!r->l) return r->r;
        if(!r->r) return r->l;
        Node* m=minNode(r->r);
        r->d=m->d;
        r->r=deleteNode(r->r,m->d);
    }
    return r;
}

int maxDepth(Node* r){
    if(!r) return 0;
    return 1+max(maxDepth(r->l),maxDepth(r->r));
}

int minDepth(Node* r){
    if(!r) return 0;
    int L=minDepth(r->l), R=minDepth(r->r);
    if(!r->l || !r->r) return 1+L+R;
    return 1+min(L,R);
}

int main(){
    int n,x; 
    cin>>n;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        root=insertNode(root,x);
    }
    int del; cin>>del;
    root=deleteNode(root,del);
    cout<<maxDepth(root)<<"\n"<<minDepth(root);
}
