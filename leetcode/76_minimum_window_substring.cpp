// leetcode76

#include <string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int hash1[128] = {0};
        int hash2[128] = {0};
        int type = 0;
        for(auto& e : t)
        {
            if(hash1[e]++ == 0) type++;
        }
        int min = INT_MAX;
        int cnt = 0;
        int left = 0;
        int ret_left = -1;
        int ret_right = -1;
        for(int right = 0; right < s.size(); right++)
        {
            // push window
            hash2[s[right]]++;
            if(hash2[s[right]] == hash1[s[right]]) cnt++;
            while(cnt == type)
            {
                if(right - left + 1 < min)
                {
                    ret_left = left;
                    ret_right = right;
                    min = right - left + 1;
                }
                // pop window
                if(hash2[s[left]] == hash1[s[left]])
                    cnt--;
                hash2[s[left]]--;
                left++;
            }
        }
        if(ret_left == -1) return "";
        return s.substr(ret_left, ret_right - ret_left + 1);
    }
};