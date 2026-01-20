#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> x;vector<int> y;
        for(int i=0;i<matrix.size();i++){
            for(int j=0; j<matrix[i].size();j++){
                if(matrix[i][j]==0){x.push_back(i);y.push_back(j);}
                continue;
            }
        }
        int n=0;
        int a;
        int b;
        while(n!=x.size()){
            a=x[n];
            b=y[n];
            for(int j=0;j<matrix[0].size();j++){
                matrix[a][j]=0;
            }
             for(int i=0;i<matrix.size();i++){
                matrix[i][b]=0;
            }
            n++;
        }
    }
};

//optimise solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool firstrow= false;
        bool firstcol = false;
        //check first column has a zero or not
        for(int i=0; i<m; i++){
            if(matrix[i][0]==0){
                firstcol=true;
            }
        }
        //check first row has a zero or not
        for(int j=0; j<n; j++){
            if(matrix[0][j]==0){
                firstrow=true;
            }
        }
        //check for zero in whole matrix and mark them using first row & column
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        // applying row markers
        for(int i=1;i<m;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        // applying column markers
        for(int j=1;j<n;j++){
            if(matrix[0][j]==0){
                for(int i=1;i<m;i++){
                    matrix[i][j]=0;
                }
            }
        }
        //handle firstcol value
        if(firstcol){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
        //handle firstrow value
        if(firstrow){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        
    }
};