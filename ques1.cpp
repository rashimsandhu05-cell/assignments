#include <iostream>
using namespace std;

void sel(int a[],int n){
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++) if(a[j]<a[m]) m=j;
        swap(a[i],a[m]);
    }
}

void ins(int a[],int n){
    for(int i=1;i<n;i++){
        int k=a[i],j=i-1;
        while(j>=0 && a[j]>k){a[j+1]=a[j];j--;}
        a[j+1]=k;
    }
}

void bub(int a[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
}

void merge(int a[],int l,int m,int r){
    int n1=m-l+1,n2=r-m,x[50],y[50];
    for(int i=0;i<n1;i++) x[i]=a[l+i];
    for(int i=0;i<n2;i++) y[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1&&j<n2) a[k++]=x[i]<=y[j]?x[i++]:y[j++];
    while(i<n1) a[k++]=x[i++];
    while(j<n2) a[k++]=y[j++];
}

void merges(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        merges(a,l,m);
        merges(a,m+1,r);
        merge(a,l,m,r);
    }
}

int part(int a[],int l,int r){
    int p=a[r],i=l-1;
    for(int j=l;j<r;j++) if(a[j]<p) swap(a[++i],a[j]);
    swap(a[i+1],a[r]);
    return i+1;
}

void quick(int a[],int l,int r){
    if(l<r){
        int p=part(a,l,r);
        quick(a,l,p-1);
        quick(a,p+1,r);
    }
}

int main(){
    int n,i,c,a[50];
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    cin>>c;
    switch(c){
        case 1: sel(a,n); break;
        case 2: ins(a,n); break;
        case 3: bub(a,n); break;
        case 4: merges(a,0,n-1); break;
        case 5: quick(a,0,n-1); break;
    }
    for(i=0;i<n;i++) cout<<a[i]<<" ";
}
