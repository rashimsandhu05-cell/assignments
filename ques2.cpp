#include <iostream>
using namespace std;

int main(){
    int n,a[50];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    int l=0,r=n-1;
    while(l<r){
        int mn=l,mx=l;
        for(int i=l;i<=r;i++){
            if(a[i]<a[mn]) mn=i;
            if(a[i]>a[mx]) mx=i;
        }
        swap(a[l],a[mn]);
        if(mx==l) mx=mn;
        swap(a[r],a[mx]);
        l++; r--;
    }

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
