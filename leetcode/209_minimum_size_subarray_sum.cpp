// leetcode209

#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = INT_MAX;
        int sum = 0;
        int left = 0;
        int right = 0;
        for(right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while(sum >= target)
            {
                int len = right - left + 1;
                if(len < min)
                {
                    min = len;
                }
                sum -= nums[left];
                left++;
            }
        }
        return min == INT_MAX ? 0 : min;
    }
};