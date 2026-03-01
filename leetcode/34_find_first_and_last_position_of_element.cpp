// leetcode34

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        // left side
        int left = 0;
        int right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else // nums[mid] >= target
            {
                right = mid;
            }
        }
        if(nums[left] != target) return {-1, -1};
        int begin = left;
        left = 0;
        right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if(nums[mid] <= target)
            {
                left = mid;
            }
            else // nums[mid] > target
            {
                right = mid - 1;
            }
        }
        int end = right;
        return {begin, end};
    }
};