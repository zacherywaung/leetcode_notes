// leetcode283

#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int dest = -1;
        int cur = 0;
        while(cur < nums.size())
        {
            if(nums[cur] == 0)
            {
                cur++;
            }
            else{
                dest++;
                swap(nums[dest], nums[cur]);
                cur++;
            }
        }
    }
};