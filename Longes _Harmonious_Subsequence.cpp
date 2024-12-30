#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        int maxLength = 0;

        for (int num : nums) {
            count[num]++;
        }

        for (auto& [key, value] : count) {
            if (count.find(key + 1) != count.end()) {
                maxLength = max(maxLength, value + count[key + 1]);
            }
        }

        return maxLength;
    }
};
