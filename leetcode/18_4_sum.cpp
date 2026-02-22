// leetcode18

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int d = nums.size() - 1;
        for(d = nums.size() - 1; d >= 3; d--)
        {
            if(d != nums.size() - 1 && nums[d] == nums[d + 1]) continue;
            if(nums[d] < target / 4) break; // optimize
            for(int c = d - 1; c >= 2; c--)
            {
                if(c != d - 1 && nums[c] == nums[c + 1]) continue;
                int left = 0;
                int right = c - 1;
                while(left < right)
                {
                    long long tmp1 = (long long)nums[left] + nums[right];
                    long long tmp2 = (long long)target - nums[c] - nums[d];
                    if(tmp1 < tmp2)
                    {
                        left++;
                    }
                    else if(tmp1 > tmp2)
                    {
                        right--;
                    }
                    else{
                        ret.push_back({nums[left], nums[right], nums[c], nums[d]});
                        do{
                            left++;
                        }while(nums[left] == nums[left - 1] && left < right);
                        do{
                            right--;
                        }while(nums[right] == nums[right + 1] && left < right);
                    }
                }
                
            }
        }
        return ret;
    }
};