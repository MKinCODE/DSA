#include<vector>
using namespace std;

//two pointer approach with time complexity: O(n+m)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                ans=max(ans,j-i);  //it will carefully handle i<j as if i>j difference is negative which will fail to occupy space in ans due to max func
                j++;
            }
            else i++;
        }
        return ans;
    }
};

//not the most optimal but a standard Binary search approach with time complexity: O(n log(m))
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int low,high;
        int m=nums2.size();
        int ans=0;
        for(int i=0; i<n; i++){
            low=i;
            high=m-1;
            while(low<=high){
                int mid = low + (high - low)/2;
                if(nums1[i]<=nums2[mid]){
                    ans=max(ans,mid-i);
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return ans;
    }
};