//brute force
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a1=0;
        int a2=0;
        int n=nums1.size();
        int m=nums2.size();
        vector<int> merged;
        while(a1 < n && a2 < m){

            if(nums1[a1] <= nums2[a2]){
                merged.push_back(nums1[a1]);
                a1++;
            }
            else{
                merged.push_back(nums2[a2]);
                a2++;
            }
        }

        while(a1 < n){
            merged.push_back(nums1[a1]);
            a1++;
        }

        while(a2 < m){
            merged.push_back(nums2[a2]);
            a2++;
        }
        int total=merged.size();
        if(total%2==0){
            return (merged[total/2 - 1]+merged[(total/2)])/2.0;
        }
        else{
            return (double)merged[total/2];
        }

    }
};