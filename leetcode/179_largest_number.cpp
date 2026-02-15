//leetcode179

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    template<class T>
    class compare
    {
    public:
        bool operator()(T a, T b)
        {
            if(a + b > b + a) // can't use equal
            {
                return true;
            }
            return false;
        }
    };

    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for(auto e : nums)
        {
            s.emplace_back(to_string(e));
        }
        sort(s.begin(), s.end(), [](const string& a, const string& b)->bool{
            return a + b > b + a;
        });
        //sort(s.begin(), s.end(), compare<string>());
        string ret;
        for(auto& e : s)
        {
            ret += e;
        }
        if(ret[0] == '0')
        {
            return "0";
        }
        return ret;
    }
};