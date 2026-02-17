// leetcode91

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool is_valid(char c)
    {
        return '1' <= c && c <= '9';
    }

    bool is_valid_double(char x, char y)
    {
        int tmp = 10*(x - '0') + y - '0';
        return tmp >= 10 && tmp <= 26;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n);
        dp[0] = is_valid(s[0])? 1 : 0;
        if(n == 1)
        {
            return dp[0];
        }
        bool flag1 = is_valid(s[0]) && is_valid(s[1]);
        bool flag2 = is_valid_double(s[0], s[1]);
        if(flag1)
        {
            dp[1]++;
        }
        if(flag2)
        {
            dp[1]++;
        }
        for(int i = 2; i < n; i++)
        {
            bool flag3 = is_valid(s[i])? 1 : 0;
            bool flag4 = is_valid_double(s[i - 1], s[i])? 1 : 0;
            dp[i] = dp[i - 1]*flag3 + dp[i - 2]*flag4;
        }
        return dp[n-1];
    }
};

// optimize
class Solution1 {
public:
    bool is_valid(char c)
    {
        return '1' <= c && c <= '9';
    }

    bool is_valid_double(char x, char y)
    {
        int tmp = 10*(x - '0') + y - '0';
        return tmp >= 10 && tmp <= 26;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;  // virtual node
        dp[1] = is_valid(s[0]);
        for(int i = 2; i <= n; i++)
        {
            bool flag3 = is_valid(s[i - 1])? 1 : 0;
            bool flag4 = is_valid_double(s[i - 2], s[i - 1])? 1 : 0;
            dp[i] = dp[i - 1]*flag3 + dp[i - 2]*flag4;
        }
        return dp[n];
    }
};