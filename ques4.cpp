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

bool isBST(Node* r, long mn, long mx){
    if(!r) return true;
    if(r->d<=mn || r->d>=mx) return false;
    return isBST(r->l,mn,r->d) && isBST(r->r,r->d,mx);
}

int main(){
    Node* root=build();
    if(isBST(root,LLONG_MIN,LLONG_MAX)) cout<<"YES";
    else cout<<"NO";
}
