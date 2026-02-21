// leetcode611

#include <vector>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ret = 0;
        for(int c = n - 1; c >= 2; c--)
        {
            int left = 0;
            int right = c - 1;
            while(left < right)
            {
                if(nums[left] + nums[right] > nums[c])
                {
                    ret += right - left;
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return ret;
    }
};