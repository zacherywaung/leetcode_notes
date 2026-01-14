// leetcode46  mid

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        vector<bool> check(7, false);
        dfs(ret, nums, path, check);
        return ret;
    }

    void dfs(vector<vector<int>>& ret, vector<int>& nums, vector<int>& path, vector<bool>& check)
    {
        if(path.size() == nums.size())
        {
            ret.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(check[i] == false)
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(ret, nums, path, check);
                path.pop_back();
                check[i] = false;
            }
        }
    }
};
