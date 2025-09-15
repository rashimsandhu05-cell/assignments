#include<iostream>
using namespace std;

int main(){
    int row1,col1,row2,col2;
    
    cout<<"---Matrix 1---"<<endl;
    cout<<"Enter the number of rows in Matrix 1: ";
    cin>>row1;
    cout<<"Enter the number of coloumns in Matrix 1: ";
    cin>>col1;
    int matrix1[row1][col1];
    cout<<"Enter the Elements: "<<endl;
    for(int i=0;i<row1;++i){
        for(int j=0;j<col1;++j){
            cin>>matrix1[i][j];
        }
    }

    cout<<"---Matrix 2---"<<endl;
    cout<<"Enter the number of rows in Matrix 2: ";
    cin>>row2;
    cout<<"Enter the number of coloumns in Matrix 2: ";
    cin>>col2;
    int matrix2[row2][col2];
    cout<<"Enter the Elements: "<<endl;
    for(int i=0;i<row2;++i){
        for(int j=0;j<col2;++j){
            cin>>matrix2[i][j];
        }
    }

    int result[col1][row2];
    for(int i=0;i<col1;++i){
        for(int j=0;j<row2;++j){
            result[i][j]=0;
        }
    }

    if(col1==row2){
        for(int i=0;i<row1;++i){
            for(int j=0;j<col2;++j){
                for(int k=0;k<col1;++k){
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        cout<<"---Matrix Multipilcation---"<<endl;
        for(int i=0;i<row1;++i){
            for(int j=0;j<col2;++j){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
        

    }
    else{
        cout<<"MATRIX MULTIPLICATION NOT POSSIBLE!"<<endl;
    }

    return 0;

}