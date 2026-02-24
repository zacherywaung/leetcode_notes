// leetcode1004

#include <vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ret = 0;
        int cnt = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        for(right = 0; right < n; right++)
        {
            if(nums[right] == 0) cnt++;
            while(cnt > k)
            {
                if(nums[left] == 0) cnt--;
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};