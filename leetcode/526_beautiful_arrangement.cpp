//leetcode 526 mid

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        vector<int> path;
        int ret = 0;
        vector<bool> check_use(n, false);
        dfs(n, path, ret, check_use);
        return ret;
    }

    bool check(int n, int index)
    {
        if(n % index != 0 && index % n != 0)
        {
            return false;
        }
        return true;
    }

    void dfs(int& n, vector<int>& path, int& ret, vector<bool>& check_use)
    {
        if(path.size() == n)
        {
            ret++;
            return;
        }
        for(int i = 1; i <= n; i++)
        {
            if(!check_use[i - 1] && check(i, path.size() + 1))
            {
                path.push_back(i);
                check_use[i - 1] = true;
                dfs(n, path, ret, check_use);
                path.pop_back();
                check_use[i - 1] = false;
            }
        }
    }
};