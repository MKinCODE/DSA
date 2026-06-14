#include<vector>
using namespace std;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1,0);
        for(int i=0; i<bookings.size();i++){
            for(int j=bookings[i][0]; j<=bookings[i][1]; j++){
                diff[j]+=bookings[i][2];
            }
        }
        return vector<int>(diff.begin()+1,diff.end());
    }
};