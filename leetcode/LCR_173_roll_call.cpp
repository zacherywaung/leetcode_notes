// LCR 173

#include <vector>
using namespace std;
class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int left = 0;
        int right = records.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(records[mid] != mid) right = mid;
            else left = mid + 1;
        }
        if(left == records[left]) return left + 1;
        return left;
    }
};