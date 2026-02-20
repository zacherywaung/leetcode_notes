// leetcode11

#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int curVolume = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left < right)
        {
            curVolume = min(height[left], height[right]) * (right - left);
            if(curVolume > max) max = curVolume;
            if(height[left] < height[right]) left++;
            else right--;
        }
        return max;
    }
};