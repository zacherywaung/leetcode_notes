//leetcode376

#include <vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int cnt = 0;
        int left = 0;
        int right = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            right = nums[i + 1] - nums[i];
            if(right == 0) continue;
            if(right * left <= 0)
            {
                cnt++;
            }
            left = right;
        }
        return cnt + 1;
    }
};