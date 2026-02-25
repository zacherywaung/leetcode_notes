// leetcode904

#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ret = 0;
        unordered_map<int, int> basket;
        for(int left = 0, right = 0; right < fruits.size(); right++)
        {
            basket[fruits[right]]++;
            while(basket.size() > 2)
            {
                basket[fruits[left]]--;
                if(basket[fruits[left]] == 0) basket.erase(fruits[left]);
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};