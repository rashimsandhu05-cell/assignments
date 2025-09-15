#include<iostream>
using namespace std;

int size;
int arr[100];

void Create(int arr[],int &size){
    cout<<"Enter elements in the array: "<<endl;
    for(int i=0;i<size;++i){
        cin>>arr[i];
    }

}

void Display(int arr[],int &size){
    cout<<"Elements in the array: ";
    for(int i=0;i<size;++i){
        cout<<arr[i];
        if(i<size-1){
            cout<<", ";
        }
    }
    cout<<endl;
}

void Insert(int arr[],int &pos,int &element){
    size+=1;
    for(int i=size;i>=pos-1;--i){
        if(i==pos-1){
            arr[i]=element;
        }
        else{
            arr[i+1]=arr[i];
        }

    }
}

void Delete(int arr[], int &pos){
    for(int i=pos-1;i<size;++i){
        arr[i]=arr[i+1];
    }
    --size;
}

void Search(int arr[],int &element){
    for(int i=0;i<size;++i){
        if(arr[i]==element){
            cout<<"Element found at "<<i+1<<" position"<<endl;
        }
    }
}

int main(){
    int pos,element;
    cout<<"---MENU PROGRAM---"<<endl;
    int choice;
    while(true){
        cout<<"1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter the number of elements in array: ";
            cin>>size;
            Create(arr,size);
            break;
            case 2:
            Display(arr,size);
            break;
            case 3:
            cout<<"Enter the position to insert an element: ";
            cin>>pos;
            cout<<"Enter the element to insert in the array: ";
            cin>>element;
            Insert(arr,pos,element);
            break;
            case 4:
            cout<<"Enter the position to delete an element: ";
            cin>>pos;
            Delete(arr,pos);
            break;
            case 5:
            cout<<"Enter the element to search in the array: ";
            cin>>element;
            Search(arr,element);
            break;
            case 6:
            return 0;;
            default:
            cout<<"Invalid command!"<<endl;


        }

    }
    
}