//leetcode 47

#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        vector<int> check(8, false);
        sort(nums.begin(), nums.end());
        dfs(nums, ret, path, check);
        return ret;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ret, vector<int>& path, vector<int>& check)
    {
        if(path.size() == nums.size())
        {
            ret.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(check[i] == false && (i == 0 || nums[i] != nums[i-1] || check[i-1] == true))
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums, ret, path, check);
                path.pop_back();
                check[i] = false;
            }
        }
    }
};