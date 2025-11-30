#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>&a,int n,int i){
    int l=2*i+1,r=2*i+2,m=i;
    if(l<n && a[l]>a[m]) m=l;
    if(r<n && a[r]>a[m]) m=r;
    if(m!=i){ swap(a[i],a[m]); heapify(a,n,m); }
}

void heapsortInc(vector<int>&a){
    int n=a.size();
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

void heapsortDec(vector<int>&a){
    heapsortInc(a);
    reverse(a.begin(),a.end());
}

int main(){
    int n; cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int ch; cin>>ch;

    if(ch==1) heapsortInc(a);
    else heapsortDec(a);

    for(int x:a) cout<<x<<" ";
}
