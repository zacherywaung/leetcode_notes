//leetcode 39

#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> path;
        int pos = 0;
        int sum = 0;
        dfs(candidates, target, ret, path, pos, sum);
        return ret;
    }

    void dfs(vector<int>& candidates, const int& target, vector<vector<int>>& ret,
    vector<int>& path, int pos, int sum)
    {
        if(sum == target)
        {
            ret.push_back(path);
            return;
        }
        if(sum > target)
        {
            return;
        }
        for(int i = pos; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            dfs(candidates, target, ret, path, i, sum + candidates[i]);
            path.pop_back();
        }
    }
};