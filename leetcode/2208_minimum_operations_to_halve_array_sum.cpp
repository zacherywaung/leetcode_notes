//leetcode2208

#include<queue>
using namespace std;
class Solution {
public:
    int halveArray(vector<int>& nums) {
        int cnt = 0;
        double sum = 0.0;
        priority_queue<double> pq;
        for(auto e : nums)
        {
            pq.push(e);
            sum += e;
        }
        double target = sum / 2.0;
        while(sum > target)
        {
            double max = pq.top();
            pq.pop();
            double half = max / 2.0;
            sum -= half;
            pq.push(half);
            cnt++;
        }
        return cnt;
    }
};