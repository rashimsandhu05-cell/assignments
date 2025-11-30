#include <bits/stdc++.h>
using namespace std;

struct Node{
    int d;
    Node *l,*r;
    Node(int x){d=x;l=r=NULL;}
};

Node* insert(Node* r,int x){
    if(!r) return new Node(x);
    if(x<r->d) r->l=insert(r->l,x);
    else r->r=insert(r->r,x);
    return r;
}

Node* recSearch(Node* r,int x){
    if(!r || r->d==x) return r;
    if(x<r->d) return recSearch(r->l,x);
    return recSearch(r->r,x);
}

Node* nonRecSearch(Node* r,int x){
    while(r && r->d!=x){
        if(x<r->d) r=r->l;
        else r=r->r;
    }
    return r;
}

Node* minNode(Node* r){
    while(r->l) r=r->l;
    return r;
}

Node* maxNode(Node* r){
    while(r->r) r=r->r;
    return r;
}

Node* successor(Node* root, int x){
    Node* cur=root,*s=NULL;
    while(cur){
        if(x<cur->d) s=cur, cur=cur->l;
        else cur=cur->r;
    }
    return s;
}

Node* predecessor(Node* root, int x){
    Node* cur=root,*p=NULL;
    while(cur){
        if(x>cur->d) p=cur, cur=cur->r;
        else cur=cur->l;
    }
    return p;
}

int main(){
    int n,x; 
    cin>>n;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        root=insert(root,x);
    }
    cin>>x;

    Node* a=recSearch(root,x);
    Node* b=nonRecSearch(root,x);
    Node* mn=minNode(root);
    Node* mx=maxNode(root);
    Node* s=successor(root,x);
    Node* p=predecessor(root,x);

    if(a) cout<<"Found\n"; else cout<<"Not Found\n";
    if(b) cout<<"Found\n"; else cout<<"Not Found\n";
    cout<<mn->d<<"\n"<<mx->d<<"\n";
    if(s) cout<<s->d<<"\n"; else cout<<"NA\n";
    if(p) cout<<p->d<<"\n"; else cout<<"NA\n";
}
