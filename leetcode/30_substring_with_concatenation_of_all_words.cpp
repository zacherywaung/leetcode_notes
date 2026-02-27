// leetcode30 hard


#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        int step = words[0].size();
        unordered_map<string, int> hash1;
        int size = 0;
        for(auto& e : words)
        {
            hash1[e]++;
            size++;
        }
        int wide = size * step;
        for(int i = 0; i < step; i++) // enum start place
        {
            int left = i;
            unordered_map<string, int> hash2;
            int cnt = 0;
            for(int right = i; right < s.size(); right += step)
            {
                // enter window
                string in = s.substr(right, step);
                hash2[in]++;
                if(hash2[in] <= hash1[in]) cnt++;
                if((right - left + 1) > wide)
                {
                    // leave window
                    string out = s.substr(left, step);
                    if(hash2[out] <= hash1[out]) cnt--;
                    hash2[out]--;
                    left += step;
                }
                if(cnt == size)
                {
                    ret.emplace_back(left);
                }
            }
        }
        return ret;
    }
};