// leetcode 22

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string path;
        int left = 0;
        int right = 0;
        dfs(ret, path, left, right, n);
        return ret;
    }

    void dfs(vector<string>& ret, string& path, int left, int right, int& n)
    {
        if(path.size() == 2*n)
        {
            ret.push_back(path);
            return;
        }
        if(left < n)
        {
            path.push_back('(');
            dfs(ret, path, left + 1, right, n);
            path.pop_back();
        }
        if(right < left)
        {
            path.push_back(')');
            dfs(ret, path, left, right + 1, n);
            path.pop_back();
        }
    }
};