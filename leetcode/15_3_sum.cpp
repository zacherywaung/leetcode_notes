// leetcode15

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int c = 0;
        for(c = nums.size() - 1; c >= 2; c--)
        {
            if(c != nums.size() - 1 && nums[c] == nums[c + 1]) continue;
            int left = 0;
            int right = c - 1;
            while(left < right)
            {
                if(nums[left] + nums[right] < -nums[c])
                {
                    left++;
                }
                else if(nums[left] + nums[right] > -nums[c])
                {
                    right--;
                }
                else{
                    ret.push_back({nums[left], nums[right], nums[c]});
                    left++;
                    right--;
                    while(nums[left] == nums[left - 1] && left < right) left++;
                    while(nums[right] == nums[right + 1] && left < right) right--;
                }
            }
        }
        return ret;
    }
};