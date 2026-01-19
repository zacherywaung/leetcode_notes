//leetcode 77

#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> path;
        //vector<bool> check(k, false);
        vector<int> nums;
        for(int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }
        int pos = 0;
        dfs(ret, path, nums, n, k, pos);
        return ret;
    }

    void dfs(vector<vector<int>>& ret, vector<int>& path, vector<int>& nums, int& n, int& k, int pos)
    {
        if(path.size() == k)
        {
            ret.push_back(path);
            return;
        }
        for(int i = pos; i < n; i++)
        {
            //if(check[i] == false)
            //{
                path.push_back(nums[i]);
                //check[i] = true;
                dfs(ret, path, nums, n, k, i + 1);
                path.pop_back();
                //check[i] = false;
            //}
        }

    }
};