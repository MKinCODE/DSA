#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// time complexity O(log m*n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int row = mid / n;         //converting 1D mid in 2D
            int col = mid % n;         //memorize

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};


// time complexity O(mlogn)
// class Solution
// {
// public:
//     bool searchMatrix(vector<vector<int>> &matrix, int target)
//     {
//         int n = matrix[0].size();
//         for (int i = 0; i < matrix.size(); i++)
//         {
//             if (target > matrix[i][n - 1])
//             {
//                 continue;
//             }
//             else if (target == matrix[i][n - 1])
//             {
//                 return true;
//             }
//             else
//             {
//                 int l = 0;
//                 int h = n - 1;
//                 while (l <= h)
//                 {
//                     int mid = ((l + h) / 2);
//                     if (target == matrix[i][mid])
//                     {
//                         return true;
//                     }
//                     else if (target < matrix[i][mid])
//                     {
//                         h = mid - 1;
//                     }
//                     else
//                     {
//                         l = mid + 1;
//                     }
//                 }
//             }
//         }
//     return false
//     }

