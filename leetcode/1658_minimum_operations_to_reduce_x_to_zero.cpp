// leetcode1658

#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ret = 0;
        int cur = 0;
        int sum = 0;
        for(auto e : nums)
        {
            sum += e;
        }
        int target = sum - x;
        if(target < 0) return -1;
        if(target == 0) return nums.size();
        for(int left = 0, right = 0; right < nums.size(); right++)
        {
            cur += nums[right];
            while(cur > target)
            {
                cur -= nums[left];
                left++;
            }
            if(cur == target)
            {
                ret = max(ret, right - left + 1);
            }
        }
        if(ret == 0) return -1;
        return nums.size() - ret;
    }
};