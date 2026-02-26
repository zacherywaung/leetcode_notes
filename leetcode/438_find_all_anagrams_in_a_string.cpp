// leetcode438

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int hash1[26] = {0};
        int hash2[26] = {0};
        int valid = p.size();
        for(auto& e : p)
        {
            hash1[e - 'a']++;
        }
        int left = 0;
        int cnt = 0;  // valid element count
        for(int right = 0; right < s.size(); right++)
        {
            hash2[s[right] - 'a']++;
            if(hash2[s[right] - 'a'] <= hash1[s[right] - 'a']) cnt++;
            if(right - left + 1 > p.size())
            {
                if(hash2[s[left] - 'a'] <= hash1[s[left] - 'a']) cnt--;
                hash2[s[left] - 'a']--;
                left++;
            }
            if(cnt == valid)
            {
                ret.push_back(left);
            }
        }
        return ret;
    }
};