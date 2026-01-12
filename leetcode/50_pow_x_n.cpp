// leetcode 50    mid

class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        bool flag = false;
        if(nn < 0)
        {
            flag = true;
            nn = -nn;
        }
        if(flag)
        {
            return 1 / dfs(x, nn);
        }
        return dfs(x, nn);
    }

    double dfs(double x, long long n)
    {
        if(n == 0)
        {
            return 1;
        }
        double tmp = dfs(x, n/2);
        if(n % 2)
        {
            return tmp * tmp * x;
        }
        else{
            return tmp * tmp;
        }
    }
    
};