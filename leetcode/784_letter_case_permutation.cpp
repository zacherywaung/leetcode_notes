//leetcode 784 mid

#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        string path;
        vector<string> ret;
        int pos = 0;
        dfs(ret, path, pos, s);
        return ret;
    }

    void dfs(vector<string>& ret, string& path, int pos, const string& s)
    {
        if(path.size() == s.size())
        {
            ret.push_back(path);
            return;
        }
        if(s[pos] >= '0' && s[pos] <= '9')
        {
            path.push_back(s[pos]);
            dfs(ret, path, pos + 1, s);
            path.pop_back();
        }
        else{
            if(s[pos] >= 'A' && s[pos] <= 'Z')
            {
                path.push_back(s[pos]);
                dfs(ret, path, pos + 1, s);
                path.pop_back();
                path.push_back(s[pos] + 32);
                dfs(ret, path, pos + 1, s);
                path.pop_back();
            }
            else
            {
                path.push_back(s[pos]);
                dfs(ret, path, pos + 1, s);
                path.pop_back();
                path.push_back(s[pos] - 32);
                dfs(ret, path, pos + 1, s);
                path.pop_back();
            }
        }


    }
};