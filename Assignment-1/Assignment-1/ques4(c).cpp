#include<iostream>
using namespace std;

int main(){
    int row,col;

    cout<<"---Matrix---"<<endl;
    cout<<"Enter the number of rows in matrix: ";
    cin>>row;
    cout<<"Enter the number of coloumns in matrix: ";
    cin>>col;

    int matrix[row][col];

    cout<<"Enter the elements in matrix: "<<endl;
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            cin>>matrix[i][j];
        }
    }

    int transpose[col][row];

    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            transpose[j][i] = matrix[i][j];
        }
    }

    cout<<"---Transpose Matrix---"<<endl;
    for(int i=0;i<col;++i){
        for(int j=0;j<row;++j){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;


}