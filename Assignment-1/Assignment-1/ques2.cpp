#include<iostream>
using namespace std;

int size;

void Delete(int pos,int arr[]){
    for(int k=pos;k<size;++k){
        arr[k]=arr[k+1];

    }
    --size;
}


int main(){
    
    
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];

    cout<<"---Enter the elements in the array---"<<endl;

    for (int i=0;i<size;++i){
        cin>>arr[i];
    }

    for(int i=0;i<size-1;++i){
        for(int j=i+1;j<size;++j){
            if (arr[i]==arr[j]){
                Delete(j,arr);
                --j;
            }
        }
    }

    cout<<"---Unique Elements in the Array---"<<endl;

    for(int i=0;i<size;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;

}