#include <vector>
#include <algorithm>
using namespace std;
//this approach is used since arr[i]<10^5, so we can use counting sort to find the frequency of each element in arr and then sort the frequency array in descending order and keep subtracting the frequency from total until total is less than or equal to size/2, and count the number of elements we have subtracted, which will be our answer.
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size=arr.size()/2;
        int maxi=*max_element(arr.begin(),arr.end());

        vector<int> freq(maxi + 1, 0);

        for(int x:arr) freq[x]++;

        int ans=0;
        int total=arr.size();
        sort(freq.rbegin(), freq.rend());
        for(int x:freq){
            total-=x;
            ans++;
            if(total<=size) break;
        }
        return ans;
    }
};
//if the elements in arr are not less than 10^5, then we can use a hash map and vector to store the frequency of each element and then sort the vector in descending order and keep subtracting the frequency from total until total is less than or equal to size/2, and count the number of elements we have subtracted, which will be our answer.