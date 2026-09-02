#define IS_ODD  1
#define IS_EVEN 2
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> pos;
        for (int i = 0; i < nums1.size(); i++) {
            pos.push_back(0);
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (abs(nums1[i]) % 2 == 1) {
                pos[i] |= IS_ODD;
            } else {
                pos[i] |= IS_EVEN;
            }

            for (int j = 0; j < nums1.size(); j++) {
                if (i == j) {
                    continue;
                }
                // cout << nums1[ << i << ] - nums1[ << j << ]:  << nums1[i] - nums1[j] << endl;
                if (abs(nums1[i] - nums1[j]) % 2 == 1) {
                    pos[i] |= IS_ODD;
                } else {
                    pos[i] |= IS_EVEN;
                }
            }
        }

        bool nextCanBeOdd = true;
        bool nextCanBeEven = true;
        for (int p : pos) {
            // cout << p:  << p << , p & IS_ODD:  << (p & IS_ODD == 0) << , p & IS_EVEN:  << ((p & IS_EVEN) == 0) << endl;

            if (p & IS_ODD == 0) {
                if (!nextCanBeEven) {
                    return false;
                }
                nextCanBeOdd = false;
            }

            if (p & IS_EVEN == 0) {
                if (!nextCanBeOdd) {
                    return false;
                }
                nextCanBeEven = false;
            }
        }
        return true;
    }
};