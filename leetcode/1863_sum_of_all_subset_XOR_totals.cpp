//leetcode1863      easy


#include<vector>
using namespace std;
// class Solution {
// public:
//     int subsetXORSum(vector<int>& nums) {
//         vector<int> path;
//         vector<int> ret;
//         int pos = 0;
//         dfs(nums, path, ret, pos);
//         int sum = 0;
//         for(auto e : ret)
//         {
//             sum += e;
//         }
//         return sum;
//     }

//     void dfs(vector<int>& nums, vector<int>& path, vector<int>& ret, int pos)
//     {
//         if(pos == nums.size())
//         {
//             ret.push_back(calculateXOR(path));
//             return;
//         }
//         //choose
//         path.push_back(nums[pos]);
//         dfs(nums, path, ret, pos + 1);
//         path.pop_back();
//         //unchoose
//         dfs(nums, path, ret, pos + 1);
//     }

//     int calculateXOR(vector<int> path)
//     {
//         int ret = 0;
//         for(int i = 0; i < path.size(); i++)
//         {
//             ret ^= path[i];
//         }
//         return ret;
//     }
// };


class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int path = 0;
        int sum = 0;
        int pos = 0;
        dfs(nums, path, sum, pos);
        return sum;
    }

    void dfs(vector<int>& nums, int& path, int& sum, int pos)
    {
        sum += path;
        for(int i = pos; i < nums.size(); i++)
        {
            path ^= nums[i];
            dfs(nums, path, sum, i + 1);
            path ^= nums[i];
        }
    }

};