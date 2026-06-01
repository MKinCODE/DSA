#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            vector<int> row(i+1,1);                     //create row for each numrows initialised with 1
            for(int j=1;j<i;j++){                       //start with j=1 as j=0 & j=i for each row is same, i.e. 1
                row[j]=ans[i-1][j] + ans[i-1][j-1];     // then the 1 for each col can be modified
            }
            ans.push_back(row);                         //push final row created into final ans
        }
        return ans;
    }
};