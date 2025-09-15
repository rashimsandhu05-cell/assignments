#include<iostream>
using namespace std;

int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];

    cout<<"---Enter the elements of the array---"<<endl;
    for(int i=0;i<size;++i){
        cin>>arr[i];
    }

    int arr1[size];
    for(int i=0;i<size;++i){
        arr1[i]=arr[size-1-i];

    }

    cout<<"---Reverse Array---"<<endl;

    for(int i=0;i<size;++i){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    return 0;


}