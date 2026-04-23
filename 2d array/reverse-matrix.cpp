#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
int top=0;
int bottom=matrix.size()-1;            // size of matrix = no. of rows
while(top<bottom){
    swap(matrix[top],matrix[bottom]);     // matrix[top],matrix[bottom] = whole row,i.e. vector<int>
    top++;
    bottom--;
}
for(int i=0;i<matrix.size();i++){
    for(int j=0; j<matrix[i].size();j++){    //size of matrix[i] = no. of columns(sometimes in each row)
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}