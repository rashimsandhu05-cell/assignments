#include <bits/stdc++.h>
using namespace std;

vector<int> h;

void up(int i){
    while(i>0){
        int p=(i-1)/2;
        if(h[p]>=h[i]) break;
        swap(h[p],h[i]);
        i=p;
    }
}

void down(int i){
    int n=h.size();
    while(true){
        int l=2*i+1, r=2*i+2, m=i;
        if(l<n && h[l]>h[m]) m=l;
        if(r<n && h[r]>h[m]) m=r;
        if(m==i) break;
        swap(h[i],h[m]);
        i=m;
    }
}

void insertPQ(int x){
    h.push_back(x);
    up(h.size()-1);
}

int getMaxPQ(){
    if(h.empty()) return -1;
    return h[0];
}

int deleteMaxPQ(){
    if(h.empty()) return -1;
    int v=h[0];
    h[0]=h.back();
    h.pop_back();
    if(!h.empty()) down(0);
    return v;
}

int main(){
    int ch,x;
    while(cin>>ch){
        if(ch==1){ cin>>x; insertPQ(x); }
        else if(ch==2) cout<<deleteMaxPQ()<<" ";
        else if(ch==3) cout<<getMaxPQ()<<" ";
        else break;
    }
}
