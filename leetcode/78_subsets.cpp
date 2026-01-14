// leetcode78  mid

#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        int i = 0;
        dfs(nums, ret, path, i);
        return ret;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ret, vector<int>& path, int i)
    {
        if(i == nums.size())
        {
            ret.push_back(path);
            return;
        }
        //choose
        path.push_back(nums[i]);
        dfs(nums, ret, path, i + 1);
        path.pop_back();

        //unchoose
        dfs(nums, ret, path, i + 1);
    }
};



// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ret;
//         vector<int> path;
//         int i = 0;
//         dfs(nums, ret, path, i);
//         return ret;
//     }

//     void dfs(vector<int>& nums, vector<vector<int>>& ret, vector<int>& path, int pos)
//     {
//         ret.push_back(path);
//         for(int i = pos; i < nums.size(); i++)
//         {
//             path.push_back(nums[i]);
//             dfs(nums, ret, path, i + 1);
//             path.pop_back();
//         }

//     }
// };