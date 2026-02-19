#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cur = 0;
        int dst = -1;
        int n = arr.size();
        while(dst < n - 1)
        {
            if(arr[cur] == 0)
            {
                dst += 2;
            }
            else{
                dst++;
            }
            cur++;
        }
        cur--;
        if(dst == n)
        {
            arr[dst - 1] = 0;
            cur--;
            dst -= 2;
        }
        while(cur >= 0)
        {
            if(arr[cur] == 0)
            {
                arr[dst] = arr[dst - 1]= 0;
                dst -= 2;
            }
            else{
                arr[dst] = arr[cur];
                dst--;
            }
            cur--;
        }
    }
};