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
//transpose+reverse row wise
for(int i=0; i<matrix.size();i++){
    for(int j=i+1;j<matrix[i].size();j++){
        swap(matrix[i][j],matrix[j][i]);
    }
}

for(int i=0;i<matrix.size();i++){
    reverse(matrix[i].begin(),matrix[i].end());
}

for(int i=0;i<matrix.size();i++){
    for(int j=0; j<matrix[i].size();j++){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
}
cout<<endl<<endl;
//reverse+transpose
int top=0;
int bottom=matrix.size()-1;
while(top<bottom){
    swap(matrix[top],matrix[bottom]);
    top++;
    bottom--;
}
for(int i=0;i<matrix.size();i++){
    for(int j=i+1;j<matrix[i].size();j++){
        swap(matrix[i][j],matrix[j][i]);
    }
}
for(int i=0;i<matrix.size();i++){
    for(int j=0; j<matrix[i].size();j++){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}