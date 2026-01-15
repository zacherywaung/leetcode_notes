//leetcode 17   mid

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string path;
        vector<string> ret;
        vector<string> map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int pos = 0;
        dfs(digits, path, ret, map, pos);
        return ret;
    }

    void dfs(string& digits, string& path, vector<string>& ret, vector<string>& map, int pos)
    {
        if(path.size() == digits.size())
        {
            ret.push_back(path);
            return;
        }
        for(int i = 0; i < map[digits[pos] - '0'].size(); i++)
        {
            path.push_back(map[digits[pos] - '0'][i]);
            dfs(digits, path, ret, map, pos + 1);
            path.pop_back();
        }
    }
};

