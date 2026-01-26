//leetcode494

#include<vector>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int pos = 0;
        int sum = 0;
        int ret = 0;
        dfs(nums, target, pos, sum, ret);
        return ret;
    }

    void dfs(vector<int>& nums, const int& target, int pos, int sum, int& ret)
    {
        if(pos == nums.size())
        {
            if(sum == target)
            {
                ret++;
            }
            return;
        }
        dfs(nums, target, pos + 1, sum += nums[pos], ret);

        sum -= nums[pos];
        dfs(nums, target, pos + 1, sum -= nums[pos], ret);
    }
};